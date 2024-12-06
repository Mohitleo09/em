#include <reg51.h>
#include "lcd.h"  // Assuming you are using an LCD for display

void delay(unsigned int count)
{
    unsigned int i, j;
    for(i = 0; i < count; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    unsigned char hours = 0, minutes = 0, seconds = 0;
    lcd_init();
    while(1)
    {
        lcd_clear();
        lcd_write_num(hours);
        lcd_write(':');
        lcd_write_num(minutes);
        lcd_write(':');
        lcd_write_num(seconds);
        delay(1000);  // 1 second delay
        seconds++;
        if(seconds >= 60)
        {
            seconds = 0;
            minutes++;
            if(minutes >= 60)
            {
                minutes = 0;
                hours++;
                if(hours >= 24)
                    hours = 0;
            }
        }
    }
}
