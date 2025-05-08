#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<iostream>
using namespace std;
 
/* Defining the class to store edges-----------------------------------------*/
 
class edge
{
public: int x1;
int y1;
int x2;
int y2;
int flag;
};
 
int main()
{
int gd = DETECT, gm, n, i, j, k;
 
float dx,dy,m[10],x_int[10],inter_x[10];
int x[10],y[10],ymax = 0, ymin = 480, yy,temp;
edge ed[10],temped;
 
initgraph (&gd, &gm, "c:\\turboc3\\bgi");
 
/* Read the number of vertices of the polygon------------------------------------------------ */
 
cout<<"Enter the number vertices of the graph: ";
cin>>n;
/* Read the vertices of the polygon and also find Ymax and Ymin--------------------------------------------------------------- */
 
cout<<"Enter the vertices: \n";
for(i = 0; i < n; i++)
{
cout<<"x["<<i<<"]:"; 
cin>>x[i];
cout<<"y["<<i<<"]:";
cin>>y[i];
if(y[i] > ymax)
ymax = y[i];
if(y[i] < ymin)
ymin = y[i];
ed[i].x1 = x[i];
ed[i].y1 = y[i];
}
/* Store the edge information-------------------------------*/
 
for(i=0;i<n-1;i++)
{
ed[i].x2 = ed[i+1].x1;
ed[i].y2 = ed[i+1].y1;
ed[i].flag=0;
}
ed[i].x2 = ed[0].x1;
ed[i].y2 = ed[0].y1;
ed[i].flag=0;
/* Check for y1>y2, if not interchange y1 and y2 with corresponding x1 and x2--------------------------------*/
for(i=0;i<n;i++)
{
  if(ed[i].y1 < ed[i].y2)
  {
  temp = ed[i].x1;
  ed[i].x1=ed[i].x2;
  ed[i].x2=temp;
  temp = ed[i].y1;
  ed[i].y1=ed[i].y2;
  ed[i].y2=temp;
  }
}
 
/* Draw the polygon---------------------- */
for(i=0;i<n;i++)
{
line(ed[i].x1,ed[i].y1,ed[i].x2,ed[i].y2);
}
/* sorting of edges in the order of y1,y2,x1--------------------------------------------- */
  for(i=0;i<n-1;i++)
  {
 	for(j=0;j<n-1;j++)
 	{
  	   if(ed[j].y1<ed[j+1].y1)
  	   {
  	   temped = ed[j];
  	   ed[j]=ed[j+1];
  	   ed[j+1] = temped;
  	   }
  	   if(ed[j].y1==ed[j+1].y1)
  	   {
        	if(ed[j].y2<ed[j+1].y2)
        	{
        	temped = ed[j];
        	ed[j]=ed[j+1];
        	ed[j+1] = temped;
        	}
        	   if(ed[j].y2==ed[j+1].y2)
        	{
              	if(ed[j].x1<ed[j+1].x1)
              	{
                    	temped = ed[j];
                    	ed[j]=ed[j+1];
                    	ed[j+1] = temped;
              	}
        	}
  	   }
 
  	}
   }
/* calculating 1/slope of each edge  and storing top xcoordinate of the edge     --------------------------- */
for(i=0;i<n;i++)
{
dx = ed[i].x2 - ed[i].x1;
dy = ed[i].y2 - ed[i].y1;
if(dy==0)
{
m[i]=0;
}
else
{
m[i] = dx/dy;
}
inter_x[i]= ed[i].x1;
}
 
yy=ymax;
while(yy>ymin)
{
/*  Marking active egdes-------------------------- */
   	for(i=0;i<n;i++)
   	{
   	if(yy > ed[i].y2 && yy <= ed[i].y1 && ed[i].y1!=ed[i].y2)
  	  {
  	  ed[i].flag = 1;
  	  }
  	  else
  	  {
  	  ed[i].flag = 0;
  	  }
   	}
 
/* Finding the x intersections--------------------------------  */
 
   	j=0;
   	for(i=0;i<n;i++)
	{
  	 if(ed[i].flag==1)
  	 {
   	 	 if(yy==ed[i].y1)
  	  {
  	   x_int[j]=ed[i].x1;
  	   j++;
        	if(ed[i-1].y1==yy && ed[i-1].y1<yy)
        	{
        	 x_int[j]=ed[i].x1;
        	 j++;
        	}
        	if(ed[i+1].y1==yy && ed[i+1].y1<yy)
        	{
        	 x_int[j]=ed[i].x1;
        	 j++;
        	}
  	  }
  	else
  	{
  	x_int[j] = inter_x[i]+(-m[i]);
  	inter_x[i]=x_int[j];
  	j++;
  	}
  	}
	}
 
/* Sorting the x intersections--------------------------------*/
  	for(i=0;i<j;i++)
  	{
  	  for(k=0;k<j-1;k++)
  	  {
  	   if(x_int[k]>x_int[k+1])
  	   {
  	    temp =x_int[k];
  	    x_int[k] = x_int[k+1];
  	    x_int[k+1] = temp;
  	   }
  	  }
  	}
 
/* Extracting pairs of x values to draw lines---------------------------------------------- */
  	setcolor(10);
  	for(i=0;i<j;i+=2)
  	{
  	line(x_int[i],yy,x_int[i+1],yy);
  	}
	yy--;
	delay(50);
}
getch();
}
