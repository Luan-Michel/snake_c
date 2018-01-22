#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void gotoxy(int x, int y)
{
        COORD coord = {0, 0};
        coord.X = x;
        coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int posy=8, posx=2, mx = 2, my = 8,t[50][2],tam=0,vel=500;
char pos = 's';

void fim()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\tGAME OVER!!!");
    getch();
    exit(1);
}

void gameover()
{
    int i;
    if(posx >= 79 || posx <= 1 || posy >= 24 || posy <= 7)
    {
        fim();
    }
    for(i=2;i<=tam;i++)
    {
        if(posx == t[i][1] && posy == t[i][2])
        {
            if(tam > 2){
                fim();
            }
        }
    }

}

void limp()
{
    int i;
    for(i=tam;i>0;i--)
    {
        t[i][1] = t[i-1][1];
        t[i][2] = t[i-1][2];
    }
    t[1][1] = posx;
    t[1][2] = posy;
    gotoxy(t[tam][1],t[tam][2]);
    printf(" ");
}

void maca()
{
    if(mx == posx && my == posy)
    {
        gotoxy(70,1);
        printf("%i",(tam*10));
        mx = (rand()%77)+1;
        my = (rand()%17)+7;
        gotoxy(mx,my);
        printf("%c",153);
        tam = tam+1;
        vel = 500 - (tam*10);
    }
}

void direcao(int d)
{
    if(d==0) posy--;
    if(d==1) posx--;
    if(d==2) posy++;
    if(d==3) posx++;
    gotoxy(posx,posy);
    printf("%c",177);
    gotoxy(79,24);
    Sleep(vel);
}

void movimento()
{
    int d, m = 1, tam = 1;
    while(pos != 'l')
    {
        while(pos!='l' && !(pos=kbhit()))
        {
            direcao(d);
            maca();
            limp();
            gameover();
        }
        pos = getch();
        if(pos=='w' && d != 2) d=0;
        if(pos=='a' && d != 3) d=1;
        if(pos=='s' && d != 0) d=2;
        if(pos=='d' && d != 1) d=3;
    }

}

main()
{
    int x;
    printf("\n\t\t ##### ##  ## ###### ##  ## #####         SCORE: ");
    printf("\n\t\t ##    ### ## ##  ## ## ##  ##");
    printf("\n\t\t ##### ###### ###### ####   ####");
    printf("\n\t\t    ## ## ### ##  ## ## ##  ##");
    printf("\n\t\t ##### ##  ## ##  ## ##  ## #####");
    for(x=0;x<=79;x++){
            gotoxy(x,6);
            printf("%c",219);
    }
    for(x=0;x<=79;x++){
            gotoxy(x,24);
            printf("%c",219);
    }
    for(x=7;x<=24;x++){
            gotoxy(0,x);
            printf("%c",219);
    }
    for(x=7;x<=24;x++){
            gotoxy(79,x);
            printf("%c",219);
    }

    movimento();
}
