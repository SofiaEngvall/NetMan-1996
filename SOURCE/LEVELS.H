#define MAX_X 32
#define MAX_Y 22

char BlockPos[MAX_Y][MAX_X];
char BlockRikt[MAX_Y][MAX_X];
char BlockPrick[MAX_Y][MAX_X];

char LevX, LevY;

int ghostStartX, ghostStartY, pacStartX, pacStartY;

void Level0();
void Level1();
void Level2();
void Level3();
void Level4();
void Level5();
void Level6();

void LoadLevel(int level)
{
  for(int y=0;y<MAX_Y;y++)
    for(int x=0;x<MAX_X;x++)
      BlockPrick[y][x]=0;

  switch(level)
  {
    case  0: Level0(); break;
    case  1: Level1(); break;
    case  2: Level2(); break;
    case  3: Level4(); break;
    case  4: Level6(); break;
    case  5: Level3(); break;
    case  6: Level5(); break;
  }
}

void Level0()
{
  LevX=8; LevY=5;

  pacStartX=20; pacStartY=20;
  ghostStartX=140; ghostStartY=20;

  BlockPos[0][0]=1; BlockPos[0][1]=1; BlockPos[0][2]=1;
  BlockPos[0][3]=1; BlockPos[0][4]=1; BlockPos[0][5]=1;
  BlockPos[0][6]=1; BlockPos[0][7]=1; BlockPos[0][8]=1;

  BlockPos[1][0]=1; BlockPos[1][1]=0; BlockPos[1][2]=0;
  BlockPos[1][3]=0; BlockPos[1][4]=0; BlockPos[1][5]=0;
  BlockPos[1][6]=0; BlockPos[1][7]=0; BlockPos[1][8]=1;

  BlockPos[2][0]=1; BlockPos[2][1]=0; BlockPos[2][2]=1;
  BlockPos[2][3]=0; BlockPos[2][4]=1; BlockPos[2][5]=0;
  BlockPos[2][6]=1; BlockPos[2][7]=1; BlockPos[2][8]=1;

  BlockPos[3][0]=1; BlockPos[3][1]=0; BlockPos[3][2]=0;
  BlockPos[3][3]=0; BlockPos[3][4]=0; BlockPos[3][5]=0;
  BlockPos[3][6]=1;

  BlockPos[4][0]=1; BlockPos[4][1]=1; BlockPos[4][2]=1;
  BlockPos[4][3]=1; BlockPos[4][4]=1; BlockPos[4][5]=1;
  BlockPos[4][6]=1;


//BlockRikt[y][x]= DOWN * 8 + RIGHT * 4 + LEFT * 2 + UP * 1;

  BlockRikt[1][1]= 12; BlockRikt[1][2]= 6; BlockRikt[1][3]= 14;
  BlockRikt[1][4]= 6; BlockRikt[1][5]= 14; BlockRikt[1][6]= 2;
  BlockRikt[1][7]= 2;

  BlockRikt[2][1]= 9; BlockRikt[2][3]= 9; BlockRikt[2][5]= 9;

  BlockRikt[3][1]= 5; BlockRikt[3][2]= 6; BlockRikt[3][3]= 7;
  BlockRikt[3][4]= 6; BlockRikt[3][5]= 3;


  BlockPrick[1][1]= 1; BlockPrick[1][2]= 1; BlockPrick[1][3]= 1;
  BlockPrick[1][4]= 1; BlockPrick[1][5]= 1; BlockPrick[1][6]= 1;
  BlockPrick[1][7]= 0;

  BlockPrick[2][1]= 1; BlockPrick[2][3]= 2; BlockPrick[2][5]= 1;

  BlockPrick[3][1]= 1; BlockPrick[3][2]= 1; BlockPrick[3][3]= 1;
  BlockPrick[3][4]= 1; BlockPrick[3][5]= 1;
}


