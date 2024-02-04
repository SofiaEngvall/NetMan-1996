#include "fm.h"

#define C    65.41
#define Cu   69.30
#define D    73.42
#define Du   77.78
#define E    82.41
#define F    87.31
#define Fu   92.50
#define G    98.00
#define Gu  103.83
#define A   110.00
#define Au  116.54
#define H   123.47

extern void RedrawDots();
void SoundOff();
unsigned long HundAfter00();

extern unsigned IOport;
extern char debug;
extern char soundDevice;

unsigned long time2changeMusic;
int music[1000][2];
int musicCount=0;
int soundCount=0;
char soundType=0;

void SoundInit()
{
  unsigned dummy;
  ReadBlasterEnv(&IOport, &dummy, &dummy, &dummy);

  if(IOport>0)
  {
    fm(1,0);        // M†ste initialiseras till noll
    Profm2(5, 1);               // OPL3 mode, n”dv„ndigt f”r stereo
    fm(0xC0,0x10 | 0x20 | 1);   // B†da kanalerna, parallel connection
    fm(0x23,0x21);       // ingen amplitude modulering (D7=0)
                         // inget vibrato (D6=0)
 		         // sustained envelope type (D5=1), KSR=0 (D4=0)
		         // frequency multiplier=1 (D4-D0=1)
    fm(0x43,0x0);        // no volume decrease with pitch (D7-D6=0)
      		         // no attenuation (D5-D0=0)
    fm(0x63,0xff);       // fast attack (D7-D4=0xF)
                         // and decay (D3-D0=0xF)
    fm(0x83,0x05);       // high sustain level (D7-D4=0)
                         // slow release rate (D3-D0=5)

    // *** Set parameters for the modulator cell ***
    fm(0x20,0x20);  // sustained envelope type, frequency multiplier=0
    fm(0x40,0x3f);  // maximum attenuation, no volume decrease with pitch
    fm(0x60,0x44);  // slow attack and decay
    fm(0x80,0x05);  // high sustain level, slow release rate
  }
}

void SoundOut(int freq)
  {
  if(freq==0)
    {
    SoundOff();
    return;
    }
  if(soundDevice==2) //IOport>0)           //If at least SBpro ver2
    {
    // Calculates freqnr from freq
    // freqnr = freq * 1048576 / (1 << block) / (frequency multiple number) / 50000L;
    long freqnr = (long)freq * 1048576L / (1 << 4) / 50000L;
    fm(0xA0,((int)freqnr & 0xFF));
    fm(0xB0,(((int)freqnr >> 8) & 0x3) + (4 << 2) | KEYON);
    }
  else if(soundDevice==1) //Pc-Speaker
    sound(freq);
  }

void SoundOff()
  {
  if(soundDevice==2)           //If at least SBpro ver2
    {
    fm(0xA0,(0 & 0xFF));
    fm(0xB0,((0 >> 8) & 0x3) + (4 << 2) | KEYON);
    }
  else if(soundDevice==1)      //Pc-Speaker
    nosound();
  }

void Ljud()
  {
  switch(soundType)
    {
    case  1: if(soundCount<290)
	       soundCount+=10;
	     else
	       {
	       soundType=0;
	       SoundOff();
	       }
	     break;
    case  2: if(soundCount<700)
	       soundCount+=50;
	     else
	       {
	       soundType=0;
	       SoundOff();
	       }
	     break;
    case 50: for(soundCount=50;soundCount<400;soundCount+=5)
	       { SoundOut(soundCount); delay(1); }
	     for(soundCount=400;soundCount>50;soundCount-=5)
	       { SoundOut(soundCount); delay(1); }
	     for(soundCount=50;soundCount<400;soundCount+=5)
	       { SoundOut(soundCount); delay(1); }
	     for(soundCount=400;soundCount>50;soundCount-=5)
	       { SoundOut(soundCount); delay(1); }
	     for(soundCount=50;soundCount<400;soundCount+=5)
	       { SoundOut(soundCount); delay(1); }
	     soundType=0;
	     SoundOff();
	     RedrawDots();
	     break;
    }
  if(soundType) SoundOut(soundCount);
  }

void Musik()
  {
  unsigned long timeNow=HundAfter00();

  if(debug)
    {
    gotoxy(1,1);
    printf("if %ld (now) > %ld (time to change music sound)    musicCount=%d      ", timeNow, time2changeMusic, musicCount);
    }

  if(timeNow>time2changeMusic)
    {
    SoundOut(music[musicCount][0]);
    time2changeMusic=timeNow+(long)music[musicCount][1];
    musicCount++;
    if((music[musicCount][0]==0) && (music[musicCount][1]==0))
      musicCount=0;
    }
  }

unsigned long HundAfter00() // Returnerar antal 1/100 sek efter midnatt
  {
  char hour, min, sec, hund;

  asm mov ah,2Ch;
  asm int 21h;
  asm mov [hour],ch;
  asm mov [min],cl;
  asm mov [sec],dh;
  asm mov [hund],dl;

  return ((long)hour*360000L+(long)min*6000L+(long)sec*100L+(long)hund);
  }

