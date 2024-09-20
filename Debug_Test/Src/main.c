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
