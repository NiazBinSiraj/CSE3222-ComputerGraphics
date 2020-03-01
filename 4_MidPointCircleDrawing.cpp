#include <bits/stdc++.h>
#include <graphics.h>

void drawPixels(int xCenter, int yCenter, int x, int y, int color)
{
    putpixel(xCenter + x, yCenter + y, color);
    putpixel(xCenter - x, yCenter + y, color);
    putpixel(xCenter + x, yCenter - y, color);
    putpixel(xCenter - x, yCenter - y, color);

    putpixel(xCenter + y, yCenter + x, color);
    putpixel(xCenter - y, yCenter + x, color);
    putpixel(xCenter + y, yCenter - x, color);
    putpixel(xCenter - y, yCenter - x, color);

    return;
}

void drawCircle(int xCenter, int yCenter, int radius, int color)
{
    int x,y,p;
    x = 0;
    y = radius;
    p = 1-radius;

    drawPixels(xCenter, yCenter, x, y, color);

    while(x<y)
    {
        if(p<0)
        {
            x++;
            p = p+(2*x)+1;
        }
        else
        {
            x++;
            y--;
            p = p + 2 * (x - y) + 1;
        }
        drawPixels(xCenter, yCenter, x, y, color);
    }
    return;
}

int main()
{
    int gd = DETECT;
    int gm = DETECT;
    initgraph(&gd, &gm, "");

    drawCircle(200,200,50, BLUE);

    getch();
    closegraph();
}
