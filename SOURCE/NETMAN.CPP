//                   * * * NETMAN * * *

// Copyright (C) 1996, Bjîrn Jegelius, Sofia Engvall & Gîran Asklund


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<time.h>

#include"graph.h"
#include"sound.h"
#include"levels.h"

int levelAnt=6;

#define LEVELFIL "level000.dat"
#define MAX_X 32
#define MAX_Y 22
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ESC 27
#define TRUE 1
#define FALSE 0

char ghostDir[4], ghostNr, life, direction, prefDir, mouth, joystickEnabled;
char soundDevice, musicEnabled=FALSE, dotSoundEnabled=TRUE;
char runningGame=FALSE;
int joyCenterX, joyCenterY;
int prickAnt, anger[4]={0,0,0,0}, pacX, pacY, ghostX[4], ghostY[4];
int oldGhostX[4], oldGhostY[4], ghostScore, level;
long delayTimeCalc, delayTime;
unsigned long score=0;
char debug=FALSE;

FILE *fp;

void Spel();
void MovePac();
char MoveGhosts();
void SetGhostDir();
void RedrawDots();
void ReadLev();
void StartValues();
void Lev2Scr();
void NextLevel();
char OkDir(int x, int y, char rikt);
char Byte2Bit(char byte1, char bitNr);
void InitJoy();
void ReadJoystick();
long CheckComputerSpeed();
void Meny();
void MenuText(char menyNr, char val);
void MainMenuText(char val);
void SoundMenuText(char val);
void Wait(long tal);


void main()
{
  randomize();
  InitGraph();   // VÑxla till grafiklÑge
  cleardevice();

  SoundInit();
  if(IOport>0)
  {
    printf("Sound Blaster detected.\n\n");
    soundDevice=2;
  }
  else
  {
    printf("No Sound Blaster detected.\n\n");
    soundDevice=1;
  }

  long computerSpeed=CheckComputerSpeed();  // Kollar datorns hastighet
  delayTimeCalc=(computerSpeed-125)*300;

  InitJoy();      // Initiera joystick
  // VÑntar tills ingen joystickknapp Ñr nedtryckt.
  while(joystickEnabled&&((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1)));

  if(debug)
  {
    printf("\n\n\ncomputerSpeed...: %ld\n", computerSpeed);
    printf("delayTimeCalc...: %ld\n", delayTimeCalc);
    printf("joyCenterX......: %d\n", joyCenterX);
    printf("joyCenterY......: %d", joyCenterY);
    // VÑntar pÜ joystickknapp eller tangenttryckning. Tîmmer ej buffert.
    while(!kbhit()&&(!joystickEnabled||((Byte2Bit(255-inportb(0x0201),4)==0)&&(Byte2Bit(255-inportb(0x0201),5)==0))));
    while(kbhit()) getch();  // Tîmmer buffert
    // VÑntar tills ingen joystickknapp Ñr nedtryckt.
    while(joystickEnabled&&((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1)));
  }

  DrawBlock();    // LÑgger in alla bilder i minnet

  while(1)
  {
    Meny();
    while(!runningGame)
      Spel();
    runningGame=FALSE;
  }
}

