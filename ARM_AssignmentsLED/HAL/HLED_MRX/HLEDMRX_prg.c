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
MGPIO_enSetPinDirection(LEDMRX_u8ROW0,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW3,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW4,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW5,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW6,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8ROW7,GPIO_u8OUT_PUSH_PULL_2MHZ);
//col
MGPIO_enSetPinDirection(LEDMRX_u8COL0,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL1,GPIO_u8OUT_PUSH_PULL_2MHZ);
MGPIO_enSetPinDirection(LEDMRX_u8COL0,GPIO_u8OUT_PUSH_PULL_2MHZ);
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

void HLEDMRX_voidDisplat(u8 *Copy_pu8Data)
{
/*****************col[0]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[0]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL0, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
/*****************col[1]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[1]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL1, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
/*****************col[2]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[2]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL2, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
/*****************col[3]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[3]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL3, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
/*****************col[4]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[4]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL4, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
/*****************col[5]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[5]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL5, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
/*****************col[6]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[6]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL6, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
/*****************col[7]************************/
/*Disable all columns*/
	LEDMRX_voidDisableALLColumns();
/*set Value*/
	LEDMRX_voidSetRowValues(Copy_pu8Data[7]);
/*Enable col 0 */
MGPIO_enSetPinValue(LEDMRX_u8COL7, GPIO_u8LOW);
MSTK_enSetBusyWait(3);
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
	MGPIO_enSetPinValue(LEDMRX_u8ROW0, GPIO_u8LOW);
	Local_u8BIT=GET_BIT(Copy_u8Data,1);
	MGPIO_enSetPinValue(LEDMRX_u8ROW1, GPIO_u8LOW);
	Local_u8BIT=GET_BIT(Copy_u8Data,2);
	MGPIO_enSetPinValue(LEDMRX_u8ROW2, GPIO_u8LOW);
	Local_u8BIT=GET_BIT(Copy_u8Data,3);
	MGPIO_enSetPinValue(LEDMRX_u8ROW3, GPIO_u8LOW);
	Local_u8BIT=GET_BIT(Copy_u8Data,4);
	MGPIO_enSetPinValue(LEDMRX_u8ROW4, GPIO_u8LOW);
	Local_u8BIT=GET_BIT(Copy_u8Data,5);
	MGPIO_enSetPinValue(LEDMRX_u8ROW5, GPIO_u8LOW);
	Local_u8BIT=GET_BIT(Copy_u8Data,6);
	MGPIO_enSetPinValue(LEDMRX_u8ROW6, GPIO_u8LOW);
	Local_u8BIT=GET_BIT(Copy_u8Data,7);
	MGPIO_enSetPinValue(LEDMRX_u8ROW7, GPIO_u8LOW);




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