void Level1()
{
  LevX=21; LevY=22;
  pacStartX=200; pacStartY=320;
  ghostStartX=200; ghostStartY=200;


BlockPos[0][0]=12; BlockPos[0][6]=16; BlockPos[0][11]=16; BlockPos[0][16]=16;
BlockPos[0][1]=16; BlockPos[0][7]=16; BlockPos[0][12]=16; BlockPos[0][17]=16;
BlockPos[0][2]=16; BlockPos[0][8]=16; BlockPos[0][13]=16; BlockPos[0][18]=16;
BlockPos[0][3]=16; BlockPos[0][9]=16; BlockPos[0][14]=16; BlockPos[0][19]=16;
BlockPos[0][4]=16; BlockPos[0][10]=20; BlockPos[0][15]=16; BlockPos[0][20]=13;
BlockPos[0][5]=16;

BlockPos[1][0]=18; BlockPos[1][6]=0; BlockPos[1][11]=0; BlockPos[1][16]=0;
BlockPos[1][1]=0; BlockPos[1][7]=0; BlockPos[1][12]=0; BlockPos[1][17]=0;
BlockPos[1][2]=0; BlockPos[1][8]=0; BlockPos[1][13]=0; BlockPos[1][18]=0;
BlockPos[1][3]=0; BlockPos[1][9]=0; BlockPos[1][14]=0; BlockPos[1][19]=0;
BlockPos[1][4]=0; BlockPos[1][10]=6; BlockPos[1][15]=0; BlockPos[1][20]=19;
BlockPos[1][5]=0;

BlockPos[2][0]=18; BlockPos[2][6]=27; BlockPos[2][11]=0; BlockPos[2][16]=27;
BlockPos[2][1]=0; BlockPos[2][7]=5; BlockPos[2][12]=27; BlockPos[2][17]=5;
BlockPos[2][2]=27; BlockPos[2][8]=26; BlockPos[2][13]=5; BlockPos[2][18]=26;
BlockPos[2][3]=5; BlockPos[2][9]=0; BlockPos[2][14]=26; BlockPos[2][19]=0;
BlockPos[2][4]=26; BlockPos[2][10]=24; BlockPos[2][15]=0; BlockPos[2][20]=19;
BlockPos[2][5]=0;

BlockPos[3][0]=18; BlockPos[3][6]=0; BlockPos[3][11]=0; BlockPos[3][16]=0;
BlockPos[3][1]=0; BlockPos[3][7]=0; BlockPos[3][12]=0; BlockPos[3][17]=0;
BlockPos[3][2]=0; BlockPos[3][8]=0; BlockPos[3][13]=0; BlockPos[3][18]=0;
BlockPos[3][3]=0; BlockPos[3][9]=0; BlockPos[3][14]=0; BlockPos[3][19]=0;
BlockPos[3][4]=0; BlockPos[3][10]=0; BlockPos[3][15]=0; BlockPos[3][20]=19;
BlockPos[3][5]=0;

BlockPos[4][0]=18; BlockPos[4][6]=25; BlockPos[4][11]=5; BlockPos[4][16]=27;
BlockPos[4][1]=0; BlockPos[4][7]=0; BlockPos[4][12]=26; BlockPos[4][17]=5;
BlockPos[4][2]=27; BlockPos[4][8]=27; BlockPos[4][13]=0; BlockPos[4][18]=26;
BlockPos[4][3]=5; BlockPos[4][9]=5; BlockPos[4][14]=25; BlockPos[4][19]=0;
BlockPos[4][4]=26; BlockPos[4][10]=7; BlockPos[4][15]=0; BlockPos[4][20]=19;
BlockPos[4][5]=0;

BlockPos[5][0]=18; BlockPos[5][6]=6; BlockPos[5][11]=0; BlockPos[5][16]=0;
BlockPos[5][1]=0; BlockPos[5][7]=0; BlockPos[5][12]=0; BlockPos[5][17]=0;
BlockPos[5][2]=0; BlockPos[5][8]=0; BlockPos[5][13]=0; BlockPos[5][18]=0;
BlockPos[5][3]=0; BlockPos[5][9]=0; BlockPos[5][14]=6; BlockPos[5][19]=0;
BlockPos[5][4]=0; BlockPos[5][10]=6; BlockPos[5][15]=0; BlockPos[5][20]=19;
BlockPos[5][5]=0;

BlockPos[6][0]=14; BlockPos[6][6]=8; BlockPos[6][11]=0; BlockPos[6][16]=30;
BlockPos[6][1]=17; BlockPos[6][7]=5; BlockPos[6][12]=27; BlockPos[6][17]=17;
BlockPos[6][2]=17; BlockPos[6][8]=26; BlockPos[6][13]=5; BlockPos[6][18]=17;
BlockPos[6][3]=17; BlockPos[6][9]=0; BlockPos[6][14]=10; BlockPos[6][19]=17;
BlockPos[6][4]=31; BlockPos[6][10]=24; BlockPos[6][15]=0; BlockPos[6][20]=15;
BlockPos[6][5]=0;

BlockPos[7][0]=0; BlockPos[7][6]=6; BlockPos[7][11]=0; BlockPos[7][16]=19;
BlockPos[7][1]=0; BlockPos[7][7]=0; BlockPos[7][12]=0; BlockPos[7][17]=0;
BlockPos[7][2]=0; BlockPos[7][8]=0; BlockPos[7][13]=0; BlockPos[7][18]=0;
BlockPos[7][3]=0; BlockPos[7][9]=0; BlockPos[7][14]=6; BlockPos[7][19]=0;
BlockPos[7][4]=18; BlockPos[7][10]=0; BlockPos[7][15]=0; BlockPos[7][20]=0;
BlockPos[7][5]=0;

BlockPos[8][0]=0; BlockPos[8][6]=6; BlockPos[8][11]=0; BlockPos[8][16]=19;
BlockPos[8][1]=0; BlockPos[8][7]=0; BlockPos[8][12]=25; BlockPos[8][17]=0;
BlockPos[8][2]=0; BlockPos[8][8]=25; BlockPos[8][13]=0; BlockPos[8][18]=0;
BlockPos[8][3]=0; BlockPos[8][9]=0; BlockPos[8][14]=6; BlockPos[8][19]=0;
BlockPos[8][4]=18; BlockPos[8][10]=0; BlockPos[8][15]=0; BlockPos[8][20]=0;
BlockPos[8][5]=0;

BlockPos[9][0]=16; BlockPos[9][6]=24; BlockPos[9][11]=0; BlockPos[9][16]=29;
BlockPos[9][1]=16; BlockPos[9][7]=0; BlockPos[9][12]=6; BlockPos[9][17]=16;
BlockPos[9][2]=16; BlockPos[9][8]=6; BlockPos[9][13]=0; BlockPos[9][18]=16;
BlockPos[9][3]=16; BlockPos[9][9]=0; BlockPos[9][14]=24; BlockPos[9][19]=16;
BlockPos[9][4]=28; BlockPos[9][10]=0; BlockPos[9][15]=0; BlockPos[9][20]=16;
BlockPos[9][5]=0;

BlockPos[10][0]=0; BlockPos[10][6]=0; BlockPos[10][11]=0; BlockPos[10][16]=0;
BlockPos[10][1]=0; BlockPos[10][7]=0; BlockPos[10][12]=6; BlockPos[10][17]=0;
BlockPos[10][2]=0; BlockPos[10][8]=6; BlockPos[10][13]=0; BlockPos[10][18]=0;
BlockPos[10][3]=0; BlockPos[10][9]=0; BlockPos[10][14]=0; BlockPos[10][19]=0;
BlockPos[10][4]=0; BlockPos[10][10]=0; BlockPos[10][15]=0; BlockPos[10][20]=0;
BlockPos[10][5]=0;

BlockPos[11][0]=17; BlockPos[11][6]=25; BlockPos[11][11]=5; BlockPos[11][16]=30;
BlockPos[11][1]=17; BlockPos[11][7]=0; BlockPos[11][12]=4; BlockPos[11][17]=17;
BlockPos[11][2]=17; BlockPos[11][8]=3; BlockPos[11][13]=0; BlockPos[11][18]=17;
BlockPos[11][3]=17; BlockPos[11][9]=5; BlockPos[11][14]=25; BlockPos[11][19]=17;
BlockPos[11][4]=31; BlockPos[11][10]=5; BlockPos[11][15]=0; BlockPos[11][20]=17;
BlockPos[11][5]=0;

BlockPos[12][0]=0; BlockPos[12][6]=6; BlockPos[12][11]=0; BlockPos[12][16]=19;
BlockPos[12][1]=0; BlockPos[12][7]=0; BlockPos[12][12]=0; BlockPos[12][17]=0;
BlockPos[12][2]=0; BlockPos[12][8]=0; BlockPos[12][13]=0; BlockPos[12][18]=0;
BlockPos[12][3]=0; BlockPos[12][9]=0; BlockPos[12][14]=6; BlockPos[12][19]=0;
BlockPos[12][4]=18; BlockPos[12][10]=0; BlockPos[12][15]=0; BlockPos[12][20]=0;
BlockPos[12][5]=0;

BlockPos[13][0]=12; BlockPos[13][6]=24; BlockPos[13][11]=5; BlockPos[13][16]=29;
BlockPos[13][1]=16; BlockPos[13][7]=0; BlockPos[13][12]=26; BlockPos[13][17]=16;
BlockPos[13][2]=16; BlockPos[13][8]=27; BlockPos[13][13]=0; BlockPos[13][18]=16;
BlockPos[13][3]=16; BlockPos[13][9]=5; BlockPos[13][14]=24; BlockPos[13][19]=16;
BlockPos[13][4]=28; BlockPos[13][10]=7; BlockPos[13][15]=0; BlockPos[13][20]=13;
BlockPos[13][5]=0;

BlockPos[14][0]=18; BlockPos[14][6]=0; BlockPos[14][11]=0; BlockPos[14][16]=0;
BlockPos[14][1]=0; BlockPos[14][7]=0; BlockPos[14][12]=0; BlockPos[14][17]=0;
BlockPos[14][2]=0; BlockPos[14][8]=0; BlockPos[14][13]=0; BlockPos[14][18]=0;
BlockPos[14][3]=0; BlockPos[14][9]=0; BlockPos[14][14]=0; BlockPos[14][19]=0;
BlockPos[14][4]=0; BlockPos[14][10]=6; BlockPos[14][15]=0; BlockPos[14][20]=19;
BlockPos[14][5]=0;

BlockPos[15][0]=18; BlockPos[15][6]=27; BlockPos[15][11]=0; BlockPos[15][16]=1;
BlockPos[15][1]=0; BlockPos[15][7]=5; BlockPos[15][12]=27; BlockPos[15][17]=5;
BlockPos[15][2]=27; BlockPos[15][8]=26; BlockPos[15][13]=5; BlockPos[15][18]=26;
BlockPos[15][3]=5; BlockPos[15][9]=0; BlockPos[15][14]=26; BlockPos[15][19]=0;
BlockPos[15][4]=2; BlockPos[15][10]=24; BlockPos[15][15]=0; BlockPos[15][20]=19;
BlockPos[15][5]=0;

BlockPos[16][0]=18; BlockPos[16][6]=0; BlockPos[16][11]=0; BlockPos[16][16]=6;
BlockPos[16][1]=0; BlockPos[16][7]=0; BlockPos[16][12]=0; BlockPos[16][17]=0;
BlockPos[16][2]=0; BlockPos[16][8]=0; BlockPos[16][13]=0; BlockPos[16][18]=0;
BlockPos[16][3]=0; BlockPos[16][9]=0; BlockPos[16][14]=0; BlockPos[16][19]=0;
BlockPos[16][4]=6; BlockPos[16][10]=0; BlockPos[16][15]=0; BlockPos[16][20]=19;
BlockPos[16][5]=0;

BlockPos[17][0]=22; BlockPos[17][6]=25; BlockPos[17][11]=5; BlockPos[17][16]=24;
BlockPos[17][1]=5; BlockPos[17][7]=0; BlockPos[17][12]=26; BlockPos[17][17]=0;
BlockPos[17][2]=26; BlockPos[17][8]=27; BlockPos[17][13]=0; BlockPos[17][18]=27;
BlockPos[17][3]=0; BlockPos[17][9]=5; BlockPos[17][14]=25; BlockPos[17][19]=5;
BlockPos[17][4]=24; BlockPos[17][10]=7; BlockPos[17][15]=0; BlockPos[17][20]=23;
BlockPos[17][5]=0;

BlockPos[18][0]=18; BlockPos[18][6]=6; BlockPos[18][11]=0; BlockPos[18][16]=0;
BlockPos[18][1]=0; BlockPos[18][7]=0; BlockPos[18][12]=0; BlockPos[18][17]=0;
BlockPos[18][2]=0; BlockPos[18][8]=0; BlockPos[18][13]=0; BlockPos[18][18]=0;
BlockPos[18][3]=0; BlockPos[18][9]=0; BlockPos[18][14]=6; BlockPos[18][19]=0;
BlockPos[18][4]=0; BlockPos[18][10]=6; BlockPos[18][15]=0; BlockPos[18][20]=19;
BlockPos[18][5]=0;

BlockPos[19][0]=18; BlockPos[19][6]=9; BlockPos[19][11]=0; BlockPos[19][16]=5;
BlockPos[19][1]=0; BlockPos[19][7]=5; BlockPos[19][12]=27; BlockPos[19][17]=5;
BlockPos[19][2]=27; BlockPos[19][8]=26; BlockPos[19][13]=5; BlockPos[19][18]=26;
BlockPos[19][3]=5; BlockPos[19][9]=0; BlockPos[19][14]=9; BlockPos[19][19]=0;
BlockPos[19][4]=5; BlockPos[19][10]=6; BlockPos[19][15]=5; BlockPos[19][20]=19;
BlockPos[19][5]=5;

BlockPos[20][0]=18; BlockPos[20][6]=0; BlockPos[20][11]=0; BlockPos[20][16]=0;
BlockPos[20][1]=0; BlockPos[20][7]=0; BlockPos[20][12]=0; BlockPos[20][17]=0;
BlockPos[20][2]=0; BlockPos[20][8]=0; BlockPos[20][13]=0; BlockPos[20][18]=0;
BlockPos[20][3]=0; BlockPos[20][9]=0; BlockPos[20][14]=0; BlockPos[20][19]=0;
BlockPos[20][4]=0; BlockPos[20][10]=0; BlockPos[20][15]=0; BlockPos[20][20]=19;
BlockPos[20][5]=0;

BlockPos[21][0]=14; BlockPos[21][6]=17; BlockPos[21][11]=17; BlockPos[21][16]=17;
BlockPos[21][1]=17; BlockPos[21][7]=17; BlockPos[21][12]=17; BlockPos[21][17]=17;
BlockPos[21][2]=17; BlockPos[21][8]=17; BlockPos[21][13]=17; BlockPos[21][18]=17;
BlockPos[21][3]=17; BlockPos[21][9]=17; BlockPos[21][14]=17; BlockPos[21][19]=17;
BlockPos[21][4]=17; BlockPos[21][10]=17; BlockPos[21][15]=17; BlockPos[21][20]=15;
BlockPos[21][5]=17;



  BlockRikt[1][1]=12; BlockRikt[1][7]=6; BlockRikt[1][14]=6;
  BlockRikt[1][2]=6; BlockRikt[1][8]=6; BlockRikt[1][15]=14;
  BlockRikt[1][3]=6; BlockRikt[1][9]=10; BlockRikt[1][16]=6;
  BlockRikt[1][4]=6; BlockRikt[1][11]=12; BlockRikt[1][17]=6;
  BlockRikt[1][5]=14; BlockRikt[1][12]=6; BlockRikt[1][18]=6;
  BlockRikt[1][6]=6; BlockRikt[1][13]=6; BlockRikt[1][19]=10;

  BlockRikt[2][1]=9; BlockRikt[2][9]=9; BlockRikt[2][15]=9;
  BlockRikt[2][5]=9; BlockRikt[2][11]=9; BlockRikt[2][19]=9;

  BlockRikt[3][1]=13; BlockRikt[3][7]=14; BlockRikt[3][13]=14;
  BlockRikt[3][2]=6; BlockRikt[3][8]=6; BlockRikt[3][14]=6;
  BlockRikt[3][3]=6; BlockRikt[3][9]=7; BlockRikt[3][15]=15;
  BlockRikt[3][4]=6; BlockRikt[3][10]=6; BlockRikt[3][16]=6;
  BlockRikt[3][5]=15; BlockRikt[3][11]=7; BlockRikt[3][17]=6;
  BlockRikt[3][6]=6; BlockRikt[3][12]=6; BlockRikt[3][18]=6;
   BlockRikt[3][19]=11;

  BlockRikt[4][1]=9; BlockRikt[4][7]=9; BlockRikt[4][15]=9;
  BlockRikt[4][5]=9; BlockRikt[4][13]=9; BlockRikt[4][19]=9;

  BlockRikt[5][1]=5; BlockRikt[5][8]=6; BlockRikt[5][15]=13;
  BlockRikt[5][2]=6; BlockRikt[5][9]=10; BlockRikt[5][16]=6;
  BlockRikt[5][3]=6; BlockRikt[5][11]=12; BlockRikt[5][17]=6;
  BlockRikt[5][4]=6; BlockRikt[5][12]=6; BlockRikt[5][18]=6;
  BlockRikt[5][5]=11; BlockRikt[5][13]=3; BlockRikt[5][19]=3;
  BlockRikt[5][7]=5;

  BlockRikt[6][5]=9; BlockRikt[6][11]=9; BlockRikt[6][15]=9;
  BlockRikt[6][9]=9;

  BlockRikt[7][5]=9; BlockRikt[7][9]=7; BlockRikt[7][12]=6;
  BlockRikt[7][7]=12; BlockRikt[7][10]=6; BlockRikt[7][13]=10;
  BlockRikt[7][8]=6; BlockRikt[7][11]=7; BlockRikt[7][15]=9;

  BlockRikt[8][5]=9; BlockRikt[8][10]=15; BlockRikt[8][13]=9;
  BlockRikt[8][7]=9; BlockRikt[8][11]=11; BlockRikt[8][15]=9;
  BlockRikt[8][9]=13;

  BlockRikt[9][5]=9; BlockRikt[9][10]=15; BlockRikt[9][13]=9;
  BlockRikt[9][7]=9; BlockRikt[9][11]=11; BlockRikt[9][15]=9;
  BlockRikt[9][9]=13;

  BlockRikt[10][0]=4; BlockRikt[10][7]=11; BlockRikt[10][15]=15;
  BlockRikt[10][1]=6; BlockRikt[10][9]=5; BlockRikt[10][16]=6;
  BlockRikt[10][2]=6; BlockRikt[10][10]=7; BlockRikt[10][17]=6;
  BlockRikt[10][3]=6; BlockRikt[10][11]=3; BlockRikt[10][18]=6;
  BlockRikt[10][4]=6; BlockRikt[10][13]=13; BlockRikt[10][19]=6;
  BlockRikt[10][5]=15; BlockRikt[10][14]=6; BlockRikt[10][20]=2;
  BlockRikt[10][6]=6;

  BlockRikt[11][5]=9; BlockRikt[11][13]=9; BlockRikt[11][15]=9;
  BlockRikt[11][7]=9;

  BlockRikt[12][5]=9; BlockRikt[12][9]=6; BlockRikt[12][12]=6;
  BlockRikt[12][7]=13; BlockRikt[12][10]=6; BlockRikt[12][13]=11;
  BlockRikt[12][8]=6; BlockRikt[12][11]=6; BlockRikt[12][15]=9;

  BlockRikt[13][5]=9; BlockRikt[13][13]=9; BlockRikt[13][15]=9;
  BlockRikt[13][7]=9;

  BlockRikt[14][1]=12; BlockRikt[14][7]=7; BlockRikt[14][14]=6;
  BlockRikt[14][2]=6; BlockRikt[14][8]=6; BlockRikt[14][15]=15;
  BlockRikt[14][3]=6; BlockRikt[14][9]=10; BlockRikt[14][16]=6;
  BlockRikt[14][4]=6; BlockRikt[14][11]=12; BlockRikt[14][17]=6;
  BlockRikt[14][5]=15; BlockRikt[14][12]=6; BlockRikt[14][18]=6;
  BlockRikt[14][6]=6; BlockRikt[14][13]=7; BlockRikt[14][19]=10;

  BlockRikt[15][1]=9; BlockRikt[15][9]=9; BlockRikt[15][15]=9;
  BlockRikt[15][5]=9; BlockRikt[15][11]=9; BlockRikt[15][19]=9;

  BlockRikt[16][1]=5; BlockRikt[16][8]=6; BlockRikt[16][14]=6;
  BlockRikt[16][2]=6; BlockRikt[16][9]=7; BlockRikt[16][15]=11;
  BlockRikt[16][3]=10; BlockRikt[16][10]=6; BlockRikt[16][17]=12;
  BlockRikt[16][5]=13; BlockRikt[16][11]=7; BlockRikt[16][18]=6;
  BlockRikt[16][6]=6; BlockRikt[16][12]=6; BlockRikt[16][19]=3;
  BlockRikt[16][7]=14; BlockRikt[16][13]=14;

  BlockRikt[17][3]=9; BlockRikt[17][7]=9; BlockRikt[17][15]=9;
  BlockRikt[17][5]=9; BlockRikt[17][13]=9; BlockRikt[17][17]=9;

  BlockRikt[18][1]=12; BlockRikt[18][8]=6; BlockRikt[18][15]=5;
  BlockRikt[18][2]=6; BlockRikt[18][9]=10; BlockRikt[18][16]=6;
  BlockRikt[18][3]=7; BlockRikt[18][11]=12; BlockRikt[18][17]=7;
  BlockRikt[18][4]=6; BlockRikt[18][12]=6; BlockRikt[18][18]=6;
  BlockRikt[18][5]=3; BlockRikt[18][13]=3; BlockRikt[18][19]=10;
  BlockRikt[18][7]=5;

  BlockRikt[19][1]=9; BlockRikt[19][11]=9; BlockRikt[19][19]=9;
  BlockRikt[19][9]=9;

  BlockRikt[20][1]=5; BlockRikt[20][7]=6; BlockRikt[20][13]=6;
  BlockRikt[20][2]=6; BlockRikt[20][8]=6; BlockRikt[20][14]=6;
  BlockRikt[20][3]=6; BlockRikt[20][9]=7; BlockRikt[20][15]=6;
  BlockRikt[20][4]=6; BlockRikt[20][10]=6; BlockRikt[20][16]=6;
  BlockRikt[20][5]=6; BlockRikt[20][11]=7; BlockRikt[20][17]=6;
  BlockRikt[20][6]=6; BlockRikt[20][12]=6; BlockRikt[20][18]=6;
   BlockRikt[20][19]=3;

// *************************************************************************

  BlockPrick[1][1]=1; BlockPrick[1][7]=1; BlockPrick[1][14]=1;
  BlockPrick[1][2]=1; BlockPrick[1][8]=1; BlockPrick[1][15]=1;
  BlockPrick[1][3]=1; BlockPrick[1][9]=1; BlockPrick[1][16]=1;
  BlockPrick[1][4]=1; BlockPrick[1][11]=1; BlockPrick[1][17]=1;
  BlockPrick[1][5]=1; BlockPrick[1][12]=1; BlockPrick[1][18]=1;
  BlockPrick[1][6]=1; BlockPrick[1][13]=1; BlockPrick[1][19]=1;

  BlockPrick[2][1]=1; BlockPrick[2][9]=1; BlockPrick[2][15]=1;
  BlockPrick[2][5]=1; BlockPrick[2][11]=1; BlockPrick[2][19]=1;

  BlockPrick[3][1]=1; BlockPrick[3][7]=1; BlockPrick[3][13]=1;
  BlockPrick[3][2]=1; BlockPrick[3][8]=1; BlockPrick[3][14]=1;
  BlockPrick[3][3]=1; BlockPrick[3][9]=1; BlockPrick[3][15]=1;
  BlockPrick[3][4]=1; BlockPrick[3][10]=1; BlockPrick[3][16]=1;
  BlockPrick[3][5]=1; BlockPrick[3][11]=1; BlockPrick[3][17]=1;
  BlockPrick[3][6]=1; BlockPrick[3][12]=1; BlockPrick[3][18]=1;
   BlockPrick[3][19]=1;

  BlockPrick[4][1]=2; BlockPrick[4][7]=1; BlockPrick[4][15]=1;
  BlockPrick[4][5]=1; BlockPrick[4][13]=1; BlockPrick[4][19]=2;

  BlockPrick[5][1]=1; BlockPrick[5][8]=1; BlockPrick[5][15]=1;
  BlockPrick[5][2]=1; BlockPrick[5][9]=1; BlockPrick[5][16]=1;
  BlockPrick[5][3]=1; BlockPrick[5][11]=1; BlockPrick[5][17]=1;
  BlockPrick[5][4]=1; BlockPrick[5][12]=1; BlockPrick[5][18]=1;
  BlockPrick[5][5]=1; BlockPrick[5][13]=1; BlockPrick[5][19]=1;
  BlockPrick[5][7]=1;

  BlockPrick[6][5]=1; BlockPrick[6][11]=0; BlockPrick[6][15]=1;
  BlockPrick[6][9]=0;

  BlockPrick[7][5]=1; BlockPrick[7][9]=0; BlockPrick[7][12]=0;
  BlockPrick[7][7]=0; BlockPrick[7][10]=0; BlockPrick[7][13]=0;
  BlockPrick[7][8]=0; BlockPrick[7][11]=0; BlockPrick[7][15]=1;

  BlockPrick[8][5]=1; BlockPrick[8][10]=0; BlockPrick[8][13]=0;
  BlockPrick[8][7]=0; BlockPrick[8][11]=0; BlockPrick[8][15]=1;
  BlockPrick[8][9]=0;

  BlockPrick[9][5]=1; BlockPrick[9][10]=0; BlockPrick[9][13]=0;
  BlockPrick[9][7]=0; BlockPrick[9][11]=0; BlockPrick[9][15]=1;
  BlockPrick[9][9]=0;

  BlockPrick[10][0]=0; BlockPrick[10][7]=0; BlockPrick[10][15]=1;
  BlockPrick[10][1]=0; BlockPrick[10][9]=0; BlockPrick[10][16]=0;
  BlockPrick[10][2]=0; BlockPrick[10][10]=0; BlockPrick[10][17]=0;
  BlockPrick[10][3]=0; BlockPrick[10][11]=0; BlockPrick[10][18]=0;
  BlockPrick[10][4]=0; BlockPrick[10][13]=0; BlockPrick[10][19]=0;
  BlockPrick[10][5]=1; BlockPrick[10][14]=0; BlockPrick[10][20]=0;
  BlockPrick[10][6]=0;

  BlockPrick[11][5]=1; BlockPrick[11][13]=0; BlockPrick[11][15]=1;
  BlockPrick[11][7]=0;

  BlockPrick[12][5]=1; BlockPrick[12][9]=0; BlockPrick[12][12]=0;
  BlockPrick[12][7]=0; BlockPrick[12][10]=0; BlockPrick[12][13]=0;
  BlockPrick[12][8]=0; BlockPrick[12][11]=0; BlockPrick[12][15]=1;

  BlockPrick[13][5]=1; BlockPrick[13][13]=0; BlockPrick[13][15]=1;
  BlockPrick[13][7]=0;

  BlockPrick[14][1]=1; BlockPrick[14][7]=1; BlockPrick[14][14]=1;
  BlockPrick[14][2]=1; BlockPrick[14][8]=1; BlockPrick[14][15]=1;
  BlockPrick[14][3]=1; BlockPrick[14][9]=1; BlockPrick[14][16]=1;
  BlockPrick[14][4]=1; BlockPrick[14][11]=1; BlockPrick[14][17]=1;
  BlockPrick[14][5]=1; BlockPrick[14][12]=1; BlockPrick[14][18]=1;
  BlockPrick[14][6]=1; BlockPrick[14][13]=1; BlockPrick[14][19]=1;

  BlockPrick[15][1]=2; BlockPrick[15][9]=1; BlockPrick[15][15]=1;
  BlockPrick[15][5]=1; BlockPrick[15][11]=1; BlockPrick[15][19]=2;

  BlockPrick[16][1]=1; BlockPrick[16][8]=1; BlockPrick[16][14]=1;
  BlockPrick[16][2]=1; BlockPrick[16][9]=1; BlockPrick[16][15]=1;
  BlockPrick[16][3]=1; BlockPrick[16][10]=0; BlockPrick[16][17]=1;
  BlockPrick[16][5]=1; BlockPrick[16][11]=1; BlockPrick[16][18]=1;
  BlockPrick[16][6]=1; BlockPrick[16][12]=1; BlockPrick[16][19]=1;
  BlockPrick[16][7]=1; BlockPrick[16][13]=1;

  BlockPrick[17][3]=1; BlockPrick[17][7]=1; BlockPrick[17][15]=1;
  BlockPrick[17][5]=1; BlockPrick[17][13]=1; BlockPrick[17][17]=1;

  BlockPrick[18][1]=1; BlockPrick[18][8]=1; BlockPrick[18][15]=1;
  BlockPrick[18][2]=1; BlockPrick[18][9]=1; BlockPrick[18][16]=1;
  BlockPrick[18][3]=1; BlockPrick[18][11]=1; BlockPrick[18][17]=1;
  BlockPrick[18][4]=1; BlockPrick[18][12]=1; BlockPrick[18][18]=1;
  BlockPrick[18][5]=1; BlockPrick[18][13]=1; BlockPrick[18][19]=1;
  BlockPrick[18][7]=1;

  BlockPrick[19][1]=1; BlockPrick[19][11]=1; BlockPrick[19][19]=1;
  BlockPrick[19][9]=1;

  BlockPrick[20][1]=1; BlockPrick[20][7]=1; BlockPrick[20][13]=1;
  BlockPrick[20][2]=1; BlockPrick[20][8]=1; BlockPrick[20][14]=1;
  BlockPrick[20][3]=1; BlockPrick[20][9]=1; BlockPrick[20][15]=1;
  BlockPrick[20][4]=1; BlockPrick[20][10]=1; BlockPrick[20][16]=1;
  BlockPrick[20][5]=1; BlockPrick[20][11]=1; BlockPrick[20][17]=1;
  BlockPrick[20][6]=1; BlockPrick[20][12]=1; BlockPrick[20][18]=1;
   BlockPrick[20][19]=1;

// Nedanst†ende rad g”r s† att sp”kena bara kan g† upp genom
// mittenblocket i boet.
  BlockRikt[8][9]=12; BlockRikt[8][11]=10;
}


