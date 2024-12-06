#include <reg51.h>

sbit LED = P2^0; // Define P2.0 as LED

void delay();

void main() {
    while (1) {
        LED = 1;   // Set P2.0 HIGH
        delay();   // Call delay
        LED = 0;   // Set P2.0 LOW
        delay();   // Call delay
    }
}

void delay() {
    unsigned char r4, r3;
    for (r4 = 18; r4 > 0; r4--) {     // Outer loop
        for (r3 = 255; r3 > 0; r3--) { // Inner loop
            // Do nothing, just wait
        }
    }
}
