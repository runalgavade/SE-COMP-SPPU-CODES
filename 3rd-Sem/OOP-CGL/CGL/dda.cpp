#include <iostream>
#include <math.h>
#include <graphics.h>

#define Round(a) ((int)(a + 0.5))

using namespace std;

class Runal {
private:
    int x1, y1, x2, y2, x3, y3, x4, y4;
public:
    void accept();
    void call();
    void DDA(int xa, int ya, int xb, int yb);
    void midpoint();
    void draw_midpoint(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd);
    void midpoint(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd);
};

void Runal::accept() {
    cout << "Enter coordinates of Square:" << endl;
    cout << "\nEnter x1: ";
    cin >> x1;
    cout << "\nEnter y1: ";
    cin >> y1;
    cout << "\nEnter x2: ";
    cin >> x2;
    cout << "\nEnter y2: ";
    cin >> y2;
    cout << "\nEnter x3: ";
    cin >> x3;
    cout << "\nEnter y3: ";
    cin >> y3;
    cout << "\nEnter x4: ";
    cin >> x4;
    cout << "\nEnter y4: ";
    cin >> y4;
}

void Runal::DDA(int xa, int ya, int xb, int yb) {
    int dx, dy, steps, k;
    dx = xb - xa;
    dy = yb - ya;
    float x = xa, y = ya, xinc, yinc;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xinc = dx / (float)steps;
    yinc = dy / (float)steps;

    putpixel(Round(x), Round(y), 2);
    for (k = 0; k < steps; k++) {
        x += xinc;
        y += yinc;
        putpixel(Round(x), Round(y), 2);
        delay(5);
    }
}

void Runal::midpoint() {
    int mid_x1, mid_y1, mid_x2, mid_y2, mid_x3, mid_y3, mid_x4, mid_y4;
    mid_x1 = (x1 + x2) / 2;
    mid_y1 = (y1 + y2) / 2;
    mid_x2 = (x2 + x3) / 2;
    mid_y2 = (y2 + y3) / 2;
    mid_x3 = (x3 + x4) / 2;
    mid_y3 = (y3 + y4) / 2;
    mid_x4 = (x4 + x1) / 2;
    mid_y4 = (y4 + y1) / 2;
    draw_midpoint(mid_x1, mid_y1, mid_x2, mid_y2, mid_x3, mid_y3, mid_x4, mid_y4);
}

void Runal::draw_midpoint(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
    DDA(xa, ya, xb, yb);
    DDA(xb, yb, xc, yc);
    DDA(xc, yc, xd, yd);
    DDA(xd, yd, xa, ya);
    midpoint(xa, ya, xb, yb, xc, yc, xd, yd);
}

void Runal::midpoint(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
    int mid_x1, mid_y1, mid_x2, mid_y2, mid_x3, mid_y3, mid_x4, mid_y4;
    mid_x1 = (xa + xb) / 2;
    mid_y1 = (ya + yb) / 2;
    mid_x2 = (xb + xc) / 2;
    mid_y2 = (yb + yc) / 2;
    mid_x3 = (xc + xd) / 2;
    mid_y3 = (yc + yd) / 2;
    mid_x4 = (xd + xa) / 2;
    mid_y4 = (yd + ya) / 2;

    DDA(mid_x1, mid_y1, mid_x2, mid_y2);
    DDA(mid_x2, mid_y2, mid_x3, mid_y3);
    DDA(mid_x3, mid_y3, mid_x4, mid_y4);
    DDA(mid_x4, mid_y4, mid_x1, mid_y1);
}

void Runal::call() {
    DDA(x1, y1, x2, y2);
    delay(100);
    DDA(x2, y2, x3, y3);
    delay(200);
    DDA(x3, y3, x4, y4);
    delay(200);
    DDA(x4, y4, x1, y1);
    delay(100);
    midpoint();
}

int main() {
    Runal a;
    a.accept();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    a.call();
    getch();
    closegraph();
    return 0;
}
