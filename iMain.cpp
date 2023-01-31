# include "iGraphics.h"
#include<math.h>
#include<stdlib.h>
#include<string.h>

int start=0, N, i, r, g, b, term=0, Last=0, moves, score, Max, score_call, pixel, mode=0, easy=0, music=1, sec=0, minu=0, hr=0;
char str[10], tim[10];

struct point
{
    int x, y;
};

struct color
{
    int r, g, b;
};

typedef struct point pt;
typedef struct color color;

pt p[100], temp1, temp2;
color music_on, music_off, easy_on, easy_off;

void pointxy(int N)
{
    int i, j, t=r*N*N/255;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(t==N*N) t=0;
            p[t]={0+j*pixel,(N-i-1)*pixel};
            t++;
        }
    }
}

void color_set()
{
    if(easy)
    {
        easy_on={150, 0, 0};
        easy_off={0, 0, 100};
    }
    else
    {
        easy_on={0, 0, 100};
        easy_off={150, 0, 0};
    }
    if(music)
    {
        music_on={150, 0, 0};
        music_off={0, 0, 100};
    }
    else
    {
        music_on={0, 0, 100};
        music_off={150, 0, 0};
    }
}

int fscore()
{
    int maximum=0;
    FILE *fp;
    char filename[50];
    if(easy)
    {
        if(start==1) strcpy(filename,"Files/file1_easy.txt");
        if(start==2) strcpy(filename,"Files/file2_easy.txt");
        if(start==3) strcpy(filename,"Files/file3_easy.txt");
    }
    else
    {
        if(start==1) strcpy(filename,"Files/file1.txt");
        if(start==2) strcpy(filename,"Files/file2.txt");
        if(start==3) strcpy(filename,"Files/file3.txt");
    }
    fp=fopen(filename, "r");
    if(fp==NULL)
    {
        printf("%s File does not exist.", filename);
        return 0;
    }
    fscanf(fp, "%d", &maximum);
    fclose(fp);
    if(maximum<score)
    {
        maximum=score;
        fp=fopen(filename, "w");
        fprintf(fp, "%d", maximum);
        fclose(fp);
    }
    score_call=1;
    return maximum;
}

void puzzle0()
{
    score=1000;
    moves=0;
    score_call=0;
    iSetColor(255,0,0);
    iText(245, 530, "PUZZLE!!!", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,0,100);
    iFilledRectangle(100, 430, 400, 60);
    iFilledRectangle(100, 340, 400, 60);
    iFilledRectangle(100, 250, 400, 60);
    iFilledRectangle(100, 160, 400, 60);
    iFilledRectangle(100, 70, 400, 60);
    iSetColor(255,255,0);
    iText(275, 455, "EASY", GLUT_BITMAP_HELVETICA_18);
    iText(260, 365, "MEDIUM", GLUT_BITMAP_HELVETICA_18);
    iText(275, 275, "HARD", GLUT_BITMAP_HELVETICA_18);
    iText(250, 185, "SETTINGS", GLUT_BITMAP_HELVETICA_18);
    iText(275, 95, "EXIT", GLUT_BITMAP_HELVETICA_18);
    mode=0;
}

void puzzle1()
{
    iShowBMP(p[1].x, p[1].y, "Images/3.bmp");
    iShowBMP(p[2].x, p[2].y, "Images/8.bmp");
    iShowBMP(p[3].x, p[3].y, "Images/1.bmp");
    iShowBMP(p[4].x, p[4].y, "Images/5.bmp");
    iShowBMP(p[5].x, p[5].y, "Images/7.bmp");
    iShowBMP(p[6].x, p[6].y, "Images/2.bmp");
    iShowBMP(p[7].x, p[7].y, "Images/4.bmp");
    iShowBMP(p[8].x, p[8].y, "Images/6.bmp");
    iSetColor(100,100,255);
    iLine(200, 0, 200, 600);
    iLine(400, 0, 400, 600);
    iLine(0, 200, 600, 200);
    iLine(0, 400, 600, 400);
    iSetColor(0,0,255);
    iText(620, 60, "Press B for home.", GLUT_BITMAP_9_BY_15);
    mode=1;
    if(p[3].x==200&&p[3].y==400&&p[6].x==400&&p[6].y==400&&p[1].x==0&&p[1].y==200&&p[7].x==200&&p[7].y==200
       &&p[4].x==400&&p[4].y==200&&p[8].x==0&&p[8].y==0&&p[5].x==200&&p[5].y==0&&p[2].x==400&&p[2].y==0)
        Last=1;
}

