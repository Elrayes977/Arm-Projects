/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:16/7/2023
	Version: 1.0.0
	SWC:RCC

	*****************************
 */
#if 0
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"

void delay(u16 num);

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	MGPIO_enSetPinDirection(PC13, GPIO_u8OUT_PUSH_PULL_2MHZ);


  while(1){
	  MGPIO_enSetPinValue(PC13,GPIO_u8HIGH);
	  delay(600);
	  MGPIO_enSetPinValue(PC13,GPIO_u8LOW);
	  delay(600);
  }
}

void delay(u16 num)
{
for(u16 i=0;i<num;i++)
{
	for(u16 j=0;j<num;j++)
	{
		asm("NOP");
	}



}



}
#endif

#include<stdio.h>

#define ARRAY_SIZE   10
int array[ARRAY_SIZE] = {60, 100, 30, 10, 80, 40, 20, 70, 50, 90};

void BubbleSort(int *ptr, int size);
void PrintArray(int *ptr, int size);
void Swap_Number(int *x, int *y);
void UpdateArray(int *ptr, int size);

int data = 20;

int main(void)
{
  	int arraySize = ARRAY_SIZE;
	int a=5, b=8;

	BubbleSort(array, arraySize);
	PrintArray(array, arraySize);

	data++;
	UpdateArray(array, arraySize);

 	Swap_Number(&a, &b);

	while(1);

	return 0;
}



void BubbleSort(int *ptr, int size)
{
	int temp;

	for(int i=0; i<size-1; i++)
	{
		for(int j=0; j<size-i-1; j++)
		{
			if(ptr[j] > ptr[j+1])
			{
				temp = ptr[j+1];
				ptr[j+1] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

void PrintArray(int *ptr, int size)
{
	for(int i=0; i<size; i++)
	{

		printf("Element of [%d]: ", i+1);
		printf("%d\n",array[i]);
	}

}


void Swap_Number(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;

}


void UpdateArray(int *ptr, int size)
{
	for(int i=0; i<size; i++)
	{
		array[i] = array[i]+5;
	}

}