void Level2()
{
  Level1();

  BlockPrick[6][9]=1; BlockPrick[6][11]=1;

  BlockPrick[7][7]=1; BlockPrick[7][8]=1; BlockPrick[7][9]=1;
  BlockPrick[7][10]=1; BlockPrick[7][11]=1; BlockPrick[7][12]=1;
  BlockPrick[7][13]=1;

  BlockPrick[8][7]=1; BlockPrick[8][13]=1;

  BlockPrick[9][7]=1; BlockPrick[9][13]=1;

  BlockPrick[10][0]=1; BlockPrick[10][1]=1; BlockPrick[10][2]=1;
  BlockPrick[10][3]=1; BlockPrick[10][4]=1; BlockPrick[10][6]=1;
  BlockPrick[10][7]=1; BlockPrick[10][9]=0; BlockPrick[10][10]=0;
  BlockPrick[10][11]=0; BlockPrick[10][13]=1; BlockPrick[10][14]=1;
  BlockPrick[10][16]=1; BlockPrick[10][17]=1; BlockPrick[10][18]=1;
  BlockPrick[10][19]=1; BlockPrick[10][20]=1;

  BlockPrick[11][7]=1; BlockPrick[11][13]=1;

  BlockPrick[12][7]=1; BlockPrick[12][8]=1; BlockPrick[12][9]=1;
  BlockPrick[12][10]=1; BlockPrick[12][11]=1; BlockPrick[12][12]=1;
  BlockPrick[12][13]=1;

  BlockPrick[13][7]=1; BlockPrick[13][13]=1;
}

