#include <reg51.h> // Include header for 8051 registers

void delay(); // Function prototype for delay

void main() {
    while (1) { // Infinite loop
        P2 = 0x01; // Set P2.0
        delay();

        P2 = 0x02; // Set P2.1
        delay();

        P2 = 0x04; // Set P2.2
        delay();

        P2 = 0x08; // Set P2.3
        delay();

        P2 = 0x10; // Set P2.4
        delay();

        P2 = 0x20; // Set P2.5
        delay();

        P2 = 0x40; // Set P2.6
        delay();

        P2 = 0x80; // Set P2.7
        delay();
    }
}

void delay() {
    unsigned char i;
    for (i = 0; i < 255; i++) { // Simple software delay
        // Do nothing, just loop
    }
}
