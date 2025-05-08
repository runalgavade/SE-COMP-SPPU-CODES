#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

void ffill(int x, int y, int oldcolour, int newcolour) {
    // Check if the current pixel is the old colour
    if (getpixel(x, y) == oldcolour) {
        putpixel(x, y, newcolour); // Change the pixel to the new colour
        // Recursively fill the surrounding pixels
        ffill(x + 1, y, oldcolour, newcolour);
        ffill(x, y + 1, oldcolour, newcolour);
        ffill(x - 1, y, oldcolour, newcolour);
        ffill(x, y - 1, oldcolour, newcolour);
        ffill(x + 1, y + 1, oldcolour, newcolour);
        ffill(x + 1, y - 1, oldcolour, newcolour);
        ffill(x - 1, y - 1, oldcolour, newcolour);
        ffill(x - 1, y + 1, oldcolour, newcolour);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    rectangle(100, 100, 300, 300); // Draw a rectangle
    ffill(105, 105, 0, 225); // Fill the rectangle with colour

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0; // Return success
}
