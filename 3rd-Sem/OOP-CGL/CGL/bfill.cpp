#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <iostream>

void bfill(int x, int y, int fill, int border) {
    // Check if the current pixel is not the border color and is not filled
    if (getpixel(x, y) != border && getpixel(x, y) != fill) {
        putpixel(x, y, fill); // Fill the pixel with the fill color
        // Recursively fill the surrounding pixels
        bfill(x, y - 1, fill, border); // Up
        bfill(x - 1, y, fill, border); // Left
        bfill(x, y + 1, fill, border); // Down
        bfill(x + 1, y, fill, border); // Right
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    // Draw a rectangle
    rectangle(300, 100, 600, 300);
    
    // Fill the rectangle with color
    bfill(350, 120, BLUE, WHITE);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0; // Return success
}
