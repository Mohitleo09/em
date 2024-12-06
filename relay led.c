#include <reg51.h>

void delay(unsigned int count)
{
    unsigned int i, j;
    for(i = 0; i < count; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    while(1)
    {
        P1 = 0xFF;  // Relay ON, LED ON
        delay(1000);
        P1 = 0x00;  // Relay OFF, LED OFF
        delay(1000);
    }
}
