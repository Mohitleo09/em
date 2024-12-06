#include <reg51.h>

void delay(unsigned int x);

void delay(unsigned int x) {
    while (x > 0) {
        x--;  // Simple delay loop
    }
}

void main() {
    while (1) {
        P1_0 = 1;       // Set P1.0 high
        delay(20000);   // Delay
        P1_0 = 0;       // Set P1.0 low
        delay(20000);   // Delay
    }
}
