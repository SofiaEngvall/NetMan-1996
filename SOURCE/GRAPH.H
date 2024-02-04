#include<graphics.h>

#define PACRADIE 10
#define YMAXRASTER 110
#define YMINRASTER 0
#define TRUE 1
#define FALSE 0

int textPos;

void *Pac[4][5];
// void *ArgPac[4][5]; // F”r n„tverk - n„r Pac:en kan „ta andra...
void *Block[50];
void *Prick[3];
void *Ghost[4];
void *AfraidGhost;
void *Scroll;

void DrawBlock();
void InitGraph();
void Rasters();
void Drawraster(int);
void Drawraster1(int);
void Drawraster10(int);
void Drawraster11(int);
void ScrollInit();
void Scrolla();

void DrawBlock()
{
  int size=imagesize(0, 0, 20, 20);
  cleardevice();
  setfillstyle(SOLID_FILL, YELLOW);
  setcolor(YELLOW); // BLACK?

// Uppgubbe
  pieslice(10, 10, 0, 90, PACRADIE);
  pieslice(10, 10, 90, 360, PACRADIE);
  Pac[0][0]=malloc(size);
  getimage(0, 0, 20, 20, Pac[0][0]);
  putimage(0, 0, Pac[0][0], XOR_PUT);

  pieslice(10, 10, 0, 78, PACRADIE);
  pieslice(10, 10, 102, 360, PACRADIE);
  Pac[0][1]=malloc(size);
  getimage(0, 0, 20, 20, Pac[0][1]);
  putimage(0, 0, Pac[0][1], XOR_PUT);

  pieslice(10, 10, 0, 66, PACRADIE);
  pieslice(10, 10, 114, 360, PACRADIE);
  Pac[0][2]=malloc(size);
  getimage(0, 0, 20, 20, Pac[0][2]);
  putimage(0, 0, Pac[0][2], XOR_PUT);

  pieslice(10, 10, 0, 54, PACRADIE);
  pieslice(10, 10, 126, 360, PACRADIE);
  Pac[0][3]=malloc(size);
  getimage(0, 0, 20, 20, Pac[0][3]);
  putimage(0, 0, Pac[0][3], XOR_PUT);

  pieslice(10, 10, 0, 42, PACRADIE);
  pieslice(10, 10, 138, 360, PACRADIE);
  Pac[0][4]=malloc(size);
  getimage(0, 0, 20, 20, Pac[0][4]);
  putimage(0, 0, Pac[0][4], XOR_PUT);

// V„nstergubbe
  pieslice(10, 10, 0, 180, PACRADIE);
  pieslice(10, 10, 180, 360, PACRADIE);
  Pac[1][0]=malloc(size);
  getimage(0, 0, 20, 20, Pac[1][0]);
  putimage(0, 0, Pac[1][0], XOR_PUT);

  pieslice(10, 10, 0, 168, PACRADIE);
  pieslice(10, 10, 192, 360, PACRADIE);
  Pac[1][1]=malloc(size);
  getimage(0, 0, 20, 20, Pac[1][1]);
  putimage(0, 0, Pac[1][1], XOR_PUT);

  pieslice(10, 10, 0, 156, PACRADIE);
  pieslice(10, 10, 204, 360, PACRADIE);
  Pac[1][2]=malloc(size);
  getimage(0, 0, 20, 20, Pac[1][2]);
  putimage(0, 0, Pac[1][2], XOR_PUT);

  pieslice(10, 10, 0, 144, PACRADIE);
  pieslice(10, 10, 216, 360, PACRADIE);
  Pac[1][3]=malloc(size);
  getimage(0, 0, 20, 20, Pac[1][3]);
  putimage(0, 0, Pac[1][3], XOR_PUT);

  pieslice(10, 10, 0, 132, PACRADIE);
  pieslice(10, 10, 228, 360, PACRADIE);
  Pac[1][4]=malloc(size);
  getimage(0, 0, 20, 20, Pac[1][4]);
  putimage(0, 0, Pac[1][4], XOR_PUT);

// H”gergubbe
  pieslice(10, 10, 0, 360, PACRADIE);
  Pac[2][0]=malloc(size);
  getimage(0, 0, 20, 20, Pac[2][0]);
  putimage(0, 0, Pac[2][0], XOR_PUT);

  pieslice(10, 10, 12, 348, PACRADIE);
  Pac[2][1]=malloc(size);
  getimage(0, 0, 20, 20, Pac[2][1]);
  putimage(0, 0, Pac[2][1], XOR_PUT);

  pieslice(10, 10, 24, 336, PACRADIE);
  Pac[2][2]=malloc(size);
  getimage(0, 0, 20, 20, Pac[2][2]);
  putimage(0, 0, Pac[2][2], XOR_PUT);

  pieslice(10, 10, 36, 324, PACRADIE);
  Pac[2][3]=malloc(size);
  getimage(0, 0, 20, 20, Pac[2][3]);
  putimage(0, 0, Pac[2][3], XOR_PUT);

  pieslice(10, 10, 48, 312, PACRADIE);
  Pac[2][4]=malloc(size);
  getimage(0, 0, 20, 20, Pac[2][4]);
  putimage(0, 0, Pac[2][4], XOR_PUT);

// Nergubbe
  pieslice(10, 10, 0, 270, PACRADIE);
  pieslice(10, 10, 270, 360, PACRADIE);
  Pac[3][0]=malloc(size);
  getimage(0, 0, 20, 20, Pac[3][0]);
  putimage(0, 0, Pac[3][0], XOR_PUT);

  pieslice(10, 10, 0, 258, PACRADIE);
  pieslice(10, 10, 282, 360, PACRADIE);
  Pac[3][1]=malloc(size);
  getimage(0, 0, 20, 20, Pac[3][1]);
  putimage(0, 0, Pac[3][1], XOR_PUT);

  pieslice(10, 10, 0, 246, PACRADIE);
  pieslice(10, 10, 294, 360, PACRADIE);
  Pac[3][2]=malloc(size);
  getimage(0, 0, 20, 20, Pac[3][2]);
  putimage(0, 0, Pac[3][2], XOR_PUT);

  pieslice(10, 10, 0, 234, PACRADIE);
  pieslice(10, 10, 306, 360, PACRADIE);
  Pac[3][3]=malloc(size);
  getimage(0, 0, 20, 20, Pac[3][3]);
  putimage(0, 0, Pac[3][3], XOR_PUT);

  pieslice(10, 10, 0, 222, PACRADIE);
  pieslice(10, 10, 318, 360, PACRADIE);
  Pac[3][4]=malloc(size);
  getimage(0, 0, 20, 20, Pac[3][4]);
  putimage(0, 0, Pac[3][4], XOR_PUT);


// Ghost
  setfillstyle(SOLID_FILL, RED);
  setcolor(RED);
  fillellipse(10, 5, 10, 5);
  bar(0,5,20,20);
  setfillstyle(SOLID_FILL, BLACK);
  setcolor(BLACK);
  bar(6,6,7,8);
  bar(13,6,14,8);
  Ghost[0]=malloc(size);
  getimage(0, 0, 20, 20, Ghost[0]);
  putimage(0, 0, Ghost[0], XOR_PUT);

  setfillstyle(SOLID_FILL, LIGHTBLUE);
  setcolor(LIGHTBLUE);
  fillellipse(10, 5, 10, 5);
  bar(0,5,20,20);
  setfillstyle(SOLID_FILL, BLACK);
  setcolor(BLACK);
  bar(6,6,7,8);
  bar(13,6,14,8);
  Ghost[1]=malloc(size);
  getimage(0, 0, 20, 20, Ghost[1]);
  putimage(0, 0, Ghost[1], XOR_PUT);

  setfillstyle(SOLID_FILL, LIGHTRED);
  setcolor(LIGHTRED);
  fillellipse(10, 5, 10, 5);
  bar(0,5,20,20);
  setfillstyle(SOLID_FILL, BLACK);
  setcolor(BLACK);
  bar(6,6,7,8);
  bar(13,6,14,8);
  Ghost[2]=malloc(size);
  getimage(0, 0, 20, 20, Ghost[2]);
  putimage(0, 0, Ghost[2], XOR_PUT);

  setfillstyle(SOLID_FILL, LIGHTGREEN);
  setcolor(LIGHTGREEN);
  fillellipse(10, 5, 10, 5);
  bar(0,5,20,20);
  setfillstyle(SOLID_FILL, BLACK);
  setcolor(BLACK);
  bar(6,6,7,8);
  bar(13,6,14,8);
  Ghost[3]=malloc(size);
  getimage(0, 0, 20, 20, Ghost[3]);
  putimage(0, 0, Ghost[3], XOR_PUT);

  setfillstyle(SOLID_FILL, BLUE);
  setcolor(BLUE);
  fillellipse(10, 5, 10, 5);
  bar(0,5,20,20);
  setfillstyle(SOLID_FILL, BLACK);
  setcolor(BLACK);
  bar(6,6,7,8);
  bar(13,6,14,8);
  AfraidGhost=malloc(size);
  getimage(0, 0, 20, 20, AfraidGhost);
  putimage(0, 0, AfraidGhost, XOR_PUT);


// Block
  Block[0]=malloc(size);
  getimage(0, 0, 20, 20, Block[0]);

  setfillstyle(SOLID_FILL, GREEN); // F„rg p† banan
//  setcolor(GREEN);                 // Beh”vs denna?

  bar(5,5,20,15);
  bar(5,5,15,20);
  Block[1]=malloc(size);
  getimage(0, 0, 20, 20, Block[1]);
  putimage(0, 0, Block[1], XOR_PUT);

  bar(0,5,15,15);
  bar(5,5,15,20);
  Block[2]=malloc(size);
  getimage(0, 0, 20, 20, Block[2]);
  putimage(0, 0, Block[2], XOR_PUT);

  bar(5,0,15,15);
  bar(5,5,20,15);
  Block[3]=malloc(size);
  getimage(0, 0, 20, 20, Block[3]);
  putimage(0, 0, Block[3], XOR_PUT);

  bar(5,0,15,15);
  bar(0,5,15,15);
  Block[4]=malloc(size);
  getimage(0, 0, 20, 20, Block[4]);
  putimage(0, 0, Block[4], XOR_PUT);

  bar(0,5,20,15);
  Block[5]=malloc(size);
  getimage(0, 0, 20, 20, Block[5]);
  putimage(0, 0, Block[5], XOR_PUT);

  bar(5,0,15,20);
  Block[6]=malloc(size);
  getimage(0, 0, 20, 20, Block[6]);
  putimage(0, 0, Block[6], XOR_PUT);

  bar(5,5,15,20);
  bar(0,5,20,15);
  Block[7]=malloc(size);
  getimage(0, 0, 20, 20, Block[7]);
  putimage(0, 0, Block[7], XOR_PUT);

  bar(5,5,20,15);
  bar(5,0,15,20);
  Block[8]=malloc(size);
  getimage(0, 0, 20, 20, Block[8]);
  putimage(0, 0, Block[8], XOR_PUT);

  bar(5,0,15,15);
  bar(0,5,20,15);
  Block[9]=malloc(size);
  getimage(0, 0, 20, 20, Block[9]);
  putimage(0, 0, Block[9], XOR_PUT);

  bar(0,5,15,15);
  bar(5,0,15,20);
  Block[10]=malloc(size);
  getimage(0, 0, 20, 20, Block[10]);
  putimage(0, 0, Block[10], XOR_PUT);

  bar(0,5,20,15);
  bar(5,0,15,20);
  Block[11]=malloc(size);
  getimage(0, 0, 20, 20, Block[11]);
  putimage(0, 0, Block[11], XOR_PUT);

  bar(0,0,20,15);
  bar(0,0,15,20);
  Block[12]=malloc(size);
  getimage(0, 0, 20, 20, Block[12]);
  putimage(0, 0, Block[12], XOR_PUT);

  bar(0,0,20,15);
  bar(5,0,20,20);
  Block[13]=malloc(size);
  getimage(0, 0, 20, 20, Block[13]);
  putimage(0, 0, Block[13], XOR_PUT);

  bar(0,5,20,20);
  bar(0,0,15,20);
  Block[14]=malloc(size);
  getimage(0, 0, 20, 20, Block[14]);
  putimage(0, 0, Block[14], XOR_PUT);

  bar(5,0,20,20);
  bar(0,5,20,20);
  Block[15]=malloc(size);
  getimage(0, 0, 20, 20, Block[15]);
  putimage(0, 0, Block[15], XOR_PUT);

  bar(0,0,20,15);
  Block[16]=malloc(size);
  getimage(0, 0, 20, 20, Block[16]);
  putimage(0, 0, Block[16], XOR_PUT);

  bar(0,5,20,20);
  Block[17]=malloc(size);
  getimage(0, 0, 20, 20, Block[17]);
  putimage(0, 0, Block[17], XOR_PUT);

  bar(0,0,15,20);
  Block[18]=malloc(size);
  getimage(0, 0, 20, 20, Block[18]);
  putimage(0, 0, Block[18], XOR_PUT);

  bar(5,0,20,20);
  Block[19]=malloc(size);
  getimage(0, 0, 20, 20, Block[19]);
  putimage(0, 0, Block[19], XOR_PUT);

  bar(5,5,15,20);
  bar(0,0,20,15);
  Block[20]=malloc(size);
  getimage(0, 0, 20, 20, Block[20]);
  putimage(0, 0, Block[20], XOR_PUT);

  bar(5,0,15,15);
  bar(0,5,20,20);
  Block[21]=malloc(size);
  getimage(0, 0, 20, 20, Block[21]);
  putimage(0, 0, Block[21], XOR_PUT);

  bar(5,5,20,15);
  bar(0,0,15,20);
  Block[22]=malloc(size);
  getimage(0, 0, 20, 20, Block[22]);
  putimage(0, 0, Block[22], XOR_PUT);

  bar(0,5,15,15);
  bar(5,0,20,20);
  Block[23]=malloc(size);
  getimage(0, 0, 20, 20, Block[23]);
  putimage(0, 0, Block[23], XOR_PUT);

  bar(5,0,15,15);
  Block[24]=malloc(size);
  getimage(0, 0, 20, 20, Block[24]);
  putimage(0, 0, Block[24], XOR_PUT);

  bar(5,5,15,20);
  Block[25]=malloc(size);
  getimage(0, 0, 20, 20, Block[25]);
  putimage(0, 0, Block[25], XOR_PUT);

  bar(0,5,15,15);
  Block[26]=malloc(size);
  getimage(0, 0, 20, 20, Block[26]);
  putimage(0, 0, Block[26], XOR_PUT);

  bar(5,5,20,15);
  Block[27]=malloc(size);
  getimage(0, 0, 20, 20, Block[27]);
  putimage(0, 0, Block[27], XOR_PUT);

  bar(0,0,15,15);
  Block[28]=malloc(size);
  getimage(0, 0, 20, 20, Block[28]);
  putimage(0, 0, Block[28], XOR_PUT);

  bar(5,0,20,15);
  Block[29]=malloc(size);
  getimage(0, 0, 20, 20, Block[29]);
  putimage(0, 0, Block[29], XOR_PUT);

  bar(5,5,20,20);
  Block[30]=malloc(size);
  getimage(0, 0, 20, 20, Block[30]);
  putimage(0, 0, Block[30], XOR_PUT);

  bar(0,5,15,20);
  Block[31]=malloc(size);
  getimage(0, 0, 20, 20, Block[31]);
  putimage(0, 0, Block[31], XOR_PUT);

  bar(0,0,15,15);
  bar(5,15,15,20);
  Block[32]=malloc(size);
  getimage(0, 0, 20, 20, Block[32]);
  putimage(0, 0, Block[32], XOR_PUT);

  bar(0,0,15,15);
  bar(15,5,20,15);
  Block[33]=malloc(size);
  getimage(0, 0, 20, 20, Block[33]);
  putimage(0, 0, Block[33], XOR_PUT);

  bar(5,0,20,15);
  bar(5,15,15,20);
  Block[34]=malloc(size);
  getimage(0, 0, 20, 20, Block[34]);
  putimage(0, 0, Block[34], XOR_PUT);

  bar(0,5,15,20);
  bar(15,5,20,15);
  Block[35]=malloc(size);
  getimage(0, 0, 20, 20, Block[35]);
  putimage(0, 0, Block[35], XOR_PUT);

  bar(0,5,15,20);
  bar(5,0,15,5);
  Block[36]=malloc(size);
  getimage(0, 0, 20, 20, Block[36]);
  putimage(0, 0, Block[36], XOR_PUT);

  bar(0,5,20,15);
  bar(0,5,5,15);
  Block[37]=malloc(size);
  getimage(0, 0, 20, 20, Block[37]);
  putimage(0, 0, Block[37], XOR_PUT);

  bar(5,5,20,20);
  bar(5,0,15,5);
  Block[38]=malloc(size);
  getimage(0, 0, 20, 20, Block[38]);
  putimage(0, 0, Block[38], XOR_PUT);

  bar(5,5,20,20);
  bar(0,5,5,15);
  Block[39]=malloc(size);
  getimage(0, 0, 20, 20, Block[39]);
  putimage(0, 0, Block[39], XOR_PUT);

  bar(0,0,20,20);
  Block[40]=malloc(size);
  getimage(0, 0, 20, 20, Block[40]);
  putimage(0, 0, Block[40], XOR_PUT);

  setfillstyle(SOLID_FILL, WHITE);
  setcolor(WHITE);

  Prick[0]=malloc(size);
  getimage(0, 0, 20, 20, Prick[0]);

  circle(10,10,2);
  Prick[1]=malloc(size);
  getimage(0, 0, 20, 20, Prick[1]);
  putimage(0, 0, Prick[1], XOR_PUT);

  fillellipse(10, 10, 5, 5);
  Prick[2]=malloc(size);
  getimage(0, 0, 20, 20, Prick[2]);
  putimage(0, 0, Prick[2], XOR_PUT);

}