void Spel()
{
  char keyIn, val;
  cleardevice();
  setpalette(7,255); // Gîr sÜ att 7 blir synlig igen efter menyns scrolltext
//  ReadLev();  //LÑser in levlarna frÜn fil
  delayTime=delayTimeCalc;
  if(delayTime<0)
    delayTime=0;
  level=1;
  musicCount=0;
  Song1();
  LoadLevel(level);
  StartValues();
  Lev2Scr();
  MovePac();
// VÑntar tills ingen joystickknapp Ñr nedtryckt.
  while(joystickEnabled&&((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1)));
// VÑntar pÜ joystickknapp eller tangenttryckning. Tîmmer ej buffert.
  while(!kbhit()&&(!joystickEnabled||((Byte2Bit(255-inportb(0x0201),4)==0)&&(Byte2Bit(255-inportb(0x0201),5)==0))));
// VÑntar tills ingen joystickknapp Ñr nedtryckt.
  while(joystickEnabled&&((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1)));

  while(1)
  {
    if(joystickEnabled)
      ReadJoystick();

    while(kbhit())  // *** Egen funktion *** Kolla efter paus, avbryt etc! ***
    {
      keyIn=getch();
      if(keyIn==ESC)
      {
	Meny();
	if(!runningGame)
	  return;
	cleardevice();
	setpalette(7,255);
	Lev2Scr();
      }
      if(keyIn=='-')
        delayTime+=1000;
      if(keyIn=='+')
      {
        delayTime-=1000;
        if(delayTime<0)
          delayTime=0;
      }
      if(debug)
      {
	if(keyIn=='0')
	  prickAnt=0;
	if(keyIn=='r')
	  RedrawDots();
	if(keyIn=='l')
	{
	  life++;
	  gotoxy(60,2); printf("Life     : %d ", life);
	}
	if(keyIn=='L')
	{
	  life--;
	  gotoxy(60,2); printf("Life     : %d ", life);
	}
	if(keyIn=='d')
	{
	  delayTime+=5000;
	  gotoxy(60,8); printf("Delay    : %ld ", delayTime);
	}
	if(keyIn=='D')
	{
	  delayTime-=5000;
	  gotoxy(60,8); printf("Delay    : %ld ", delayTime);
	}
	if(keyIn=='a')
	{
	  anger[0]=30000; anger[1]=30000;
	  anger[2]=30000; anger[3]=30000;
	}
	if(keyIn=='A')
	{
	  anger[0]=0; anger[1]=0;
	  anger[2]=0; anger[3]=0;
	}
      }
      if(keyIn==0)
      {
	keyIn=getch();
	if((keyIn==UP)||(keyIn==LEFT)||(keyIn==RIGHT)||(keyIn==DOWN))
	  prefDir=keyIn; // Prefered direction
	//if(keyIn==F1) Help();
      }
    }

    MovePac();

    Ljud();
    if(musicEnabled) Musik();

    if(prickAnt<=0) // Klarat banan
    {
      score+=2000;
      gotoxy(60,4); printf("Score    : %ld", score);
      NextLevel();
    }

    if(MoveGhosts()) // MoveGhosts() returnerar TRUE nÑr man fîrlorat alla liv
      return;

//  MoveNet();

  Wait(delayTime);

  }
}

