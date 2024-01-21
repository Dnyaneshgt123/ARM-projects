#include<LPC21xx.h>
void clock_wise(void); //void means doesn't return anything from this function
void anti_clock_wise(void);
unsigned int var1;
unsigned long int i = 0, j = 0, k = 0;
int main (void)
{
PINSEL2 = 0x00000000; //p1.20 to p1.23 GPIO
IO1DIR = 0x00F00000; // p1.20 to p1.23 as output
while(1)
{
for(j = 0; j < 50; j++) //50 times in clock wise rotation
clock_wise(); //rotate one round clockwise

}

}

void clock_wise(void)
{
var1 = 0x00080000; //for clockwise
for(i = 0; i <= 3; i++)// for ABCD stepping
{
var1 <<=1;
IO1CLR = 0x00F00000; //clearing all 4 bits
IO1SET = var1; //setting particular bit
for(k = 0; k < 3000; k++); //this line is terminated with semi colon for speed variation
}
}

void anti_clock_wise(void)
{
	
var1 = 0x00800000;
IO1CLR = 0x00F00000;
IO1SET = var1;
for(i = 0; i < 3; i++)
{
var1 >>= 1;
IO1CLR = 0x00F00000;
IO1SET = var1;
for(k = 0; k < 3000; k++);
}

}

