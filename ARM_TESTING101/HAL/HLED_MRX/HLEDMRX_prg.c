/*
 * HLEDMRX_prg.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Elrayes
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSTK_int.h"

#include "HLEDMRX_priv.h"
#include "HLEDMRX_config.h"
#include "HLED_int.h"

void HLEDMRX_voidInit(void)
{

//rows
MGPIO_enSetPinDirection(LEDMRX_u8ROW0,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW1,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW2,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW3,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW4,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW5,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW6,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW7,GPIO_u8OUT_PUSH_PULL_2MHZ);
//col
MGPIO_enSetPinDirection(LEDMRX_u8COL0,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL1,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL2,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL3,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL4,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL5,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL6,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL7,GPIO_u8OUT_PUSH_PULL_2MHZ);
//disable all colomns
//LEDMRX_voidDisableALLColumns();
//disable all rows
//LEDMRX_voidDisableALLRow();

}



void HLEDMRX_voidShiftDIsplay( u64 Copy_pu8Data[],u8 speed)
{
	u64 arr[8];
	for(u8 z=0;z<8;z++)
	{
		arr[z]=Copy_pu8Data[z];

	}

	u8 x;
for(u8 j=0;j<8;j++)//we have 8 elem
{
	arr[j]<<=7;

}
	for(u8 i=0;i<45;i++)
	{
		x=0;
		while(x<(10+speed)){
		/*****************col[0]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[0]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL0, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		/*****************col[1]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[1]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL1, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		/*****************col[2]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[2]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL2, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		/*****************col[3]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[3]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL3, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		/*****************col[4]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[4]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL4, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		/*****************col[5]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[5]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL5, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		/*****************col[6]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[6]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL6, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		/*****************col[7]************************/
		/*Disable all columns*/
			LEDMRX_voidDisableALLColumns();
		/*set Value*/
			LEDMRX_voidSetRowValues(arr[7]);
		/*Enable col 0 */
		MGPIO_enSetPinValue(LEDMRX_u8COL7, GPIO_u8LOW);
		MSTK_enSetBusyWait(2);
		//HLEDMRX_voidDisplat(arr);
		x++;
		}
		for(u8 j=0;j<8;j++)//we have 8 elem
		{
			arr[j]>>=1;

		}

	}



}


void HLEDMRX_voidDisplat(u8 *Copy_pu8Data)
{
/*****************col[0]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[0]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL0, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
/*****************col[1]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[1]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL1, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
/*****************col[2]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[2]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL2, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
/*****************col[3]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[3]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL3, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
/*****************col[4]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[4]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL4, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
/*****************col[5]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[5]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL5, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
/*****************col[6]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[6]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL6, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
/*****************col[7]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[7]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL7, GPIO_u8LOW);
MSTK_enSetBusyWait(2);
}

static void LEDMRX_voidDisableALLColumns(void)
{
	MGPIO_enSetPinValue(LEDMRX_u8COL0, GPIO_u8HIGH);
	MGPIO_enSetPinValue(LEDMRX_u8COL1, GPIO_u8HIGH);
	MGPIO_enSetPinValue(LEDMRX_u8COL2, GPIO_u8HIGH);
	MGPIO_enSetPinValue(LEDMRX_u8COL3, GPIO_u8HIGH);
	MGPIO_enSetPinValue(LEDMRX_u8COL4, GPIO_u8HIGH);
	MGPIO_enSetPinValue(LEDMRX_u8COL5, GPIO_u8HIGH);
	MGPIO_enSetPinValue(LEDMRX_u8COL6, GPIO_u8HIGH);
	MGPIO_enSetPinValue(LEDMRX_u8COL7, GPIO_u8HIGH);


}
static void LEDMRX_voidSetRowValues(u8 Copy_u8Data)
{
	u8 Local_u8BIT=0;
	Local_u8BIT=GET_BIT(Copy_u8Data,0);
	MGPIO_enSetPinValue(LEDMRX_u8ROW0, Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Data,1);
	MGPIO_enSetPinValue(LEDMRX_u8ROW1, Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Data,2);
	MGPIO_enSetPinValue(LEDMRX_u8ROW2, Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Data,3);
	MGPIO_enSetPinValue(LEDMRX_u8ROW3, Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Data,4);
	MGPIO_enSetPinValue(LEDMRX_u8ROW4, Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Data,5);
	MGPIO_enSetPinValue(LEDMRX_u8ROW5, Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Data,6);
	MGPIO_enSetPinValue(LEDMRX_u8ROW6, Local_u8BIT);
	Local_u8BIT=GET_BIT(Copy_u8Data,7);
	MGPIO_enSetPinValue(LEDMRX_u8ROW7, Local_u8BIT);




}
static void LEDMRX_voidDisableALLRow(void)
{
	MGPIO_enSetPinValue(LEDMRX_u8ROW0, GPIO_u8LOW);
	MGPIO_enSetPinValue(LEDMRX_u8ROW1, GPIO_u8LOW);
	MGPIO_enSetPinValue(LEDMRX_u8ROW2, GPIO_u8LOW);
	MGPIO_enSetPinValue(LEDMRX_u8ROW3, GPIO_u8LOW);
	MGPIO_enSetPinValue(LEDMRX_u8ROW4, GPIO_u8LOW);
	MGPIO_enSetPinValue(LEDMRX_u8ROW5, GPIO_u8LOW);
	MGPIO_enSetPinValue(LEDMRX_u8ROW6, GPIO_u8LOW);
	MGPIO_enSetPinValue(LEDMRX_u8ROW7, GPIO_u8LOW);


}
