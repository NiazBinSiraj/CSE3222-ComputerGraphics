#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main() {
    int gd=DETECT, gm=DETECT;
	initgraph(&gd,&gm,"");

	setcolor(WHITE);

    setfillstyle(SOLID_FILL, GREEN);
    rectangle(100,100,450,300);
    floodfill(150,150,WHITE);

    setfillstyle(SOLID_FILL, RED);
    circle(250, 200, 60);
    floodfill(250,200,WHITE);

    getch();
    closegraph();
    return 0;
}