void Level3()
{
  Level2();

  for(char y=0;y<=LevY;y++)
    for(char x=0;x<=LevX;x++)
      BlockPos[y][x]=0;
}

void Level4()
{
  LevX=21; LevY=22;
  pacStartX=200; pacStartY=300;
  ghostStartX=200; ghostStartY=60;

BlockPos[0][0]=12; BlockPos[0][6]=16; BlockPos[0][11]=16; BlockPos[0][16]=16;
BlockPos[0][1]=16; BlockPos[0][7]=16; BlockPos[0][12]=16; BlockPos[0][17]=16;
BlockPos[0][2]=16; BlockPos[0][8]=16; BlockPos[0][13]=16; BlockPos[0][18]=16;
BlockPos[0][3]=16; BlockPos[0][9]=16; BlockPos[0][14]=16; BlockPos[0][19]=16;
BlockPos[0][4]=16; BlockPos[0][10]=16; BlockPos[0][15]=16; BlockPos[0][20]=13;
BlockPos[0][5]=16;

BlockPos[1][0]=18; BlockPos[1][6]=0; BlockPos[1][11]=0; BlockPos[1][16]=0;
BlockPos[1][1]=0; BlockPos[1][7]=0; BlockPos[1][12]=0; BlockPos[1][17]=0;
BlockPos[1][2]=0; BlockPos[1][8]=0; BlockPos[1][13]=0; BlockPos[1][18]=0;
BlockPos[1][3]=0; BlockPos[1][9]=0; BlockPos[1][14]=0; BlockPos[1][19]=0;
BlockPos[1][4]=0; BlockPos[1][10]=0; BlockPos[1][15]=0; BlockPos[1][20]=19;
BlockPos[1][5]=0;

BlockPos[2][0]=18; BlockPos[2][6]=26; BlockPos[2][11]=5; BlockPos[2][16]=39;
BlockPos[2][1]=0; BlockPos[2][7]=0; BlockPos[2][12]=2; BlockPos[2][17]=35;
BlockPos[2][2]=27; BlockPos[2][8]=1; BlockPos[2][13]=0; BlockPos[2][18]=26;
BlockPos[2][3]=39; BlockPos[2][9]=5; BlockPos[2][14]=27; BlockPos[2][19]=0;
BlockPos[2][4]=35; BlockPos[2][10]=5; BlockPos[2][15]=5; BlockPos[2][20]=19;
BlockPos[2][5]=5;

BlockPos[3][0]=18; BlockPos[3][6]=0; BlockPos[3][11]=0; BlockPos[3][16]=34;
BlockPos[3][1]=0; BlockPos[3][7]=0; BlockPos[3][12]=6; BlockPos[3][17]=28;
BlockPos[3][2]=0; BlockPos[3][8]=6; BlockPos[3][13]=0; BlockPos[3][18]=0;
BlockPos[3][3]=29; BlockPos[3][9]=0; BlockPos[3][14]=0; BlockPos[3][19]=0;
BlockPos[3][4]=32; BlockPos[3][10]=0; BlockPos[3][15]=0; BlockPos[3][20]=19;
BlockPos[3][5]=0;

BlockPos[4][0]=14; BlockPos[4][6]=25; BlockPos[4][11]=0; BlockPos[4][16]=24;
BlockPos[4][1]=31; BlockPos[4][7]=0; BlockPos[4][12]=24; BlockPos[4][17]=0;
BlockPos[4][2]=0; BlockPos[4][8]=24; BlockPos[4][13]=0; BlockPos[4][18]=0;
BlockPos[4][3]=0; BlockPos[4][9]=0; BlockPos[4][14]=25; BlockPos[4][19]=30;
BlockPos[4][4]=24; BlockPos[4][10]=0; BlockPos[4][15]=0; BlockPos[4][20]=15;
BlockPos[4][5]=0;

BlockPos[5][0]=40; BlockPos[5][6]=6; BlockPos[5][11]=0; BlockPos[5][16]=0;
BlockPos[5][1]=14; BlockPos[5][7]=0; BlockPos[5][12]=0; BlockPos[5][17]=0;
BlockPos[5][2]=31; BlockPos[5][8]=0; BlockPos[5][13]=0; BlockPos[5][18]=30;
BlockPos[5][3]=0; BlockPos[5][9]=0; BlockPos[5][14]=6; BlockPos[5][19]=15;
BlockPos[5][4]=0; BlockPos[5][10]=0; BlockPos[5][15]=0; BlockPos[5][20]=40;
BlockPos[5][5]=0;

BlockPos[6][0]=40; BlockPos[6][6]=9; BlockPos[6][11]=26; BlockPos[6][16]=26;
BlockPos[6][1]=12; BlockPos[6][7]=26; BlockPos[6][12]=0; BlockPos[6][17]=0;
BlockPos[6][2]=28; BlockPos[6][8]=0; BlockPos[6][13]=27; BlockPos[6][18]=29;
BlockPos[6][3]=0; BlockPos[6][9]=27; BlockPos[6][14]=9; BlockPos[6][19]=13;
BlockPos[6][4]=27; BlockPos[6][10]=5; BlockPos[6][15]=7; BlockPos[6][20]=40;
BlockPos[6][5]=7;

BlockPos[7][0]=12; BlockPos[7][6]=0; BlockPos[7][11]=0; BlockPos[7][16]=0;
BlockPos[7][1]=28; BlockPos[7][7]=0; BlockPos[7][12]=0; BlockPos[7][17]=0;
BlockPos[7][2]=0; BlockPos[7][8]=0; BlockPos[7][13]=0; BlockPos[7][18]=0;
BlockPos[7][3]=0; BlockPos[7][9]=0; BlockPos[7][14]=0; BlockPos[7][19]=29;
BlockPos[7][4]=0; BlockPos[7][10]=0; BlockPos[7][15]=24; BlockPos[7][20]=13;
BlockPos[7][5]=24;

BlockPos[8][0]=18; BlockPos[8][6]=0; BlockPos[8][11]=27; BlockPos[8][16]=0;
BlockPos[8][1]=0; BlockPos[8][7]=27; BlockPos[8][12]=5; BlockPos[8][17]=25;
BlockPos[8][2]=0; BlockPos[8][8]=5; BlockPos[8][13]=26; BlockPos[8][18]=0;
BlockPos[8][3]=25; BlockPos[8][9]=26; BlockPos[8][14]=0; BlockPos[8][19]=0;
BlockPos[8][4]=0; BlockPos[8][10]=0; BlockPos[8][15]=0; BlockPos[8][20]=19;
BlockPos[8][5]=0;

BlockPos[9][0]=18; BlockPos[9][6]=0; BlockPos[9][11]=0; BlockPos[9][16]=0;
BlockPos[9][1]=0; BlockPos[9][7]=0; BlockPos[9][12]=0; BlockPos[9][17]=38;
BlockPos[9][2]=30; BlockPos[9][8]=0; BlockPos[9][13]=0; BlockPos[9][18]=31;
BlockPos[9][3]=36; BlockPos[9][9]=0; BlockPos[9][14]=0; BlockPos[9][19]=0;
BlockPos[9][4]=0; BlockPos[9][10]=0; BlockPos[9][15]=25; BlockPos[9][20]=19;
BlockPos[9][5]=25;

BlockPos[10][0]=18; BlockPos[10][6]=2; BlockPos[10][11]=0; BlockPos[10][16]=0;
BlockPos[10][1]=0; BlockPos[10][7]=0; BlockPos[10][12]=25; BlockPos[10][17]=19;
BlockPos[10][2]=19; BlockPos[10][8]=25; BlockPos[10][13]=0; BlockPos[10][18]=18;
BlockPos[10][3]=18; BlockPos[10][9]=0; BlockPos[10][14]=1; BlockPos[10][19]=0;
BlockPos[10][4]=0; BlockPos[10][10]=25; BlockPos[10][15]=4; BlockPos[10][20]=19;
BlockPos[10][5]=3;

BlockPos[11][0]=18; BlockPos[11][6]=24; BlockPos[11][11]=0; BlockPos[11][16]=0;
BlockPos[11][1]=0; BlockPos[11][7]=0; BlockPos[11][12]=6; BlockPos[11][17]=19;
BlockPos[11][2]=19; BlockPos[11][8]=6; BlockPos[11][13]=0; BlockPos[11][18]=18;
BlockPos[11][3]=18; BlockPos[11][9]=0; BlockPos[11][14]=24; BlockPos[11][19]=0;
BlockPos[11][4]=0; BlockPos[11][10]=6; BlockPos[11][15]=0; BlockPos[11][20]=19;
BlockPos[11][5]=0;

BlockPos[12][0]=18; BlockPos[12][6]=0; BlockPos[12][11]=0; BlockPos[12][16]=30;
BlockPos[12][1]=0; BlockPos[12][7]=0; BlockPos[12][12]=24; BlockPos[12][17]=15;
BlockPos[12][2]=19; BlockPos[12][8]=24; BlockPos[12][13]=0; BlockPos[12][18]=18;
BlockPos[12][3]=14; BlockPos[12][9]=0; BlockPos[12][14]=0; BlockPos[12][19]=0;
BlockPos[12][4]=31; BlockPos[12][10]=24; BlockPos[12][15]=0; BlockPos[12][20]=19;
BlockPos[12][5]=0;

BlockPos[13][0]=18; BlockPos[13][6]=25; BlockPos[13][11]=0; BlockPos[13][16]=29;
BlockPos[13][1]=0; BlockPos[13][7]=0; BlockPos[13][12]=0; BlockPos[13][17]=16;
BlockPos[13][2]=29; BlockPos[13][8]=0; BlockPos[13][13]=0; BlockPos[13][18]=28;
BlockPos[13][3]=16; BlockPos[13][9]=0; BlockPos[13][14]=25; BlockPos[13][19]=0;
BlockPos[13][4]=28; BlockPos[13][10]=0; BlockPos[13][15]=0; BlockPos[13][20]=19;
BlockPos[13][5]=0;

BlockPos[14][0]=18; BlockPos[14][6]=3; BlockPos[14][11]=27; BlockPos[14][16]=0;
BlockPos[14][1]=0; BlockPos[14][7]=5; BlockPos[14][12]=5; BlockPos[14][17]=0;
BlockPos[14][2]=0; BlockPos[14][8]=5; BlockPos[14][13]=5; BlockPos[14][18]=0;
BlockPos[14][3]=0; BlockPos[14][9]=26; BlockPos[14][14]=4; BlockPos[14][19]=0;
BlockPos[14][4]=0; BlockPos[14][10]=0; BlockPos[14][15]=0; BlockPos[14][20]=19;
BlockPos[14][5]=0;

BlockPos[15][0]=22; BlockPos[15][6]=0; BlockPos[15][11]=0; BlockPos[15][16]=25;
BlockPos[15][1]=5; BlockPos[15][7]=0; BlockPos[15][12]=0; BlockPos[15][17]=0;
BlockPos[15][2]=26; BlockPos[15][8]=0; BlockPos[15][13]=0; BlockPos[15][18]=27;
BlockPos[15][3]=0; BlockPos[15][9]=0; BlockPos[15][14]=0; BlockPos[15][19]=5;
BlockPos[15][4]=25; BlockPos[15][10]=0; BlockPos[15][15]=0; BlockPos[15][20]=23;
BlockPos[15][5]=0;

BlockPos[16][0]=18; BlockPos[16][6]=0; BlockPos[16][11]=0; BlockPos[16][16]=4;
BlockPos[16][1]=0; BlockPos[16][7]=27; BlockPos[16][12]=1; BlockPos[16][17]=0;
BlockPos[16][2]=0; BlockPos[16][8]=2; BlockPos[16][13]=26; BlockPos[16][18]=0;
BlockPos[16][3]=0; BlockPos[16][9]=0; BlockPos[16][14]=0; BlockPos[16][19]=0;
BlockPos[16][4]=3; BlockPos[16][10]=25; BlockPos[16][15]=27; BlockPos[16][20]=19;
BlockPos[16][5]=26;

BlockPos[17][0]=18; BlockPos[17][6]=0; BlockPos[17][11]=0; BlockPos[17][16]=0;
BlockPos[17][1]=0; BlockPos[17][7]=0; BlockPos[17][12]=6; BlockPos[17][17]=0;
BlockPos[17][2]=25; BlockPos[17][8]=6; BlockPos[17][13]=0; BlockPos[17][18]=25;
BlockPos[17][3]=0; BlockPos[17][9]=0; BlockPos[17][14]=0; BlockPos[17][19]=0;
BlockPos[17][4]=0; BlockPos[17][10]=6; BlockPos[17][15]=0; BlockPos[17][20]=19;
BlockPos[17][5]=0;

BlockPos[18][0]=18; BlockPos[18][6]=25; BlockPos[18][11]=0; BlockPos[18][16]=25;
BlockPos[18][1]=0; BlockPos[18][7]=0; BlockPos[18][12]=24; BlockPos[18][17]=0;
BlockPos[18][2]=6; BlockPos[18][8]=24; BlockPos[18][13]=0; BlockPos[18][18]=6;
BlockPos[18][3]=0; BlockPos[18][9]=0; BlockPos[18][14]=25; BlockPos[18][19]=0;
BlockPos[18][4]=25; BlockPos[18][10]=6; BlockPos[18][15]=0; BlockPos[18][20]=19;
BlockPos[18][5]=0;

BlockPos[19][0]=18; BlockPos[19][6]=24; BlockPos[19][11]=0; BlockPos[19][16]=6;
BlockPos[19][1]=0; BlockPos[19][7]=0; BlockPos[19][12]=0; BlockPos[19][17]=0;
BlockPos[19][2]=24; BlockPos[19][8]=0; BlockPos[19][13]=0; BlockPos[19][18]=24;
BlockPos[19][3]=0; BlockPos[19][9]=0; BlockPos[19][14]=24; BlockPos[19][19]=0;
BlockPos[19][4]=6; BlockPos[19][10]=24; BlockPos[19][15]=0; BlockPos[19][20]=19;
BlockPos[19][5]=0;

BlockPos[20][0]=18; BlockPos[20][6]=0; BlockPos[20][11]=0; BlockPos[20][16]=6;
BlockPos[20][1]=0; BlockPos[20][7]=0; BlockPos[20][12]=25; BlockPos[20][17]=0;
BlockPos[20][2]=0; BlockPos[20][8]=25; BlockPos[20][13]=0; BlockPos[20][18]=0;
BlockPos[20][3]=0; BlockPos[20][9]=0; BlockPos[20][14]=0; BlockPos[20][19]=0;
BlockPos[20][4]=6; BlockPos[20][10]=0; BlockPos[20][15]=0; BlockPos[20][20]=19;
BlockPos[20][5]=0;

BlockPos[21][0]=14; BlockPos[21][6]=17; BlockPos[21][11]=17; BlockPos[21][16]=21;
BlockPos[21][1]=17; BlockPos[21][7]=17; BlockPos[21][12]=21; BlockPos[21][17]=17;
BlockPos[21][2]=17; BlockPos[21][8]=21; BlockPos[21][13]=17; BlockPos[21][18]=17;
BlockPos[21][3]=17; BlockPos[21][9]=17; BlockPos[21][14]=17; BlockPos[21][19]=17;
BlockPos[21][4]=21; BlockPos[21][10]=17; BlockPos[21][15]=17; BlockPos[21][20]=15;
BlockPos[21][5]=17;


  BlockRikt[1][1]=12; BlockRikt[1][7]=14; BlockRikt[1][13]=14; BlockRikt[1][19]=10;
  BlockRikt[1][2]=6; BlockRikt[1][8]=6; BlockRikt[1][14]=6;
  BlockRikt[1][3]=6; BlockRikt[1][9]=6; BlockRikt[1][15]=6;
  BlockRikt[1][4]=6; BlockRikt[1][10]=6; BlockRikt[1][16]=6;
  BlockRikt[1][5]=6; BlockRikt[1][11]=6; BlockRikt[1][17]=6;
  BlockRikt[1][6]=6; BlockRikt[1][12]=6; BlockRikt[1][18]=6;

  BlockRikt[2][1]=9; BlockRikt[2][13]=9;
  BlockRikt[2][7]=9; BlockRikt[2][19]=9;

  BlockRikt[3][1]=5; BlockRikt[3][11]=10;
  BlockRikt[3][2]=10; BlockRikt[3][13]=13;
  BlockRikt[3][5]=12; BlockRikt[3][14]=6;
  BlockRikt[3][6]=6; BlockRikt[3][15]=10;
  BlockRikt[3][7]=11; BlockRikt[3][18]=12;
  BlockRikt[3][9]=12; BlockRikt[3][19]=3;
  BlockRikt[3][10]=14;

  BlockRikt[4][2]=5; BlockRikt[4][9]=13; BlockRikt[4][15]=9;
  BlockRikt[4][3]=10; BlockRikt[4][10]=15; BlockRikt[4][17]=12;
  BlockRikt[4][5]=9; BlockRikt[4][11]=11; BlockRikt[4][18]=3;
  BlockRikt[4][7]=9; BlockRikt[4][13]=9;

  BlockRikt[5][3]=13; BlockRikt[5][10]=6; BlockRikt[5][16]=6;
  BlockRikt[5][4]=6; BlockRikt[5][11]=6; BlockRikt[5][17]=11;
  BlockRikt[5][5]=3; BlockRikt[5][12]=14;
  BlockRikt[5][7]=5; BlockRikt[5][13]=3;
  BlockRikt[5][8]=14; BlockRikt[5][15]=5;
  BlockRikt[5][9]=6;

  BlockRikt[6][3]=9; BlockRikt[6][12]=9; BlockRikt[6][17]=9;
  BlockRikt[6][8]=9;

  BlockRikt[7][2]=12; BlockRikt[7][8]=7; BlockRikt[7][13]=6;
  BlockRikt[7][3]=7; BlockRikt[7][9]=6; BlockRikt[7][14]=10;
  BlockRikt[7][4]=10; BlockRikt[7][10]=14; BlockRikt[7][16]=12;
  BlockRikt[7][6]=12; BlockRikt[7][11]=6; BlockRikt[7][17]=7;
  BlockRikt[7][7]=6; BlockRikt[7][12]=7; BlockRikt[7][18]=10;

  BlockRikt[8][1]=12; BlockRikt[8][6]=11; BlockRikt[8][16]=11;
  BlockRikt[8][2]=3; BlockRikt[8][10]=9; BlockRikt[8][18]=5;
  BlockRikt[8][4]=13; BlockRikt[8][14]=13; BlockRikt[8][19]=10;
  BlockRikt[8][5]=6; BlockRikt[8][15]=6;

  BlockRikt[9][1]=9; BlockRikt[9][9]=14; BlockRikt[9][13]=14;
  BlockRikt[9][4]=9; BlockRikt[9][10]=7; BlockRikt[9][14]=3;
  BlockRikt[9][6]=5; BlockRikt[9][11]=14; BlockRikt[9][16]=9;
  BlockRikt[9][7]=14; BlockRikt[9][12]=6; BlockRikt[9][19]=9;
  BlockRikt[9][8]=6;

  BlockRikt[10][1]=9; BlockRikt[10][9]=9; BlockRikt[10][16]=9;
  BlockRikt[10][4]=9; BlockRikt[10][11]=9; BlockRikt[10][19]=9;
  BlockRikt[10][7]=9; BlockRikt[10][13]=9;

  BlockRikt[11][1]=9; BlockRikt[11][9]=9; BlockRikt[11][15]=12;
  BlockRikt[11][4]=5; BlockRikt[11][11]=9; BlockRikt[11][16]=3;
  BlockRikt[11][5]=10; BlockRikt[11][13]=9; BlockRikt[11][19]=9;
  BlockRikt[11][7]=9;

  BlockRikt[12][1]=9; BlockRikt[12][9]=9; BlockRikt[12][14]=6;
  BlockRikt[12][5]=13; BlockRikt[12][11]=9; BlockRikt[12][15]=11;
  BlockRikt[12][6]=6; BlockRikt[12][13]=13; BlockRikt[12][19]=9;
  BlockRikt[12][7]=11;

  BlockRikt[13][1]=9; BlockRikt[13][9]=7; BlockRikt[13][13]=3;
  BlockRikt[13][5]=9; BlockRikt[13][10]=14; BlockRikt[13][15]=9;
  BlockRikt[13][7]=5; BlockRikt[13][11]=7; BlockRikt[13][19]=9;
  BlockRikt[13][8]=6; BlockRikt[13][12]=6;

  BlockRikt[14][1]=5; BlockRikt[14][5]=11; BlockRikt[14][17]=14;
  BlockRikt[14][2]=6; BlockRikt[14][10]=9; BlockRikt[14][18]=6;
  BlockRikt[14][3]=14; BlockRikt[14][15]=13; BlockRikt[14][19]=3;
  BlockRikt[14][4]=6; BlockRikt[14][16]=6;

  BlockRikt[15][3]=9; BlockRikt[15][9]=14; BlockRikt[15][13]=6;
  BlockRikt[15][5]=5; BlockRikt[15][10]=7; BlockRikt[15][14]=14;
  BlockRikt[15][6]=14; BlockRikt[15][11]=14; BlockRikt[15][15]=3;
  BlockRikt[15][7]=6; BlockRikt[15][12]=6; BlockRikt[15][17]=9;
  BlockRikt[15][8]=6;

  BlockRikt[16][1]=12; BlockRikt[16][9]=9; BlockRikt[16][17]=13;
  BlockRikt[16][2]=6; BlockRikt[16][11]=9; BlockRikt[16][18]=6;
  BlockRikt[16][3]=11; BlockRikt[16][14]=9; BlockRikt[16][19]=10;
  BlockRikt[16][6]=9;

  BlockRikt[17][1]=9; BlockRikt[17][7]=10; BlockRikt[17][15]=14;
  BlockRikt[17][3]=13; BlockRikt[17][9]=9; BlockRikt[17][16]=6;
  BlockRikt[17][4]=6; BlockRikt[17][11]=9; BlockRikt[17][17]=11;
  BlockRikt[17][5]=14; BlockRikt[17][13]=12; BlockRikt[17][19]=9;
  BlockRikt[17][6]=7; BlockRikt[17][14]=7;

  BlockRikt[18][1]=9; BlockRikt[18][9]=9; BlockRikt[18][15]=9;
  BlockRikt[18][3]=9; BlockRikt[18][11]=9; BlockRikt[18][17]=9;
  BlockRikt[18][5]=9; BlockRikt[18][13]=9; BlockRikt[18][19]=9;
  BlockRikt[18][7]=9;

  BlockRikt[19][1]=9; BlockRikt[19][8]=6; BlockRikt[19][13]=11;
  BlockRikt[19][3]=9; BlockRikt[19][9]=11; BlockRikt[19][15]=9;
  BlockRikt[19][5]=9; BlockRikt[19][11]=13; BlockRikt[19][17]=9;
  BlockRikt[19][7]=13; BlockRikt[19][12]=6; BlockRikt[19][19]=9;

  BlockRikt[20][1]=5; BlockRikt[20][7]=3; BlockRikt[20][14]=6;
  BlockRikt[20][2]=6; BlockRikt[20][9]=5; BlockRikt[20][15]=3;
  BlockRikt[20][3]=3; BlockRikt[20][10]=6; BlockRikt[20][17]=5;
  BlockRikt[20][5]=5; BlockRikt[20][11]=3; BlockRikt[20][18]=6;
  BlockRikt[20][6]=6; BlockRikt[20][13]=5; BlockRikt[20][19]=3;

// *************************************************************************

  BlockPrick[1][1]=1; BlockPrick[1][8]=1; BlockPrick[1][14]=1;
  BlockPrick[1][2]=1; BlockPrick[1][9]=1; BlockPrick[1][15]=1;
  BlockPrick[1][3]=1; BlockPrick[1][10]=1; BlockPrick[1][16]=1;
  BlockPrick[1][4]=1; BlockPrick[1][11]=1; BlockPrick[1][17]=1;
  BlockPrick[1][5]=1; BlockPrick[1][12]=1; BlockPrick[1][18]=1;
  BlockPrick[1][6]=1; BlockPrick[1][13]=1; BlockPrick[1][19]=1;
  BlockPrick[1][7]=1;

  BlockPrick[2][1]=1; BlockPrick[2][13]=1;
  BlockPrick[2][7]=1; BlockPrick[2][19]=1;

  BlockPrick[3][1]=1; BlockPrick[3][13]=1;
  BlockPrick[3][2]=1; BlockPrick[3][14]=1;
  BlockPrick[3][5]=1; BlockPrick[3][15]=1;
  BlockPrick[3][6]=1; BlockPrick[3][18]=1;
  BlockPrick[3][7]=1; BlockPrick[3][19]=1;

  BlockPrick[3][9]=0; BlockPrick[3][10]=0; BlockPrick[3][11]=0;

  BlockPrick[4][2]=2; BlockPrick[4][7]=1; BlockPrick[4][17]=1;
  BlockPrick[4][3]=1; BlockPrick[4][13]=1; BlockPrick[4][18]=2;
  BlockPrick[4][5]=1; BlockPrick[4][15]=1;

  BlockPrick[4][9]=0; BlockPrick[4][10]=0; BlockPrick[4][11]=0;

  //******

  BlockPrick[5][3]=1; BlockPrick[5][9]=1; BlockPrick[5][13]=1;
  BlockPrick[5][4]=1; BlockPrick[5][10]=1; BlockPrick[5][15]=1;
  BlockPrick[5][5]=1; BlockPrick[5][11]=1; BlockPrick[5][16]=1;
  BlockPrick[5][7]=1; BlockPrick[5][12]=1; BlockPrick[5][17]=1;
  BlockPrick[5][8]=1;

  BlockPrick[6][3]=1; BlockPrick[6][12]=1; BlockPrick[6][17]=1;
  BlockPrick[6][8]=1;

  BlockPrick[7][2]=1; BlockPrick[7][8]=1; BlockPrick[7][13]=1;
  BlockPrick[7][3]=1; BlockPrick[7][9]=1; BlockPrick[7][14]=1;
  BlockPrick[7][4]=1; BlockPrick[7][10]=1; BlockPrick[7][16]=1;
  BlockPrick[7][6]=1; BlockPrick[7][11]=1; BlockPrick[7][17]=1;
  BlockPrick[7][7]=1; BlockPrick[7][12]=1; BlockPrick[7][18]=1;

  BlockPrick[8][1]=1; BlockPrick[8][6]=1; BlockPrick[8][16]=1;
  BlockPrick[8][2]=1; BlockPrick[8][10]=1; BlockPrick[8][18]=1;
  BlockPrick[8][4]=1; BlockPrick[8][14]=1; BlockPrick[8][19]=1;
  BlockPrick[8][5]=1; BlockPrick[8][15]=1;

  BlockPrick[9][1]=1; BlockPrick[9][9]=1; BlockPrick[9][13]=1;
  BlockPrick[9][4]=1; BlockPrick[9][10]=1; BlockPrick[9][14]=1;
  BlockPrick[9][6]=1; BlockPrick[9][11]=1; BlockPrick[9][16]=1;
  BlockPrick[9][7]=1; BlockPrick[9][12]=1; BlockPrick[9][19]=1;
  BlockPrick[9][8]=1;

  BlockPrick[10][1]=1; BlockPrick[10][9]=1; BlockPrick[10][16]=1;
  BlockPrick[10][4]=1; BlockPrick[10][11]=1; BlockPrick[10][19]=1;
  BlockPrick[10][7]=1; BlockPrick[10][13]=1;

  BlockPrick[11][1]=1; BlockPrick[11][9]=1; BlockPrick[11][15]=1;
  BlockPrick[11][4]=1; BlockPrick[11][11]=1; BlockPrick[11][16]=1;
  BlockPrick[11][5]=1; BlockPrick[11][13]=1; BlockPrick[11][19]=1;
  BlockPrick[11][7]=1;

  BlockPrick[12][1]=1; BlockPrick[12][9]=1; BlockPrick[12][14]=1;
  BlockPrick[12][5]=1; BlockPrick[12][11]=1; BlockPrick[12][15]=1;
  BlockPrick[12][6]=1; BlockPrick[12][13]=1; BlockPrick[12][19]=1;
  BlockPrick[12][7]=1;

  BlockPrick[13][1]=1; BlockPrick[13][9]=1; BlockPrick[13][13]=1;
  BlockPrick[13][5]=1; BlockPrick[13][10]=1; BlockPrick[13][15]=1;
  BlockPrick[13][7]=1; BlockPrick[13][11]=1; BlockPrick[13][19]=1;
  BlockPrick[13][8]=1; BlockPrick[13][12]=1;

  BlockPrick[14][1]=1; BlockPrick[14][5]=1; BlockPrick[14][17]=1;
  BlockPrick[14][2]=1; BlockPrick[14][10]=1; BlockPrick[14][18]=1;
  BlockPrick[14][3]=1; BlockPrick[14][15]=1; BlockPrick[14][19]=1;
  BlockPrick[14][4]=1; BlockPrick[14][16]=1;

  BlockPrick[15][3]=1; BlockPrick[15][9]=1; BlockPrick[15][13]=1;
  BlockPrick[15][5]=1; BlockPrick[15][10]=1; BlockPrick[15][14]=1;
  BlockPrick[15][6]=1; BlockPrick[15][11]=1; BlockPrick[15][15]=1;
  BlockPrick[15][7]=1; BlockPrick[15][12]=1; BlockPrick[15][17]=1;
  BlockPrick[15][8]=1;

  BlockPrick[16][1]=1; BlockPrick[16][9]=1; BlockPrick[16][17]=1;
  BlockPrick[16][2]=1; BlockPrick[16][11]=1; BlockPrick[16][18]=1;
  BlockPrick[16][3]=1; BlockPrick[16][14]=1; BlockPrick[16][19]=1;
  BlockPrick[16][6]=1;

  BlockPrick[17][1]=1; BlockPrick[17][7]=1; BlockPrick[17][15]=1;
  BlockPrick[17][3]=1; BlockPrick[17][9]=1; BlockPrick[17][16]=1;
  BlockPrick[17][4]=1; BlockPrick[17][11]=1; BlockPrick[17][17]=1;
  BlockPrick[17][5]=1; BlockPrick[17][13]=1; BlockPrick[17][19]=1;
  BlockPrick[17][6]=1; BlockPrick[17][14]=1;

  BlockPrick[18][1]=1; BlockPrick[18][9]=1; BlockPrick[18][15]=1;
  BlockPrick[18][3]=1; BlockPrick[18][11]=1; BlockPrick[18][17]=1;
  BlockPrick[18][5]=1; BlockPrick[18][13]=1; BlockPrick[18][19]=1;
  BlockPrick[18][7]=1;

  BlockPrick[19][1]=1; BlockPrick[19][8]=1; BlockPrick[19][13]=1;
  BlockPrick[19][3]=1; BlockPrick[19][9]=1; BlockPrick[19][15]=1;
  BlockPrick[19][5]=1; BlockPrick[19][11]=1; BlockPrick[19][17]=1;
  BlockPrick[19][7]=1; BlockPrick[19][12]=1; BlockPrick[19][19]=1;

  BlockPrick[20][1]=1; BlockPrick[20][7]=1; BlockPrick[20][14]=1;
  BlockPrick[20][2]=2; BlockPrick[20][9]=1; BlockPrick[20][15]=1;
  BlockPrick[20][3]=1; BlockPrick[20][10]=1; BlockPrick[20][17]=1;
  BlockPrick[20][5]=1; BlockPrick[20][11]=1; BlockPrick[20][18]=2;
  BlockPrick[20][6]=1; BlockPrick[20][13]=1; BlockPrick[20][19]=1;
}

