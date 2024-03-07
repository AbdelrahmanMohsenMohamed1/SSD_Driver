/*
 * SSD_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "SSD_Interface.h"
#include "SSD_Private.h"

void H_SSD_Void_SSDInit(void)
{
	M_DIO_Void_SetPinDirection(SSD_LED_A_PORT,SSD_LED_A_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_LED_B_PORT,SSD_LED_B_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_LED_C_PORT,SSD_LED_C_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_LED_D_PORT,SSD_LED_D_PIN,OUTPUT);


	M_DIO_Void_SetPinDirection(SSD_1_EN_PORT,SSD_1_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_2_EN_PORT,SSD_2_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_3_EN_PORT,SSD_3_EN_PIN,OUTPUT);
	M_DIO_Void_SetPinDirection(SSD_4_EN_PORT,SSD_4_EN_PIN,OUTPUT);

	M_DIO_Void_SetPinValue(SSD_1_EN_PORT,SSD_1_EN_PIN,HIGH);
	M_DIO_Void_SetPinValue(SSD_2_EN_PORT,SSD_2_EN_PIN,HIGH);
	M_DIO_Void_SetPinValue(SSD_3_EN_PORT,SSD_3_EN_PIN,HIGH);
	M_DIO_Void_SetPinValue(SSD_4_EN_PORT,SSD_4_EN_PIN,HIGH);
}
void H_SSD_Void_SSDDisplay(u32 Copy_U8_Num)
{
	u16 Local_U16_Counter = 0;
	for(Local_U16_Counter=0;Local_U16_Counter<500;Local_U16_Counter++)
	{
		u8 Local_U8_Ones =  Copy_U8_Num % 10;
		u8 Local_U8_Tens = (Copy_U8_Num%100)/ 10;
		u8 Local_U8_Hun  = (Copy_U8_Num%1000)/ 100;
		u8 Local_U8_Thou = Copy_U8_Num / 1000;

		H_SSD_Void_SSDDigitDisplay(Local_U8_Ones);
		M_DIO_Void_SetPinValue(SSD_1_EN_PORT,SSD_1_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD_1_EN_PORT,SSD_1_EN_PIN,HIGH);

		H_SSD_Void_SSDDigitDisplay(Local_U8_Tens);
		M_DIO_Void_SetPinValue(SSD_2_EN_PORT,SSD_2_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD_2_EN_PORT,SSD_2_EN_PIN,HIGH);

		H_SSD_Void_SSDDigitDisplay(Local_U8_Hun);
		M_DIO_Void_SetPinValue(SSD_3_EN_PORT,SSD_3_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD_3_EN_PORT,SSD_3_EN_PIN,HIGH);

		H_SSD_Void_SSDDigitDisplay(Local_U8_Thou);
		M_DIO_Void_SetPinValue(SSD_4_EN_PORT,SSD_4_EN_PIN,LOW);
		_delay_ms(1);
		M_DIO_Void_SetPinValue(SSD_4_EN_PORT,SSD_4_EN_PIN,HIGH);
	}
}

static void H_SSD_Void_SSDDigitDisplay(u32 Copy_U8_Num)
{
	switch(Copy_U8_Num)
	{
	case 0:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);

		break;
	case 1:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);

		break;
	case 2:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);

		break;
	case 3:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);

		break;
	case 4:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);

		break;
	case 5:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);

		break;
	case 6:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);

		break;
	case 7:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,LOW);


		break;
	case 8:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);

		break;
	case 9:
		M_DIO_Void_SetPinValue(SSD_LED_A_PORT,SSD_LED_A_PIN,HIGH);
		M_DIO_Void_SetPinValue(SSD_LED_B_PORT,SSD_LED_B_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_C_PORT,SSD_LED_C_PIN,LOW);
		M_DIO_Void_SetPinValue(SSD_LED_D_PORT,SSD_LED_D_PIN,HIGH);

	}
}
