#include <reg51.h>

void delay(unsigned int);
void delay(unsigned int x)
{
    while(x>0){
x--;
    }
}
void main(){
    while(1){
p1^0 = 0x01;
delay(20000);
    }
}
