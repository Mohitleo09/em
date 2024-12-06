#include <reg51.h>

// Define pins
sbit rd = P3^0;    // Read pin for ADC
sbit wr = P3^1;    // Write pin for ADC
sbit intr = P3^2;  // Interrupt pin for ADC
sbit cs = P3^3;    // Chip select pin for ADC

// Function prototypes
void delay(unsigned int ms);
unsigned int adc_read();
void display_on_lcd(unsigned int temp);
void lcd_init();
void lcd_command(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_string(unsigned char *str);

// Delay function
void delay(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

// Function to read data from ADC0804
unsigned int adc_read()
{
    unsigned int adc_value;
    wr = 0;       // Start conversion
    delay(1);
    wr = 1;       // Stop conversion
    while(intr == 1);  // Wait for conversion to complete
    rd = 0;       // Enable reading
    adc_value = P1;    // Read data from ADC
    rd = 1;       // Disable reading
    return adc_value;
}

// Initialize LCD
void lcd_init()
{
    lcd_command(0x38);  // 8-bit, 2-line, 5x7 matrix
    lcd_command(0x0C);  // Display ON, Cursor OFF
    lcd_command(0x06);  // Increment cursor
    lcd_command(0x01);  // Clear display
    delay(2);
}

// Send command to LCD
void lcd_command(unsigned char cmd)
{
    P2 = cmd;
    P3_4 = 0;  // RS = 0
    P3_5 = 0;  // RW = 0
    P3_6 = 1;  // Enable
    delay(1);
    P3_6 = 0;  // Disable
}

// Send data to LCD
void lcd_data(unsigned char data)
{
    P2 = data;
    P3_4 = 1;  // RS = 1
    P3_5 = 0;  // RW = 0
    P3_6 = 1;  // Enable
    delay(1);
    P3_6 = 0;  // Disable
}

// Display a string on LCD
void lcd_string(unsigned char *str)
{
    while(*str)
    {
        lcd_data(*str);
        str++;
    }
}

// Display temperature on LCD
void display_on_lcd(unsigned int temp)
{
    unsigned int temp_integer = temp / 10;  // Integer part
    unsigned int temp_decimal = temp % 10; // Decimal part

    lcd_command(0x80);  // Move to first row
    lcd_string("Temp: ");
    lcd_data(temp_integer + '0');  // Display integer part
    lcd_data('.');
    lcd_data(temp_decimal + '0');  // Display decimal part
    lcd_string(" C");
}

void main()
{
    unsigned int adc_value, temperature;
    lcd_init();

    // Initialize ADC pins
    cs = 0;   // ADC enabled
    rd = 1;   // ADC ready to read
    wr = 1;   // ADC ready to write

    while(1)
    {
        adc_value = adc_read();          // Read ADC value
        temperature = (adc_value * 50) / 255;  // Convert to temperature (LM35)
        display_on_lcd(temperature);    // Display on LCD
        delay(1000);                    // 1-second delay
    }
}
