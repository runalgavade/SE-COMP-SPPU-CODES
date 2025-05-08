#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#define ScreenWdith getmaxx()
#define ScreenHeight getmaxy()
#define GroundY ScreenHeight*0.75

int ldisp=0;

void umb(int x,int ldisp)
{
    circle(x,GroundY-90,10);//head
    line(x,GroundY-80,x,GroundY-30); //neck to legs joint
    //hand ->
    line(x,GroundY-70,x+10,GroundY-60);//back hand half hand
    line(x,GroundY-65,x+10,GroundY-55);//front hand half hand
    line(x+10,GroundY-60,x+20,GroundY-70);//back hand second half
    line(x+10,GroundY-55,x+20,GroundY-70);//front hand second half
    //legs ->
    line(x,GroundY-30,x+ldisp,GroundY);
    line(x,GroundY-30,x-ldisp,GroundY);

    pieslice(x+20,GroundY-120,0,180,40);//umbrella head
    line(x+20,GroundY-120,x+20,GroundY-70);//umbrella stick

}

void umb(int x)
{
    int i,rx,ry;
    for(int i=0;i<400;i++)
    {
        rx = rand() % ScreenWdith;
        ry = rand() % ScreenHeight;

        if(ry<GroundY-4)
        {
            if(ry < GroundY-120 || (ry > GroundY-120 && (rx < x-20 || rx > x+60)))
            line(rx,ry,rx+0.5,ry+4);
        }
    }
}

int main(){
    int gd=DETECT, gm;
    int x=0;
    initgraph(&gd, &gm,NULL);
    while(!kbhit())
    {
        line(0,GroundY,ScreenWdith,GroundY);
        umb(x);
        ldisp = (ldisp+2)%20;
        umb(x,ldisp);
        delay(25);
        cleardevice();
        x=(x+2)%ScreenWdith;
    }
    getch();
}