void InitGraph()
{
  int GraphDriver = VGA;
  int GraphMode = VGAHI;

  initgraph(&GraphDriver, &GraphMode, "");
  int errorCode=graphresult();      // Read result of initialization
  if(errorCode!=grOk)               // Error occured during init
  {
    printf("Graphics System Error: %s\n\n", grapherrormsg(errorCode));
    exit(1);
  }
}

void Rasters()
{
  static int y1=0,a=-2, y2=14,b=-2, y3=28,c=-2, y4=42,d=-2;
  static int y5=56,e=-2, y6=70,f=-2, y7=84,g=-2, y8=98,h=-2;
  static int yy4=42, yy5=56, yy6=70, yy7=84, yy8=98;

  if(y1>=YMAXRASTER) a=-2;
  if(y1<=YMINRASTER) a=2;
  if(y2>=YMAXRASTER) b=-2;
  if(y2<=YMINRASTER) b=2;
  if(y3>=YMAXRASTER) c=-2;
  if(y3<=YMINRASTER) c=2;
  if(y4>=YMAXRASTER) d=-2;
  if(y4<=YMINRASTER) d=2;
  if(y5>=YMAXRASTER) e=-2;
  if(y5<=YMINRASTER) e=2;
  if(y6>=YMAXRASTER) f=-2;
  if(y6<=YMINRASTER) f=2;
  if(y7>=YMAXRASTER) g=-2;
  if(y7<=YMINRASTER) g=2;
  if(y8>=YMAXRASTER) h=-2;
  if(y8<=YMINRASTER) h=2;

  Drawraster10(y5);
  Drawraster10(y4);
  Drawraster10(y3);
  Drawraster10(y2);
  if(((y1>YMINRASTER) && (y1<=YMINRASTER+4)) || ((y1<=YMAXRASTER-1) && (y1>=YMAXRASTER-4)))
    Drawraster10(y1);
  else
    Drawraster11(y1);

  Drawraster(yy4);
  Drawraster(yy5);
  Drawraster(yy6);
  Drawraster(yy7);
  if(((y1>YMINRASTER) && (y1<=YMINRASTER+4)) || ((y1<=YMAXRASTER-1) && (y1>=YMAXRASTER-4)))
    Drawraster(yy8);
  else
    Drawraster1(yy8);

  y1+=a; y2+=b; y3+=c; y4+=d; y5+=e; y6+=f; y7+=g; y8+=h;
  yy4-=e; yy5-=d; yy6-=c; yy7-=b; yy8-=a;
}