void puzzle2()
{
    iShowBMP(p[1].x, p[1].y, "Images/7-1.bmp");
    iShowBMP(p[2].x, p[2].y, "Images/9-1.bmp");
    iShowBMP(p[3].x, p[3].y, "Images/1-1.bmp");
    iShowBMP(p[4].x, p[4].y, "Images/13-1.bmp");
    iShowBMP(p[5].x, p[5].y, "Images/8-1.bmp");
    iShowBMP(p[6].x, p[6].y, "Images/15-1.bmp");
    iShowBMP(p[7].x, p[7].y, "Images/11-1.bmp");
    iShowBMP(p[8].x, p[8].y, "Images/3-1.bmp");
    iShowBMP(p[9].x, p[9].y, "Images/2-1.bmp");
    iShowBMP(p[10].x, p[10].y, "Images/10-1.bmp");
    iShowBMP(p[11].x, p[11].y, "Images/5-1.bmp");
    iShowBMP(p[12].x, p[12].y, "Images/4-1.bmp");
    iShowBMP(p[13].x, p[13].y, "Images/14-1.bmp");
    iShowBMP(p[14].x, p[14].y, "Images/12-1.bmp");
    iShowBMP(p[15].x, p[15].y, "Images/6-1.bmp");
    iSetColor(100,100,255);
    iLine(150, 0, 150, 600);
    iLine(300, 0, 300, 600);
    iLine(0, 150, 600, 150);
    iLine(0, 300, 600, 300);
    iLine(0, 450, 600, 450);
    iLine(450, 0, 450, 600);
    iSetColor(0,0,255);
    iText(620, 60, "Press B for home.", GLUT_BITMAP_9_BY_15);
    mode=1;
    if(p[3].x==150&&p[3].y==450&&p[9].x==300&&p[9].y==450&&p[8].x==450&&p[8].y==450&&p[12].x==0&&p[12].y==300&&
       p[11].x==150&&p[11].y==300&&p[15].x==300&&p[15].y==300&&p[1].x==450&&p[1].y==300&&p[5].x==0&&p[5].y==150&&
       p[2].x==150&&p[2].y==150&&p[10].x==300&&p[10].y==150&&p[7].x==450&&p[7].y==150&&p[14].x==0&&p[14].y==0&&
       p[4].x==150&&p[4].y==0&&p[13].x==300&&p[13].y==0&&p[6].x==450&&p[6].y==0)
        Last=1;
}

