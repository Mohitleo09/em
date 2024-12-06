#include <reg51.h> // Include the 8051 register definition file

void delay();

void main() {
    while (1) {
        P2 = 0x00; // Set Port 2 to 0x00
        delay();   // Call delay function

        P2 = 0xFF; // Set Port 2 to 0xFF
        delay();   // Call delay function
    }
}

void delay() {
    unsigned char r4, r3;
    for (r4 = 188; r4 > 0; r4--) {     // Outer loop for delay
        for (r3 = 255; r3 > 0; r3--) { // Inner loop for delay
        }
}
		}
