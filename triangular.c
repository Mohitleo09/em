#include <reg51.h>

void delay(unsigned int count)
{
    unsigned int i, j;
    for(i = 0; i < count; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    unsigned char i;
    while(1)
    {
        for(i = 0; i < 255; i++)  // Increase
        {
            P1 = i;
            delay(50);
        }
        for(i = 255; i > 0; i--)  // Decrease
        {
            P1 = i;
            delay(50);
        }
    }
}
