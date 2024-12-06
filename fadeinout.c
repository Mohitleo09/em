#include <reg51.h>

void delay(unsigned int count)
{
    unsigned int i, j;
    for(i = 0; i < count; i++)
        for(j = 0; j < 1275; j++);
}

void pwm(unsigned char duty_cycle)
{
    unsigned int i;
    for(i = 0; i < 255; i++)
    {
        if(i < duty_cycle)
            P1 = 0xFF;  // LED ON
        else
            P1 = 0x00;  // LED OFF
        delay(10);
    }
}

void main()
{
    while(1)
    {
        for(unsigned char i = 0; i < 255; i++)   // Fade In
            pwm(i);
        
        for(unsigned char i = 255; i > 0; i--)   // Fade Out
            pwm(i);
    }
}