void puzzle3()
{
    iShowBMP(p[1].x, p[1].y, "Images/5-2.bmp");
    iShowBMP(p[2].x, p[2].y, "Images/20-2.bmp");
    iShowBMP(p[3].x, p[3].y, "Images/8-2.bmp");
    iShowBMP(p[4].x, p[4].y, "Images/14-2.bmp");
    iShowBMP(p[5].x, p[5].y, "Images/6-2.bmp");
    iShowBMP(p[6].x, p[6].y, "Images/15-2.bmp");
    iShowBMP(p[7].x, p[7].y, "Images/19-2.bmp");
    iShowBMP(p[8].x, p[8].y, "Images/3-2.bmp");
    iShowBMP(p[9].x, p[9].y, "Images/7-2.bmp");
    iShowBMP(p[10].x, p[10].y, "Images/1-2.bmp");
    iShowBMP(p[11].x, p[11].y, "Images/16-2.bmp");
    iShowBMP(p[12].x, p[12].y, "Images/11-2.bmp");
    iShowBMP(p[13].x, p[13].y, "Images/23-2.bmp");
    iShowBMP(p[14].x, p[14].y, "Images/21-2.bmp");
    iShowBMP(p[15].x, p[15].y, "Images/9-2.bmp");
    iShowBMP(p[16].x, p[16].y, "Images/13-2.bmp");
    iShowBMP(p[17].x, p[17].y, "Images/18-2.bmp");
    iShowBMP(p[18].x, p[18].y, "Images/4-2.bmp");
    iShowBMP(p[19].x, p[19].y, "Images/22-2.bmp");
    iShowBMP(p[20].x, p[20].y, "Images/12-2.bmp");
    iShowBMP(p[21].x, p[21].y, "Images/17-2.bmp");
    iShowBMP(p[22].x, p[22].y, "Images/10-2.bmp");
    iShowBMP(p[23].x, p[23].y, "Images/24-2.bmp");
    iShowBMP(p[24].x, p[24].y, "Images/2-2.bmp");
    iSetColor(100,100,255);
    iLine(120, 0, 120, 600);
    iLine(240, 0, 240, 600);
    iLine(0, 120, 600, 120);
    iLine(0, 240, 600, 240);
    iLine(0, 480, 600, 480);
    iLine(480, 0, 480, 600);
    iLine(0, 360, 600, 360);
    iLine(360, 0, 360, 600);
    iSetColor(0,0,255);
    iText(620, 60, "Press B for home.", GLUT_BITMAP_9_BY_15);
    mode=1;
       /*p[10].x=120;p[10].y=480;p[24].x=240;p[24].y=480;p[8].x=360;p[8].y=480;p[18].x=480;p[18].y=480;p[1].x=0;p[1].y=360;
       p[5].x=120;p[5].y=360;p[9].x=240;p[9].y=360;p[3].x=360;p[3].y=360;p[15].x=480;p[15].y=360;p[22].x=0;p[22].y=240;
       p[12].x=120;p[12].y=240;p[20].x=240;p[20].y=240;p[16].x=360;p[16].y=240;p[4].x=480;p[4].y=240;p[6].x=0;p[6].y=120;
       p[11].x=120;p[11].y=120;p[21].x=240;p[21].y=120;p[17].x=360;p[17].y=120;p[7].x=480;p[7].y=120;p[2].x=0;p[2].y=0;
       p[14].x=120;p[14].y=0;p[19].x=240;p[19].y=0;p[13].x=360;p[13].y=0;p[23].x=480;p[23].y=0;*/
    if(p[10].x==120&&p[10].y==480&&p[24].x==240&&p[24].y==480&&p[8].x==360&&p[8].y==480&&p[18].x==480&&p[18].y==480&&p[1].x==0&&p[1].y==360&&
       p[5].x==120&&p[5].y==360&&p[9].x==240&&p[9].y==360&&p[3].x==360&&p[3].y==360&&p[15].x==480&&p[15].y==360&&p[22].x==0&&p[22].y==240&&
       p[12].x==120&&p[12].y==240&&p[20].x==240&&p[20].y==240&&p[16].x==360&&p[16].y==240&&p[4].x==480&&p[4].y==240&&p[6].x==0&&p[6].y==120&&
       p[11].x==120&&p[11].y==120&&p[21].x==240&&p[21].y==120&&p[17].x==360&&p[17].y==120&&p[7].x==480&&p[7].y==120&&p[2].x==0&&p[2].y==0&&
       p[14].x==120&&p[14].y==0&&p[19].x==240&&p[19].y==0&&p[13].x==360&&p[13].y==0&&p[23].x==480&&p[23].y==0)
        Last=1;
}

void settings()
{
    iShowBMP(0, 0, "Images/puzzle.bmp");
    iSetColor(255,0,0);
    iText(80, 530, "SETTINGS...", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,0,100);
    iFilledRectangle(70, 430, 200, 50);
    iFilledRectangle(70, 320, 200, 50);
    color_set();
    iSetColor(easy_on.r,easy_on.g,easy_on.b);
    iFilledCircle(400, 455, 30);
    iSetColor(easy_off.r,easy_off.g,easy_off.b);
    iFilledCircle(500, 455, 30);
    iSetColor(music_on.r,music_on.g,music_on.b);
    iFilledCircle(400, 345, 30);
    iSetColor(music_off.r,music_off.g,music_off.b);
    iFilledCircle(500, 345, 30);
    iSetColor(0,255,0);
    iText(100, 450, "Easy Mode", GLUT_BITMAP_HELVETICA_18);
    iText(100, 340, "Music", GLUT_BITMAP_HELVETICA_18);
    iText(385, 450, "ON", GLUT_BITMAP_HELVETICA_18);
    iText(480, 450, "OFF", GLUT_BITMAP_HELVETICA_18);
    iText(385, 340, "ON", GLUT_BITMAP_HELVETICA_18);
    iText(480, 340, "OFF", GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,0);
    iText(80, 250, "...Select one.", GLUT_BITMAP_HELVETICA_18);
    iSetColor(0,0,255);
    iText(620, 60, "Press B for home.", GLUT_BITMAP_9_BY_15);
}