void MovePac()
{
  static char mouthdir, drawDotX=0, drawDotY=0;

  switch(direction) // Byter riktning om Ñndringen Ñr 180¯
  {
    case UP    : if(prefDir==DOWN)
                 {
                   direction=prefDir;
                   drawDotX=pacX/20;
                   drawDotY=pacY/20;
                 }
                 break;
    case LEFT  : if(prefDir==RIGHT)
                 {
                   direction=prefDir;
                   drawDotX=pacX/20;
                   drawDotY=pacY/20;
                 }
                 break;
    case RIGHT : if(prefDir==LEFT)
                 {
                   direction=prefDir;
                   drawDotX=pacX/20+1;
                   drawDotY=pacY/20;
                 }
                 break;
    case DOWN  : if(prefDir==UP)
                 {
                   direction=prefDir;
                   drawDotX=pacX/20;
                   drawDotY=pacY/20+1;
                 }
  }

  if((pacX%20==0)&&(pacY%20==0))
  {
    drawDotX=0;
    drawDotY=0;
    if(OkDir(pacX/20,pacY/20,prefDir))
      direction=prefDir;
    if(BlockPrick[pacY/20][pacX/20])
    {
      switch(BlockPrick[pacY/20][pacX/20])
      {
	case 1  : prickAnt--; score+=10;
		  if(!soundType&&dotSoundEnabled)
		  {
		    soundType=1;
		    soundCount=200;
		    time2changeMusic=HundAfter00()+50L;
		  }
		  break;
	case 2  : prickAnt--; ghostScore=100; score+=50;
		  anger[0]=1500; anger[1]=1500;
		  anger[2]=1500; anger[3]=1500;
		  soundType=2;
		  soundCount=200;
		  time2changeMusic=HundAfter00()+50L;
		  break;
//	case 3  : score+=100; break; // Fîr typ kîrsbÑr mm
      }
      BlockPrick[pacY/20][pacX/20]=0;
      gotoxy(60,4); printf("Score    : %ld", score);
      gotoxy(60,6); printf("Dots left: %d  ", prickAnt);
    }
  }

    // Ta bort gubben genom att rita ett svart block.
    bar(pacX+pacX/20, pacY+pacY/20, pacX+pacX/20+20, pacY+pacY/20+20);

    if(drawDotX&&drawDotY) // Ritar ut prick efter att gubben har vÑnt 180¯
      putimage(drawDotX*20+drawDotX, drawDotY*20+drawDotY, Prick[BlockPrick[drawDotY][drawDotX]], COPY_PUT);

  switch(direction)
  {
    case UP    : if(pacY%20==0)
		   if(OkDir(pacX/20,pacY/20,UP))
		     pacY-=2;
		   else;
		 else
		   pacY-=2;
		 break;
    case LEFT  : if(pacX%20==0)
		   if(OkDir(pacX/20,pacY/20,LEFT))
		     pacX-=2;
		   else;
		 else
		   pacX-=2;
		 break;
    case RIGHT : if(pacX%20==0)
		   if(OkDir(pacX/20,pacY/20,RIGHT))
		     pacX+=2;
		   else;
		 else
		   pacX+=2;
		 break;
    case DOWN  : if(pacY%20==0)
		   if(OkDir(pacX/20,pacY/20,DOWN))
		     pacY+=2;
		   else;
		 else
		   pacY+=2;
  }

  if((pacX==0)&&(pacY==200))
  {
    pacX=400;
    if(BlockPrick[10][0]==1)
    {
      prickAnt--;
      score+=10;
      BlockPrick[10][0]=0;
    }
  }
  else if((pacX==400)&&(pacY==200))
  {
    pacX=0;
    if(BlockPrick[10][20]==1)
    {
      prickAnt--;
      score+=10;
      BlockPrick[10][20]=0;
    }
  }

  if(mouth>=19) mouthdir=-1;
  if(mouth<=0)  mouthdir=1;
  mouth+=mouthdir;

  switch(direction)
  {
    case UP    : putimage(pacX+pacX/20, pacY+pacY/20, Pac[0][mouth/4], COPY_PUT); break;
    case LEFT  : putimage(pacX+pacX/20, pacY+pacY/20, Pac[1][mouth/4], COPY_PUT); break;
    case RIGHT : putimage(pacX+pacX/20, pacY+pacY/20, Pac[2][mouth/4], COPY_PUT); break;
    case DOWN  : putimage(pacX+pacX/20, pacY+pacY/20, Pac[3][mouth/4], COPY_PUT); break;
    default    : putimage(pacX+pacX/20, pacY+pacY/20, Pac[2][0], COPY_PUT);
  }
}