void Drawraster1(int y)
{
  y=y+367;
  setfillstyle(SOLID_FILL, 4);
  bar(0, y+2, 639, y+3);
  setfillstyle(SOLID_FILL, 12);
  bar(0, y+4, 639, y+5);
  setfillstyle(SOLID_FILL, 14);
  bar(0, y+6, 639, y+7);
  setfillstyle(SOLID_FILL, 12);
  bar(0, y+8, 639, y+9);
  setfillstyle(SOLID_FILL, 4);
  bar(0, y+10, 639, y+11);
}

void Drawraster(int y)
{
  y=y+367;
  setfillstyle(SOLID_FILL, 0);
  bar(0, y-2, 639, y+1);
  setfillstyle(SOLID_FILL, 4);
  bar(0, y+2, 639, y+3);
  setfillstyle(SOLID_FILL, 12);
  bar(0, y+4, 639, y+5);
  setfillstyle(SOLID_FILL, 14);
  bar(0, y+6, 639, y+7);
  setfillstyle(SOLID_FILL, 12);
  bar(0, y+8, 639, y+9);
  setfillstyle(SOLID_FILL, 4);
  bar(0, y+10, 639, y+11);
  setfillstyle(SOLID_FILL, 0);
  bar(0, y+12, 639, y+15);
}