void Lastpage()
{
    if(score<0) score=0;
    if(!score_call)
    {
        if(music) PlaySound("Sounds/Congratulations_sound.wav", NULL, SND_ASYNC);
        Max=fscore();
    }
    if(start==1) iShowBMP(100, 120, "Images/Cats.bmp");
    else if(start==2) iShowBMP(100, 120, "Images/Tajmohol.bmp");
    else if(start==3) iShowBMP(100, 120, "Images/Boats.bmp");
    if(Max==score)
    {
        iSetColor(r,100,b);
        iText(240, 440, "Best Score!!!", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    iSetColor(255,g,100);
    iText(180, 540, "CONGRATULATIONS!!", GLUT_BITMAP_TIMES_ROMAN_24);
    iSetColor(0,255,0);
    iText(190, 90, "Your score :", GLUT_BITMAP_HELVETICA_18);
    itoa(score, str, 10);
    iText(300, 90, str, GLUT_BITMAP_HELVETICA_18);
    iText(190, 60, "Best score :", GLUT_BITMAP_HELVETICA_18);
    itoa(Max, str, 10);
    iText(300, 60, str, GLUT_BITMAP_HELVETICA_18);
    if(easy)
    {
        iText(350, 93, "(easy)", GLUT_BITMAP_9_BY_15);
        iText(350, 63, "(easy)", GLUT_BITMAP_9_BY_15);
    }
    iSetColor(0,0,255);
    iText(620, 60, "Press B for home.", GLUT_BITMAP_9_BY_15);
}

void mov(int a, int b, int n)
{
    for(i=1;i<n;i++)
    {
        if(p[i].x==(p[0].x+a)&&p[i].y==(p[0].y+b))
        {
            if(music) PlaySound("Sounds/Puzzle_click_sound.wav", NULL, SND_ASYNC);
            score-=5;
            moves++;
            temp1.x=p[0].x;
            temp1.y=p[0].y;
            temp2.x=p[i].x;
            temp2.y=p[i].y;
            term=i;
        }
    }
}

void change()
{
    int a, b, s=(temp1.x-temp2.x)/5, t=(temp1.y-temp2.y)/5;
    a=abs(p[0].x-temp2.x);
    b=abs(p[0].y-temp2.y);
    p[0].x-=s;
    p[0].y-=t;
    p[term].x+=s;
    p[term].y+=t;
    if(a<50&&b<50)
    {
        p[0]=temp2;
        p[term]=temp1;
        term=0;
    }
}

void temp(int n)
{
    if(music) PlaySound("Sounds/Puzzle_click_sound.wav", NULL, SND_ASYNC);
    score-=5;
    moves++;
    temp1=p[0];
    temp2=p[i];
    term=i;
}

void rgb()
{
    r=rand()%255;
    g=rand()%255;
    b=rand()%255;
}

void timer()
{
    sec++;
    score--;
    if(sec==60)
    {
        minu++;
        sec=0;
    }
    if(minu==60)
    {
        hr++;
        minu=0;
        sec=0;
    }
}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    iClear();
    iShowBMP(0, 0, "Images/puzzle.bmp");
    iShowBMP(600, 0, "Images/Emoji.bmp");
    if(!Last)
    {
        if(start) iShowBMP(0, 0, "Images/back.bmp");
        if(start==0) puzzle0();
        if(start==1) puzzle1();
        if(start==2) puzzle2();
        if(start==3) puzzle3();
        if(start==4) settings();
        if(0<start&&start<4)
        {
            iResumeTimer(2);
            if(term) iResumeTimer(0);
            else iPauseTimer(0);
        }
        else
        {
            iPauseTimer(2);
            sec=0;
            minu=0;
            hr=0;
        }
    }
    else
    {
        iPauseTimer(2);
        Lastpage();
    }
    iSetColor(0,255,0);
    iLine(600, 0, 600, 600);
    itoa(hr, tim, 10);
    iText(630, 545, tim, GLUT_BITMAP_HELVETICA_18);
    iText(675, 545, ":", GLUT_BITMAP_HELVETICA_18);
    itoa(minu, tim, 10);
    iText(685, 545, tim, GLUT_BITMAP_HELVETICA_18);
    iText(730, 545, ":", GLUT_BITMAP_HELVETICA_18);
    itoa(sec, tim, 10);
    iText(740, 545, tim, GLUT_BITMAP_HELVETICA_18);
    itoa(moves, tim, 10);
    iText(700, 515, tim, GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,0,0);
    iText(620, 570, "TIMER  :", GLUT_BITMAP_HELVETICA_18);
    iText(620, 515, "Moves  :", GLUT_BITMAP_HELVETICA_18);
    iText(620, 30, "Press X for exit.", GLUT_BITMAP_9_BY_15);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

    if(start==0)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx >= 100 && mx <= 500 && my >= 430 && my <= 490)
            {
                pixel=200;
                start=1;
                N=3;
                pointxy(N);
                if(music) PlaySound("Sounds/Menu_click_sound.wav", NULL, SND_ASYNC);
            }
            else if(mx >= 100 && mx <= 500 && my >= 340 && my <= 400)
            {
                pixel=150;
                start=2;
                N=4;
                pointxy(N);
                if(music) PlaySound("Sounds/Menu_click_sound.wav", NULL, SND_ASYNC);
            }
            else if(mx >= 100 && mx <= 500 && my >= 250 && my <= 310)
            {
                pixel=120;
                start=3;
                N=5;
                pointxy(N);
                if(music) PlaySound("Sounds/Menu_click_sound.wav", NULL, SND_ASYNC);
            }
            else if(mx >= 100 && mx <= 500 && my >= 160 && my <= 220)
            {
                start=4;
                if(music) PlaySound("Sounds/Menu_click_sound.wav", NULL, SND_ASYNC);
            }
            else if(mx >= 100 && mx <= 500 && my >= 70 && my <= 130) exit(0);
        }
    }
    if(start==4)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(mx>370&&mx<430&&my>425&&my<485) easy=1;
            if(mx>470&&mx<530&&my>425&&my<485) easy=0;
            if(mx>370&&mx<430&&my>315&&my<375) music=1;
            if(mx>470&&mx<530&&my>315&&my<375) music=0;
        }
    }
    if(term==0&&mode==1&&easy==0)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if(my>=p[0].y&&my<=p[0].y+pixel)
            {
                if(mx >= p[0].x+pixel && mx <= p[0].x+2*pixel) mov(pixel,0,N*N);
                if(mx <= p[0].x && mx >= p[0].x-pixel) mov(-pixel,0,N*N);
            }
            if(mx>=p[0].x&&mx<=p[0].x+pixel)
            {
                if(my >= p[0].y+pixel && my <= p[0].y+2*pixel) mov(0,pixel,N*N);
                if(my <= p[0].y && my >= p[0].y-pixel) mov(0,-pixel,N*N);
            }
        }
    }
    if(term==0&&mode==1&&easy==1)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            for(i=1;i<N*N;i++) if(mx>=p[i].x&&mx<=(p[i].x+pixel)&&my>=p[i].y&&my<=(p[i].y+pixel)) temp(i);
        }
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'x'||key=='X')
    {
        exit(0);
    }
    if(key == 'b'||key=='B')
    {
        start=0;
        Last=0;
        if(music) PlaySound("Sounds/Menu_click_sound.wav", NULL, SND_ASYNC);
    }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_RIGHT)
    {
        if(start&&p[0].x!=0) mov(-pixel,0,N*N);
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(start&&p[0].x!=pixel*(N-1)) mov(pixel,0,N*N);
    }
    if(key == GLUT_KEY_DOWN)
    {
        if(start&&p[0].y!=pixel*(N-1)) mov(0,pixel,N*N);
    }
    if(key == GLUT_KEY_UP)
    {
        if(start&&p[0].y!=0) mov(0,-pixel,N*N);
    }
}


int main()
{
    iSetTimer(45, change);
    iSetTimer(100, rgb);
    iSetTimer(1000, timer);
    iInitialize(800, 600, "Puzzle Game");
    return 0;
}
