#include <graphics.h>

void plotLine(int x1, int y1, int x2, int y2, int color)
{
    int dx,dy,p,x,y;
    dx = x2-x1;
    dy = y2-y1;
    x = x1;
    y = y1;
    p = 2*dy - dx;

    while(x<= x2 && y<=y2)
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
    return;
}

int main()
{
    int gd = DETECT;
    int gm = DETECT;

    initgraph(&gd, &gm, "");

    setcolor(WHITE);

    plotLine(50,50,200,200,WHITE);

    getch();
    closegraph();
}