char MoveGhosts()
{
  for(ghostNr=0;ghostNr<4;ghostNr++)
  {
    SetGhostDir();

    if(BlockPrick[oldGhostY[ghostNr]/20][oldGhostX[ghostNr]/20]>0)
      putimage(oldGhostX[ghostNr]+oldGhostX[ghostNr]/20, oldGhostY[ghostNr]+oldGhostY[ghostNr]/20, Prick[BlockPrick[oldGhostY[ghostNr]/20][oldGhostX[ghostNr]/20]], COPY_PUT);
    else
      bar(ghostX[ghostNr]+ghostX[ghostNr]/20, ghostY[ghostNr]+ghostY[ghostNr]/20, ghostX[ghostNr]+ghostX[ghostNr]/20+20, ghostY[ghostNr]+ghostY[ghostNr]/20+20);

    if(anger[ghostNr]<=0)
      switch(ghostDir[ghostNr])
      {
	case UP    : ghostY[ghostNr]-=2;
		     if(ghostY[ghostNr]%2) ghostY[ghostNr]++;
		     break;
	case LEFT  : ghostX[ghostNr]-=2;
		     if(ghostX[ghostNr]%2) ghostX[ghostNr]++;
		     break;
	case RIGHT : ghostX[ghostNr]+=2;
		     if(ghostX[ghostNr]%2) ghostX[ghostNr]--;
		     break;
	case DOWN  : ghostY[ghostNr]+=2;
		     if(ghostY[ghostNr]%2) ghostY[ghostNr]--;
      }
    else
      switch(ghostDir[ghostNr])
      {
	case UP    : ghostY[ghostNr]--; break;
	case LEFT  : ghostX[ghostNr]--; break;
	case RIGHT : ghostX[ghostNr]++; break;
	case DOWN  : ghostY[ghostNr]++;
      }

    if( (anger[ghostNr]<=0) || ( (anger[ghostNr]%50<=25) && (anger[ghostNr]<=500) ))
      putimage(ghostX[ghostNr]+ghostX[ghostNr]/20, ghostY[ghostNr]+ghostY[ghostNr]/20, Ghost[ghostNr], COPY_PUT);
    else
      putimage(ghostX[ghostNr]+ghostX[ghostNr]/20, ghostY[ghostNr]+ghostY[ghostNr]/20, AfraidGhost, COPY_PUT);


// Kolla om avstÜndet mellan spîke och gubbe Ñr fîr litet
    if( ( ( ((pacX-ghostX[ghostNr])<15) && ((pacX-ghostX[ghostNr])>=0) ) ||
	( ((ghostX[ghostNr]-pacX)<15) && ((ghostX[ghostNr]-pacX)>=0) ) ) &&
	( ( ((pacY-ghostY[ghostNr])<15) && ((pacY-ghostY[ghostNr])>=0) ) ||
	( ((ghostY[ghostNr]-pacY)<15) && ((ghostY[ghostNr]-pacY)>=0) ) ) )
      if(anger[ghostNr]>0)
      {
//	bar(ghostX[ghostNr]+ghostX[ghostNr]/20, ghostY[ghostNr]+ghostY[ghostNr]/20, ghostX[ghostNr]+ghostX[ghostNr]/20+20, ghostY[ghostNr]+ghostY[ghostNr]/20+20);
	putimage(ghostX[ghostNr]+ghostX[ghostNr]/20, ghostY[ghostNr]+ghostY[ghostNr]/20, Block[0], COPY_PUT);

	ghostX[ghostNr]=ghostStartX;
	ghostY[ghostNr]=ghostStartY;
	score+=ghostScore;
	ghostScore*=2;
	gotoxy(60,4); printf("Score    : %ld", score);
	anger[ghostNr]=0;
	soundType=50;
      }
      else
      {
	if(life>0)
	{
	  life--;
	  gotoxy(60,2); printf("Life     : %d ", life);
	  SoundOut(150);
	  delay(1000);
          SoundOff();
          musicCount=0;
	  putimage(pacX+pacX/20, pacY+pacY/20, Block[0], COPY_PUT);
	  RedrawDots();
	  pacX=pacStartX;
	  pacY=pacStartY;
	  putimage(pacX+pacX/20, pacY+pacY/20, Pac[2][0], COPY_PUT);
	  direction=0;
	  prefDir=0;
	  mouth=0;
	  ghostX[0]=ghostStartX; ghostY[0]=ghostStartY;
	  ghostX[1]=ghostStartX; ghostY[1]=ghostStartY;
	  ghostX[2]=ghostStartX; ghostY[2]=ghostStartY;
	  ghostX[3]=ghostStartX; ghostY[3]=ghostStartY;
	  anger[0]=0; anger[1]=0;
	  anger[2]=0; anger[3]=0;
// VÑntar pÜ joystickknapp eller tangenttryckning. Tîmmer ej buffert.
	  while(!kbhit()&&(!joystickEnabled||((Byte2Bit(255-inportb(0x0201),4)==0)&&(Byte2Bit(255-inportb(0x0201),5)==0))));
// VÑntar tills ingen joystickknapp Ñr nedtryckt.
	  while(joystickEnabled&&((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1)));
	}
	else
	{
	  gotoxy(60,2); printf("G A M E   O V E R");
	  SoundOut(150);
          delay(1000);
          SoundOff();
// VÑntar pÜ joystickknapp eller tangenttryckning. Tîmmer ej buffert.
	  while(!kbhit()&&(!joystickEnabled||((Byte2Bit(255-inportb(0x0201),4)==0)&&(Byte2Bit(255-inportb(0x0201),5)==0))));
	  while(kbhit()) getch();  // Tîmmer buffert
// VÑntar tills ingen joystickknapp Ñr nedtryckt.
	  while(joystickEnabled&&((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1)));
	  return TRUE;
	}
      }

    if(anger[ghostNr]>0) anger[ghostNr]--;
  }
  return FALSE;
}