void Drawraster11(int y)
{
  setfillstyle(SOLID_FILL, BLUE);
  bar(0, y+2, 639, y+3);
  setfillstyle(SOLID_FILL, GREEN);
  bar(0, y+4, 639, y+5);
  setfillstyle(SOLID_FILL, YELLOW);
  bar(0, y+6, 639, y+7);
  setfillstyle(SOLID_FILL, GREEN);
  bar(0, y+8, 639, y+9);
  setfillstyle(SOLID_FILL, BLUE);
  bar(0, y+10, 639, y+11);
}

void Drawraster10(int y)
{
  setfillstyle(SOLID_FILL, 0);
  bar(0, y-2, 639, y+1);
  setfillstyle(SOLID_FILL, BLUE);
  bar(0, y+2, 639, y+3);
  setfillstyle(SOLID_FILL, GREEN);
  bar(0, y+4, 639, y+5);
  setfillstyle(SOLID_FILL, YELLOW);
  bar(0, y+6, 639, y+7);
  setfillstyle(SOLID_FILL, GREEN);
  bar(0, y+8, 639, y+9);
  setfillstyle(SOLID_FILL, BLUE);
  bar(0, y+10, 639, y+11);
  setfillstyle(SOLID_FILL, 0);
  bar(0, y+12, 639, y+15);
}