void Level5()
{
  Level4();

  for(char y=0;y<=LevY;y++)
    for(char x=0;x<=LevX;x++)
      BlockPos[y][x]=0;
}

void Level6()
{
  int x,y;
  LevX=21; LevY=22;
  pacStartX=200; pacStartY=300;
  ghostStartX=200; ghostStartY=60;

  BlockPos[0][0]=12;  BlockPos[0][20]=13;
  BlockPos[21][0]=14; BlockPos[21][20]=15;

  for(x=1;x<20;x++)
  {
    BlockPos[0][x]=16;
    BlockPos[21][x]=17;
  }

  for(y=1;y<21;y++)
  {
    BlockPos[y][0]=18;
    BlockPos[y][20]=19;
  }

  for(y=1;y<21;y++)
    for(x=1;x<20;x++)
      BlockPos[y][x]=0;

  BlockRikt[1][1]=12; BlockRikt[1][19]=10;
  BlockRikt[20][1]=5; BlockRikt[20][19]=3;

  for(x=2;x<18;x++)
  {
    BlockRikt[1][x]=14;
    BlockRikt[20][x]=7;
  }

  for(y=2;y<19;y++)
  {
    BlockRikt[y][1]=13;
    BlockRikt[y][19]=11;
  }

  for(y=2;y<20;y++)
    for(x=2;x<19;x++)
      BlockRikt[y][x]=15;

  for(y=1;y<21;y++)
    for(x=1;x<20;x++)
      BlockPrick[y][x]=1;

  BlockPrick[random(19)+1][random(18)+1]=2;
  BlockPrick[random(19)+1][random(18)+1]=2;
  BlockPrick[random(19)+1][random(18)+1]=2;
}