void SetGhostDir()
{
  if((ghostX[ghostNr]%20==0)&&(ghostY[ghostNr]%20==0))
  {
    oldGhostX[ghostNr]=ghostX[ghostNr];
    oldGhostY[ghostNr]=ghostY[ghostNr];
    if((ghostDir[ghostNr]==UP)||(ghostDir[ghostNr]==DOWN))
      if((OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,LEFT))||OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,RIGHT))
	if(!OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,ghostDir[ghostNr])||(random(2)==0))
	  switch(random(20))
	  {
	    case 0 : if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,LEFT))
		       ghostDir[ghostNr]=LEFT;
		     else
		       ghostDir[ghostNr]=RIGHT;
		     break;
	    case 1 : if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,RIGHT))
		       ghostDir[ghostNr]=RIGHT;
		     else
		       ghostDir[ghostNr]=LEFT;
		     break;
	    default: if(ghostX[ghostNr]<pacX)
		       if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,RIGHT))
			 ghostDir[ghostNr]=RIGHT;
		       else
			 ghostDir[ghostNr]=LEFT;
		     else
		       if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,LEFT))
			 ghostDir[ghostNr]=LEFT;
		       else
			 ghostDir[ghostNr]=RIGHT;
		     if(anger[ghostNr]>0) // Spîket ska gÜ FRèN gubben istÑllet
		       if(ghostDir[ghostNr]==LEFT)
			 if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,RIGHT))
			   ghostDir[ghostNr]=RIGHT;
			 else;
		       else
			 if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,LEFT))
			   ghostDir[ghostNr]=LEFT;
	  }
	else;
      else
	if(!OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,ghostDir[ghostNr]))
	  if(ghostDir[ghostNr]==UP)
	    ghostDir[ghostNr]=DOWN;
	  else
	    ghostDir[ghostNr]=UP;
	else;
    else // utfîrs om ((ghostDir[ghostNr]==LEFT)||(ghostDir[ghostNr]==RIGHT))
      if((OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,UP))||OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,DOWN))
	if(!OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,ghostDir[ghostNr])||(random(2)==0))
	  switch(random(20))
	  {
	    case 0 : if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,UP))
		       ghostDir[ghostNr]=UP;
		     else
		       ghostDir[ghostNr]=DOWN;
		     break;
	    case 1 : if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,DOWN))
		       ghostDir[ghostNr]=DOWN;
		     else
		       ghostDir[ghostNr]=UP;
		     break;
	    default: if(ghostY[ghostNr]<pacY)
		       if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,DOWN))
			 ghostDir[ghostNr]=DOWN;
		       else
			 ghostDir[ghostNr]=UP;
		     else
		       if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,UP))
			 ghostDir[ghostNr]=UP;
		       else
			 ghostDir[ghostNr]=DOWN;
		     if(anger[ghostNr]>0) // Spîket ska gÜ FRèN gubben istÑllet
		       if(ghostDir[ghostNr]==UP)
			 if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,DOWN))
			   ghostDir[ghostNr]=DOWN;
			 else;
		       else
			 if(OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,UP))
			   ghostDir[ghostNr]=UP;
	  }
	else;
      else
	if(!OkDir(ghostX[ghostNr]/20,ghostY[ghostNr]/20,ghostDir[ghostNr]))
	  if(ghostDir[ghostNr]==LEFT)
	    ghostDir[ghostNr]=RIGHT;
	  else
	    ghostDir[ghostNr]=LEFT;
  }
}

void RedrawDots()
{
  int x,y;
  for(y=0;y<LevY;y++)
    for(x=0;x<LevX;x++)
      if(!BlockPos[y][x])
        if(BlockPrick[y][x])
	  putimage(x*20+x, y*20+y, Prick[BlockPrick[y][x]], COPY_PUT);
        else
          bar(x*20+x, y*20+y, x*20+x+20, y*20+y+20);
}

void ReadLev() // LÑser in baninfo frÜn fil
{
  char i, ix, iy;

  fp=fopen(LEVELFIL,"r");
  LevX=fgetc(fp);
  LevY=fgetc(fp);
  fgetc(fp);
  LevX=8; LevY=8;

  for(ix=0;ix<LevX;ix++)
    for(iy=0;iy<LevY;iy++)
      BlockPos[iy][ix]=fgetc(fp);

/*
  for(i=0;i<=LevY;i++)
    fgets(BlockPos[i],MAX_X,fp);
  for(i=0;i<=LevY;i++)
    fgets(BlockRikt[i],MAX_X,fp);
*/

// LÑs in prickarray

  fclose(fp);
}

