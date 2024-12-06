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
        P1 = ~P1;  // Toggle LED state
        delay(500); // Delay
    }
}
