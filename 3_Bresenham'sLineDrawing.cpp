#include <graphics.h>
#include <bits/stdc++.h>

void plotLine(int x1, int y1, int x2, int y2, int color)
{
    double m;
    int dx,dy,p;
    int x,y,xEnd;

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    m = (double) dy/dx;

    if(x1 > x2)
    {
        std::swap(x1,x2);
        std::swap(y1,y2);
    }

    x = x1;
    y = y1;
    putpixel(x,y,color);


    if(m < 1)
    {
        p = 2*dy - dx;
        while(x<x2)
        {
            if(p<0)
            {
                x++;
                putpixel(x,y,color);

                p = p + (2*dy);
            }

            else
            {
                x++;
                y++;
                putpixel(x,y,color);

                p = p + (2*dy) - (2*dx);
            }
        }
    }

    else
    {
        p = 2*dx - dy;
        while(x<x2)
        {
            if(p<0)
            {
                y++;
                putpixel(x,y,color);

                p = p + (2*dx);
            }

            else
            {
                x++;
                y++;
                putpixel(x,y,color);

                p = p + (2*dx) - (2*dy);
            }
        }
    }
    return;
}

int main()
{
    int gd = DETECT;
    int gm = DETECT;

    initgraph(&gd, &gm, "");

    plotLine(100,50,200,200,WHITE);


    getch();
    closegraph();
}