void StartValues()
{
  runningGame=TRUE;
  life=3;
  score=0;
  anger[0]=0; anger[1]=0;
  anger[2]=0; anger[3]=0;
  pacX=pacStartX; pacY=pacStartY;
  prefDir=0; direction=0;
  ghostX[0]=ghostStartX; ghostY[0]=ghostStartY;
  ghostX[1]=ghostStartX; ghostY[1]=ghostStartY;
  ghostX[2]=ghostStartX; ghostY[2]=ghostStartY;
  ghostX[3]=ghostStartX; ghostY[3]=ghostStartY;
  ghostDir[0]=UP;
  ghostDir[1]=LEFT;
  ghostDir[2]=RIGHT;
  ghostDir[3]=DOWN;
  soundType=0;
  soundCount=0;
}

void Lev2Scr()
{
  int x,y;
  prickAnt=0;
  for(y=0;y<LevY;y++)
    for(x=0;x<LevX;x++)
      if(BlockPos[y][x]>0)
	putimage(x*20+x, y*20+y, Block[BlockPos[y][x]], COPY_PUT);
      else
      {
	putimage(x*20+x, y*20+y, Prick[BlockPrick[y][x]], COPY_PUT);
	if(BlockPrick[y][x]>0)
	  prickAnt++;
      }
  setfillstyle(SOLID_FILL, BLACK);
  gotoxy(60,2); printf("Life     : %d ",life);
  gotoxy(60,4); printf("Score    : %ld",score);
  gotoxy(60,6); printf("Dots left: %d  ",prickAnt);
  gotoxy(60,25); printf("Press ESC for menu");
}

void NextLevel()
{
  cleardevice();
  SoundOff();
  soundType=0;
  soundCount=0;
  musicCount=0;
  level++;
  if(level>levelAnt)
  {
    score+=10000;
    level=1;
    delayTime/=2;
  }
  LoadLevel(level);
  Lev2Scr();
  pacX=pacStartX;
  pacY=pacStartY;
  putimage(pacX+pacX/20, pacY+pacY/20, Pac[2][0], COPY_PUT);
  direction=0;
  prefDir=0;
  mouth=0;
  ghostX[0]=ghostStartX; ghostY[0]=ghostStartY;
  ghostX[1]=ghostStartX; ghostY[1]=ghostStartY;
  ghostX[2]=ghostStartX; ghostY[2]=ghostStartY;
  ghostX[3]=ghostStartX; ghostY[3]=ghostStartY;
  anger[0]=0; anger[1]=0;
  anger[2]=0; anger[3]=0;
// VÑntar pÜ joystickknapp eller tangenttryckning. Tîmmer ej buffert.
  while(!kbhit()&&(!joystickEnabled||((Byte2Bit(255-inportb(0x0201),4)==0)&&(Byte2Bit(255-inportb(0x0201),5)==0))));
// VÑntar tills ingen joystickknapp Ñr nedtryckt.
  while(joystickEnabled&&((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1)));
}

char OkDir(int x, int y, char rikt)
{
  switch(rikt)
  {
    case UP    : return Byte2Bit(BlockRikt[y][x],0);
    case LEFT  : return Byte2Bit(BlockRikt[y][x],1);
    case RIGHT : return Byte2Bit(BlockRikt[y][x],2);
    case DOWN  : return Byte2Bit(BlockRikt[y][x],3);
  }
}

char Byte2Bit(char byte, char bitNr)
{
  char bits[8]={0,0,0,0,0,0,0,0};
  if(byte>=128) { bits[7]=1; byte-=128; }  // OBS! Inte unsigned
  if(byte>= 64) { bits[6]=1; byte-= 64; }
  if(byte>= 32) { bits[5]=1; byte-= 32; }
  if(byte>= 16) { bits[4]=1; byte-= 16; }
  if(byte>=  8) { bits[3]=1; byte-=  8; }
  if(byte>=  4) { bits[2]=1; byte-=  4; }
  if(byte>=  2) { bits[1]=1; byte-=  2; }
  if(byte>=  1)   bits[0]=1;
  return bits[bitNr];
}

