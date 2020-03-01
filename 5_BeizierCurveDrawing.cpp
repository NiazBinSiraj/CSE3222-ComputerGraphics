#include <bits/stdc++.h>
#include <graphics.h>

int fact(int n)
{
    if(n==0) return 1;
    return n*fact(n-1);
}

double ncr(int n, int r)
{
    double a,b,c;
    a = fact(n);
    b = fact(r);
    c = fact(n-r);
    return a/(b*c); // n!/(r! * (n-r)!)
}

double power(double a, double b)
{
    double res = 1.0;
    for(int i=0; i<(int)b; i++)
    {
        res = res * a;
    }
    return res;
}

double calB(double n, double i, double u)
{
    return ncr(n,i) * power(1-u,n-i) * power(u,i);
}

void drawBeizierCurve(int x[], int y[], int color, int n)
{
    for(double u=0; u<1.0; u+=0.00005)
    {
        double x1=0,y1=0;
        for(int i=0; i<=n; i++)
        {
            x1 += x[i]*calB(n,i,u);
            y1 += y[i]*calB(n,i,u);
        }
        putpixel(x1,y1,color);
    }

    for(int i=0; i<=n; i++)
    {
        putpixel(x[i],y[i],WHITE);
    }
    return;
}

int main()
{
    //freopen("out.txt", "w", stdout);

    int n= 4;
    int x[10];
    int y[10];

    x[0] = 0;
    x[1] = 100;
    x[2] = 400;
    x[3] = 600;
    x[4] = 300;

    y[0] = 10;
    y[1] = 200;
    y[2] = 400;
    y[3] = 100;
    y[4] = 200;


    int gd = DETECT;
    int gm = DETECT;

    initgraph(&gd, &gm, "");

    drawBeizierCurve(x,y,RED,n);

    delay(5000);
    closegraph();
    return 0;
}