void ScrollInit()
{
  static char firstTime=TRUE;

  if(firstTime)
  {
    Scroll=malloc(imagesize(5, 136, 639, 185));
    firstTime=FALSE;
  }
  setpalette(7,0);
  for(int y=130;y<186;y++)
  {
    if(y%2==0)
      y+=2;
    for(int x=0;x<640;x++)
    {
      if(x%2==0)
	x+=2;
      putpixel(x-1,y,8);
    }
  }
}

void Scrolla()
{
  static int letterX=0, letterY;

  static char *scrollText="  * * * N E T M A N * * *           Û 1996, Bj”rn Jegelius, Sofia Engvall & G”ran Asklund              ";

  static int textLen=strlen(scrollText);

  if(letterX==0)
  {
    gotoxy(1,14);
    if(scrollText[textPos]=='Û') // Û byts ut mot (c)-tecken
    {
      printf(" ");

      putpixel(2,211,7);
      putpixel(3,211,7);
      putpixel(4,211,7);
      putpixel(5,211,7);

      putpixel(1,212,7);
      putpixel(6,212,7);

      putpixel(1,213,7);
      putpixel(6,213,7);

      putpixel(0,214,7);
      putpixel(3,214,7);
      putpixel(4,214,7);
      putpixel(7,214,7);

      putpixel(0,215,7);
      putpixel(2,215,7);
      putpixel(7,215,7);

      putpixel(0,216,7);
      putpixel(2,216,7);
      putpixel(7,216,7);

      putpixel(0,217,7);
      putpixel(3,217,7);
      putpixel(4,217,7);
      putpixel(7,217,7);

      putpixel(1,218,7);
      putpixel(6,218,7);

      putpixel(1,219,7);
      putpixel(6,219,7);

      putpixel(2,220,7);
      putpixel(3,220,7);
      putpixel(4,220,7);
      putpixel(5,220,7);
    }
    else
      printf("%c",scrollText[textPos]);
    textPos++;
    if(textPos>=textLen)
      textPos=0;
  }

  for(letterY=0;letterY<13;letterY++)
    if(getpixel(letterX,letterY+210)==7)
    {
      putpixel(637,136+letterY*4,14);
      putpixel(637,137+letterY*4,14);
      putpixel(638,136+letterY*4,14);
      putpixel(638,137+letterY*4,14);
    }
    else
    {
      putpixel(637,136+letterY*4,8);
      putpixel(637,137+letterY*4,8);
      putpixel(638,136+letterY*4,8);
      putpixel(638,137+letterY*4,8);
    }

  getimage(5, 136, 639, 185, Scroll);
  putimage(1, 136, Scroll, COPY_PUT);

  letterX++;
  if(letterX>7)
    letterX=0;
}
