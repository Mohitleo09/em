#include<reg51.h>
sbit CLK = P3^0;
sbit ACLK = P3^1;
void MSdelay(int n)
{
	unsigned int i,j;
	for(i=0;i<1275;i++)
	for(j=0;j<n;j++);
}
void main()
{
	while(1)
	{
	if(CLK == 0)	
	{
		P2 = 0x66;
		MSdelay(50);
		P2 = 0xCC;
		MSdelay(50);
		P2 = 0x99;
		MSdelay(50);
		P2 = 0x33;
		MSdelay(50);
	}
	
	if(ACLK == 0)	
	{
		P2 = 0x66;
		MSdelay(50);
		P2 = 0x33;
		MSdelay(50);
		P2 = 0x99;
		MSdelay(50);
		P2 = 0xCC;
		MSdelay(100);
	}
}
}
