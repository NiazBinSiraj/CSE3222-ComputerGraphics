#include <bits/stdc++.h>
#include <graphics.h>

double xmin, ymin, xmax, ymax;
int INSIDE=0, TOP=8, BOTTOM=4, LEFT=1, RIGHT=2;

double x,y;

bool LeftSolver(double x1, double y1, double x2, double y2)
{
    if(x1 == x2) return false;
    else
    {
        x = xmin;
        double m = (y1-y2)/(x1-x2);
        y = m*(x-x1) + y1;

        if(y>=ymin && y<=ymax) return true;
        else return false;
    }
}

bool TopSolver(double x1, double y1, double x2, double y2)
{
    if(y1 == y2) return false;
    else
    {
        y = ymin;
        double m = (x1-x2)/(y1-y2);
        x = m*(y-y1) + x1;

        if(x>=xmin && x<=xmax) return true;
        else return false;
    }
}

bool RightSolver(double x1, double y1, double x2, double y2)
{
    if(x1 == x2) return false;
    else
    {
        x = xmax;
        double m = (y1-y2)/(x1-x2);
        y = m*(x-x1) + y1;

        if(y>=ymin && y<=ymax) return true;
        else return false;
    }
}

bool BottomSolver(double x1, double y1, double x2, double y2)
{
    if(y1 == y2) return false;
    else
    {
        y = ymax;
        double m = (x1-x2)/(y1-y2);
        x = m*(y-y1) + x1;

        if(x>=xmin && x<=xmax) return true;
        else return false;
    }
}

int findCode(int x, int y)
{
    int code = INSIDE;
    if(x<xmin) code = code|LEFT;
    if(x>xmax) code = code|RIGHT;
    if(y<ymin) code = code|TOP;
    if(y>ymax) code = code|BOTTOM;

    return code;
}

void lineClip(double x1, double y1, double x2, double y2, int color)
{
    int code1 = findCode(x1,y1);
    int code2 = findCode(x2,y2);

    double nx1,ny1,nx2,ny2;
    bool gotOne = false;
    bool done = false;

    if(code1 == 0 && code2 == 0)
    {
        setcolor(color);
        line(x1,y1,x2,y2);
        return;
    }

    if(code1 & code2)
    {
        printf("Not Visible\n");
        return;
    }

    if(code1 == 0)
    {
        nx1 = (double) x1;
        ny1 = (double) y1;
        gotOne = true;
    }
    else if(code2 == 0)
    {
        nx1 = (double) x2;
        ny1 = (double) y2;
        gotOne = true;
    }

    if(LeftSolver(x1,y1,x2,y2) == true)
    {
        if(gotOne == true)
        {
            nx2 = x;
            ny2 = y;
            done = true;
        }

        else
        {
            nx1 = x;
            ny1 = y;
            gotOne = true;
        }
    }

    if(TopSolver(x1,y1,x2,y2) == true && done == false)
    {
        if(gotOne == true)
        {
            nx2 = x;
            ny2 = y;
            done = true;
        }

        else
        {
            nx1 = x;
            ny1 = y;
            gotOne = true;
        }
    }

    if(RightSolver(x1,y1,x2,y2) == true && done == false)
    {
        if(gotOne == true)
        {
            nx2 = x;
            ny2 = y;
            done = true;
        }

        else
        {
            nx1 = x;
            ny1 = y;
            gotOne = true;
        }
    }

    if(BottomSolver(x1,y1,x2,y2) == true && done == false)
    {
        if(gotOne == true)
        {
            nx2 = x;
            ny2 = y;
            done = true;
        }

        else
        {
            nx1 = x;
            ny1 = y;
            gotOne = true;
        }
    }
    setcolor(color);
    line(nx1,ny1,nx2,ny2);
    return;
}

int main()
{
    int gd=DETECT,gm=DETECT;
    initgraph(&gd,&gm,"");

    xmin=100,xmax=500,ymin=10,ymax=300;
    rectangle(xmin,ymin,xmax,ymax);

    double x1=50,y1=60,x2=600,y2=200; //line
    //setcolor(RED);
    //line(x1,y1,x2,y2);

    lineClip(x1,y1,x2,y2,BLUE);

    getch();
    closegraph();
    return 0;
}