void InitJoy()
{
  printf("\n\n\nPlease center the joystick and press fire or");
  printf("\npress any key on the keybord to dissable joystick...");
  while(kbhit()) getch();
  while((Byte2Bit(255-inportb(0x0201),4)==0)&&(Byte2Bit(255-inportb(0x0201),5)==0)&&!kbhit());

  if(kbhit())
  {
    while(kbhit()) getch();
    joystickEnabled=FALSE;
  }
  else
  {
    joystickEnabled=TRUE;
    joyCenterX=0;
    outportb(0x0201, 255);
    while(Byte2Bit(255-inportb(0x0201),0)==0) joyCenterX++;

    while(Byte2Bit(255-inportb(0x0201),1)==0);

    joyCenterY=0;
    outportb(0x0201, 255);
    while(Byte2Bit(255-inportb(0x0201),1)==0) joyCenterY++;
  }
}

void ReadJoystick()
{
  int countX=0, countY=0;
  float slaskX, slaskY;

  outportb(0x0201, 255);
  while(Byte2Bit(255-inportb(0x0201),0)==0) countX++;

  while(Byte2Bit(255-inportb(0x0201),1)==0); // VÑntar till 0

  outportb(0x0201, 255);
  while(Byte2Bit(255-inportb(0x0201),1)==0) countY++;

  float xRatio=(float)countX/(float)joyCenterX;
  float yRatio=(float)countY/(float)joyCenterY;

  if(xRatio>1)
    slaskX=2-xRatio;
  else
    slaskX=xRatio;

  if(yRatio>1)
    slaskY=2-yRatio;
  else
    slaskY=yRatio;

  if(slaskX<slaskY)
  {
    if(xRatio<0.6)
      prefDir=LEFT;
    else
      if(xRatio>1.4)
	prefDir=RIGHT;
  }
  else
  {
  if(yRatio<0.6)
    prefDir=UP;
  else
    if(yRatio>1.4)
      prefDir=DOWN;
  }
}

long CheckComputerSpeed()
{
  time_t t;
  long count=0;
  int slask;
  char i;

  printf("\nChecking computer speed...");

  setfillstyle(SOLID_FILL, BLACK);

  t = time(NULL);
  while(t==time(NULL));
  while((t+4)>time(NULL))
  {
    bar(400,400,420,420);
    for(i=0;i<25;i++)
      slask=random(500)*random(50)/(random(250)+1);
    count++;
  }
  count/=3;
  printf(" Done!\n");
  if(count<500)
    printf("\nUhmb... Please bye a faster computer! ;-)\n");
  return count;
}

