#include <graphics.h>
#include <stdio.h>

int main()
{
    int gd = DETECT;
    int gm = DETECT;
    initgraph(&gd, &gm, "");

    int x1,y1,x2,y2;
    int color;


    for(int i=0; i<100; i++)
    {
        x1 = rand() % getmaxx();
        y1 = rand() % getmaxy();
        x2 = rand() % getmaxx();
        y2 = rand() % getmaxy();

        color = rand() % 16;

        setcolor(color);
        line(x1,y1,x2,y2);

        delay(1000);
        cleardevice();
    }

    closegraph();
    return 0;
}