void Song0()
  {
//  Freq (Hz)        Duration (1/100 sec)
  music[0][0]=4*F;   music[0][1]=25;
  music[1][0]=0;     music[1][1]=5;
  music[2][0]=4*D;   music[2][1]=25;
  music[3][0]=0;     music[3][1]=5;
  music[4][0]=4*C;   music[4][1]=50;
  music[5][0]=0;     music[5][1]=5;
  music[6][0]=4*C;   music[6][1]=50;
  music[7][0]=0;     music[7][1]=5;
  music[8][0]=4*C;   music[8][1]=50;
  music[9][0]=0;     music[9][1]=5;
  music[10][0]=4*C;  music[10][1]=50;
  music[11][0]=0;    music[11][1]=5;
  music[12][0]=4*F;  music[12][1]=50;
  music[13][0]=0;    music[13][1]=5;
  music[14][0]=4*F;  music[14][1]=50;
  music[15][0]=0;    music[15][1]=100;
  music[16][0]=0;    music[16][1]=0;
  }

void Song1() // Tom Dooley
  {
  int paus=3;
  int attondel=20;
  int kvart=attondel*2;
  int halv=kvart*2;
  int hel=halv*2;

//  Freq (Hz)        Duration (1/100 sec)
  music[0][0]=4*D;   music[0][1]=attondel;
  music[1][0]=0;     music[1][1]=paus;
  music[2][0]=4*D;   music[2][1]=kvart;
  music[3][0]=0;     music[3][1]=paus;
  music[4][0]=4*D;   music[4][1]=attondel;
  music[5][0]=0;     music[5][1]=paus;
  music[6][0]=4*E;   music[6][1]=kvart;
  music[7][0]=0;     music[7][1]=paus;
  music[8][0]=4*G;   music[8][1]=kvart;
  music[9][0]=0;     music[9][1]=paus;
  music[10][0]=4*H;  music[10][1]=kvart;
  music[11][0]=0;    music[11][1]=paus;
  music[12][0]=4*H;  music[12][1]=kvart*3; // halv  * 1,5
  music[13][0]=0;    music[13][1]=paus;

  music[14][0]=4*D;  music[14][1]=attondel;
  music[15][0]=0;    music[15][1]=paus;
  music[16][0]=4*D;  music[16][1]=kvart;
  music[17][0]=0;    music[17][1]=paus;
  music[18][0]=4*D;  music[18][1]=attondel;
  music[19][0]=0;    music[19][1]=paus;
  music[20][0]=4*E;  music[20][1]=kvart;
  music[21][0]=0;    music[21][1]=paus;
  music[22][0]=4*G;  music[22][1]=kvart;
  music[23][0]=0;    music[23][1]=paus;
  music[24][0]=4*A;  music[24][1]=hel;
  music[25][0]=0;    music[25][1]=paus;

  music[26][0]=4*D;  music[26][1]=attondel;
  music[27][0]=0;    music[27][1]=paus;
  music[28][0]=4*D;  music[28][1]=kvart;
  music[29][0]=0;    music[29][1]=paus;
  music[30][0]=4*D;  music[30][1]=attondel;
  music[31][0]=0;    music[31][1]=paus;
  music[32][0]=4*E;  music[32][1]=kvart;
  music[33][0]=0;    music[33][1]=paus;
  music[34][0]=4*G;  music[34][1]=kvart;
  music[35][0]=0;    music[35][1]=paus;
  music[36][0]=4*A;  music[36][1]=kvart;
  music[37][0]=0;    music[37][1]=paus;
  music[38][0]=4*A;  music[38][1]=kvart*3; // halv  * 1,5
  music[39][0]=0;    music[39][1]=paus;

  music[40][0]=4*A;  music[40][1]=attondel;
  music[41][0]=0;    music[41][1]=paus;
  music[42][0]=4*A;  music[42][1]=kvart;
  music[43][0]=0;    music[43][1]=paus;
  music[44][0]=4*H;  music[44][1]=attondel;
  music[45][0]=0;    music[45][1]=paus;
  music[46][0]=4*A;  music[46][1]=kvart;
  music[47][0]=0;    music[47][1]=paus;
  music[48][0]=4*E;  music[48][1]=kvart;
  music[49][0]=0;    music[49][1]=paus;
  music[50][0]=4*G;  music[50][1]=hel;
  music[51][0]=0;    music[51][1]=hel;

  music[52][0]=0;    music[52][1]=0;
  }