void Meny()
{
  SoundOff();
  int countY;
  float yRatio;
  char val=0, menyNr=0, keyIn, buttonPressed=TRUE;
  textPos=0;
  if(runningGame) val=1;

  cleardevice();
  ScrollInit();
  MenuText(menyNr, val);

  while(1)
  {
    Rasters();
    Scrolla();

    if(joystickEnabled)
    {
      if(buttonPressed)
      {
        if((Byte2Bit(255-inportb(0x0201),4)==0)&&(Byte2Bit(255-inportb(0x0201),5)==0))
          buttonPressed=FALSE;
      }
      else if((Byte2Bit(255-inportb(0x0201),4)==1)||(Byte2Bit(255-inportb(0x0201),5)==1))
      {
	asm mov ah,05h;    // Utfîrs nÑr en joystickknapp trycks in fîr
	asm mov cl,13;     // att lÑgga enter i tangentbordsbufferten.
	asm int 16h;
        buttonPressed=TRUE;
      }

      countY=0;
      outportb(0x0201, 255);
      while(Byte2Bit(255-inportb(0x0201),1)==0)
	countY++;

      yRatio=(float)countY/(float)joyCenterY;

      if(debug)
      {
	setpalette(7,255);
	gotoxy(1,16);
	printf("yRatio: %f  ",yRatio);
      }

      if(yRatio<0.6)
      {
	asm mov ah,05h;
	asm mov cl,43;     // LÑgger + i tangentbordsbufferten.
	asm int 16h;
      }
      if(yRatio>1.4)
      {
	asm mov ah,05h;
	asm mov cl,45;     // LÑgger - i tangentbordsbufferten.
	asm int 16h;
      }
    }

    while(kbhit())
    {
      keyIn=getch();

      if((keyIn==13)||(keyIn==32)) // Enter eller mellanslag
      {
        if(menyNr==0)
          switch(val)
	  {
	    case 0 : runningGame=FALSE; // Start new game
	     	     return;
	    case 1 : return;            // Resume game
	    case 2 : menyNr=1;          // Sound menu
                     val=0;
                     break;
	    case 4 : keyIn=27;          // Quit
	  }
	else if(menyNr==1)
	  switch(val)
	  {
	    case 0 : soundDevice++;
		     if(soundDevice>2) soundDevice=0;
		     if((soundDevice==2)&&(IOport==0)) soundDevice=0;
		     break;
	    case 1 : if(musicEnabled) musicEnabled=FALSE;
		     else musicEnabled=TRUE;
		     break;
	    case 2 : if(dotSoundEnabled) dotSoundEnabled=FALSE;
		     else dotSoundEnabled=TRUE;
		     break;
	    case 3 : menyNr=0;          // Main menu
		     if(runningGame)
		       val=1;
		     else
		       val=0;
	  }
	MenuText(menyNr, val);
      }
      if(keyIn==27) // ESC
      {
	if(menyNr==0)
	{
          closegraph();
          clrscr();
          printf("Thank you for playing Netman!\n\n");
          exit(0);
	}
	else
	{
	  menyNr=0;          // Main menu
	  if(runningGame)
	    val=1;
	  else
	    val=0;
	  MenuText(menyNr, val);
	}
      }
      if((keyIn==0)||(keyIn=='+')||(keyIn=='-'))
        if(keyIn=='+')
	  keyIn=72;
	if(keyIn=='-')
	  keyIn=80;
	if(keyIn==0)
	  keyIn=getch();
	switch(keyIn)
	{
	  case 72 : if(val>0) // UP
		      val--;
		    if((menyNr==0)&&(!runningGame)&&(val==1))
		      val--;
		    if((menyNr==1)&&(!soundDevice)&&(val==2))
		      val=0;
		    MenuText(menyNr, val);
		    break;
	  case 80 : val++; // DOWN
		    if((menyNr==0)&&(val>4))
		      val=4;
		    if((menyNr==0)&&(!runningGame)&&(val==1))
		      val++;
		    if((menyNr==1)&&(val>3))
		      val=3;
		    if((menyNr==1)&&(!soundDevice)&&(val==1))
		      val=3;
		    MenuText(menyNr, val);
	}
    }
  }
}

void MenuText(char menyNr, char val)
{
  switch(menyNr)
  {
    case 0 : MainMenuText(val); break;
    case 1 : SoundMenuText(val);
  }
}

void MainMenuText(char val)
{
  setfillstyle(BLACK,SOLID_FILL);
  bar(205,195,400,350);

  if(val==0)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  outtextxy(205,195,"Start new game");

  if(!runningGame)
    setcolor(8);
  else
  {
    if(val==1)
      setcolor(LIGHTGREEN);
    else
      setcolor(GREEN);
  }
  outtextxy(205,225,"Resume game");

  if(val==2)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  outtextxy(205,255,"Sound...");

  if(val==3)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  outtextxy(205,285,"Network game...");

  if(val==4)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  outtextxy(205,315,"Quit");
}

void SoundMenuText(char val)
{
  setfillstyle(BLACK,SOLID_FILL);
  bar(205,195,400,350);

  if(val==0)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  switch(soundDevice)
  {
    case  0 : outtextxy(205,195,"No sound"); break;
    case  1 : outtextxy(205,195,"PC speaker"); break;
    case  2 : outtextxy(205,195,"Sound Blaster");
  }

  if(val==1)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  if(!soundDevice)
    setcolor(8);
  if(musicEnabled)
    outtextxy(205,225,"Music");
  else
    outtextxy(205,225,"No music");

  if(val==2)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  if(!soundDevice)
    setcolor(8);
  if(dotSoundEnabled)
    outtextxy(205,255,"Dot sound");
  else
    outtextxy(205,255,"No dot sound");

  if(val==3)
    setcolor(LIGHTGREEN);
  else
    setcolor(GREEN);
  outtextxy(205,285,"Main menu");
}

void Wait(long tal)
{
  for(long i=0;i<tal;i++);
}