void Song2() // O Susanna ???
  {
  int paus=3;
  int attondel=15;
  int kvart=attondel*2;
//  int halv=kvart*2;
//  int hel=halv*2;

//  Freq (Hz)        Duration (1/100 sec)
  music[0][0]=4*C;   music[0][1]=kvart;
  music[1][0]=0;     music[1][1]=paus;
  music[2][0]=4*D;   music[2][1]=kvart;
  music[3][0]=0;     music[3][1]=paus;
  music[4][0]=4*E;   music[4][1]=kvart;
  music[5][0]=0;     music[5][1]=paus;
  music[6][0]=4*G;   music[6][1]=kvart;
  music[7][0]=0;     music[7][1]=paus;
  music[8][0]=4*G;   music[8][1]=kvart;
  music[9][0]=0;     music[9][1]=paus;
  music[10][0]=4*A;  music[10][1]=kvart;
  music[11][0]=0;    music[11][1]=paus;
  music[12][0]=4*G;  music[12][1]=kvart;
  music[13][0]=0;    music[13][1]=paus;
  music[14][0]=4*E;  music[14][1]=kvart;
  music[15][0]=0;    music[15][1]=paus;
  music[16][0]=4*C;  music[16][1]=kvart;
  music[17][0]=0;    music[17][1]=paus;
  music[18][0]=4*D;  music[18][1]=kvart;
  music[19][0]=0;    music[19][1]=paus;
  music[20][0]=4*E;  music[20][1]=kvart;
  music[21][0]=0;    music[21][1]=paus;
  music[22][0]=4*E;  music[22][1]=kvart;
  music[23][0]=0;    music[23][1]=paus;
  music[24][0]=4*D;  music[24][1]=kvart;
  music[25][0]=0;    music[25][1]=paus;
  music[26][0]=4*C;  music[26][1]=kvart;
  music[27][0]=0;    music[27][1]=paus;
  music[28][0]=4*D;  music[28][1]=kvart;
  music[29][0]=0;    music[29][1]=paus*6;

  music[30][0]=4*C;  music[30][1]=kvart;
  music[31][0]=0;    music[31][1]=paus;
  music[32][0]=4*D;  music[32][1]=kvart;
  music[33][0]=0;    music[33][1]=paus;
  music[34][0]=4*E;  music[34][1]=kvart;
  music[35][0]=0;    music[35][1]=paus;
  music[36][0]=4*G;  music[36][1]=kvart;
  music[37][0]=0;    music[37][1]=paus;
  music[38][0]=4*G;  music[38][1]=kvart;
  music[39][0]=0;    music[39][1]=paus;
  music[40][0]=4*A;  music[40][1]=kvart;
  music[41][0]=0;    music[41][1]=paus;
  music[42][0]=4*G;  music[42][1]=kvart;
  music[43][0]=0;    music[43][1]=paus;
  music[44][0]=4*E;  music[44][1]=kvart;
  music[45][0]=0;    music[45][1]=paus;
  music[46][0]=4*C;  music[46][1]=kvart;
  music[47][0]=0;    music[47][1]=paus;
  music[48][0]=4*D;  music[48][1]=kvart;
  music[49][0]=0;    music[49][1]=paus;
  music[50][0]=4*E;  music[50][1]=kvart;
  music[51][0]=0;    music[51][1]=paus;
  music[52][0]=4*E;  music[52][1]=kvart;
  music[53][0]=0;    music[53][1]=paus;
  music[54][0]=4*D;  music[54][1]=kvart;
  music[55][0]=0;    music[55][1]=paus;
  music[56][0]=4*D;  music[56][1]=kvart;
  music[57][0]=0;    music[57][1]=paus;
  music[58][0]=4*C;  music[58][1]=kvart;
  music[59][0]=0;    music[59][1]=paus*6;

  music[60][0]=4*G;  music[60][1]=kvart;
  music[61][0]=0;    music[61][1]=paus;
  music[62][0]=4*G;  music[62][1]=kvart;
  music[63][0]=0;    music[63][1]=paus;
  music[64][0]=4*G;  music[64][1]=kvart;
  music[65][0]=0;    music[65][1]=paus;
  music[66][0]=4*G;  music[66][1]=kvart;
  music[67][0]=0;    music[67][1]=paus;
  music[68][0]=4*A;  music[68][1]=kvart;
  music[69][0]=0;    music[69][1]=paus;
  music[70][0]=4*A;  music[70][1]=kvart;
  music[71][0]=0;    music[71][1]=paus*5;
  music[72][0]=4*A;  music[72][1]=kvart;
  music[73][0]=0;    music[73][1]=paus;
  music[74][0]=4*G;  music[74][1]=kvart;
  music[75][0]=0;    music[75][1]=paus;
  music[76][0]=4*G;  music[76][1]=kvart;
  music[77][0]=0;    music[77][1]=paus;
  music[78][0]=4*E;  music[78][1]=kvart;
  music[79][0]=0;    music[79][1]=paus;
  music[80][0]=4*C;  music[80][1]=kvart;
  music[81][0]=0;    music[81][1]=paus;
  music[82][0]=4*D;  music[82][1]=kvart;
  music[83][0]=0;    music[83][1]=paus*6;

  music[84][0]=0;    music[84][1]=0;
  }
