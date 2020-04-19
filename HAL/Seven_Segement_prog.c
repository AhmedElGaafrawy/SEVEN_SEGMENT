/*
 * Seven_Segement_prog.c
 *
 *  Created on : Mar 28, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafrawy
 */
/*****************************************************************************/
/**                                                                         **/
/**                         Libraries Inclusion                             **/
/**             standard types  -  bit math  -  error states                **/
/*****************************************************************************/
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
/*****************************************************************************/
/**                                                                         **/
/**                       AVR atmega 32 Library                             **/
/**                                                                         **/
/*****************************************************************************/
#include "../LIBRARY/AVR_REG.h"
/*****************************************************************************/
/**                                                                         **/
/**                      MCAL Libraries Inclusion                           **/
/**        DIO private  -  DIO configuration  -  DIO interface              **/
/*****************************************************************************/
#include "../MCAL/DIO_priv.h"
#include "../MCAL/DIO_config.h"
#include "../MCAL/DIO_int.h"
/*****************************************************************************/
/**                                                                         **/
/**                      HAL Libraries Inclusion                            **/
/**           Seven Segment private  -  Seven Segment configuration         **/
/*****************************************************************************/
#include "Seven_Segment_priv.h"
#include "Seven_Segment_config.h"
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/**                                                                         **/
/**            Prototype of Function for internal usage                     **/
/**                                                                         **/
/*****************************************************************************/
ERROR_STATES SEV_enuTurnOFF_Segment(u8 Copy_u8SevenOrder);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuInit.                                          **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : void.                                                 **/
/**	Functionality   : Setting All Seven segments Pins output and turned off.**/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuInit(void)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	for (u8 Copy_u8Iter=0; Copy_u8Iter<NUM_OF_SEGMENT; Copy_u8Iter ++ )
	{
		DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_A_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_A_PIN,PIN_OUTPUT);
		DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_B_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_B_PIN,PIN_OUTPUT);
		DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_C_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_C_PIN,PIN_OUTPUT);
		DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_D_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_D_PIN,PIN_OUTPUT);
		DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_E_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_E_PIN,PIN_OUTPUT);
		DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_F_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_F_PIN,PIN_OUTPUT);
		DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_G_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_G_PIN,PIN_OUTPUT);

		if (SEV_strNumderOfSev[Copy_u8Iter].u8_DOT_STATE == CONNECTED)
		{
			DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_DOT_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_DOT_PIN,PIN_OUTPUT);
		}
		if (SEV_strNumderOfSev[Copy_u8Iter].u8_CMN_STATE == CONNECTED)
		{
			DIO_enuSetPinDirection(SEV_strNumderOfSev[Copy_u8Iter].u8_CMN_PORT,SEV_strNumderOfSev[Copy_u8Iter].u8_CMN_PIN,PIN_OUTPUT);
		}
		SEV_enuTurnOFF_Segment(Copy_u8Iter);
		//SEV_enuTurnOFF_DotPin(Copy_u8Iter);
		//SEV_enuClearCommonPin(Copy_u8Iter);
		error_enuState =ES_OK;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuDisplayNumber.                                 **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Segment order to Display on and displayed Number.     **/
/**	Functionality   : Displaying a specific Number to Specific Segment.     **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuDisplayNumber(u8 Copy_u8Number , u8 Copy_u8SevenOrder)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	if (Copy_u8Number < (SEVEN_SEV+THREE_SEV))
	{
		if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_CATHODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PIN,!!((seg[Copy_u8Number]) & (ONE<<ZERO_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PIN,!!((seg[Copy_u8Number]) & (ONE<<ONE_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PIN,!!((seg[Copy_u8Number]) & (ONE<<TWO_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PIN,!!((seg[Copy_u8Number]) & (ONE<<THREE_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PIN,!!((seg[Copy_u8Number]) & (ONE<<FOUR_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PIN,!!((seg[Copy_u8Number]) & (ONE<<FIVE_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PIN,!!((seg[Copy_u8Number]) & (ONE<<SIX_SEV)));
			error_enuState = ES_OK;
		}
		else if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_ANODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PIN,!((seg[Copy_u8Number]) & (ONE<<ZERO_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PIN,!((seg[Copy_u8Number]) & (ONE<<ONE_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PIN,!((seg[Copy_u8Number]) & (ONE<<TWO_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PIN,!((seg[Copy_u8Number]) & (ONE<<THREE_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PIN,!((seg[Copy_u8Number]) & (ONE<<FOUR_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PIN,!((seg[Copy_u8Number]) & (ONE<<FIVE_SEV)));
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PIN,!((seg[Copy_u8Number]) & (ONE<<SIX_SEV)));
			error_enuState = ES_OK;
		}
		else
		{
			error_enuState = ES_NOT_OK;
		}
	}
	else
	{
		error_enuState = ES_OUT_OF_RANGE;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuTurnON_DotPin.                                 **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Segment order to Display.                             **/
/**	Functionality   : Displaying the Dot Led to Specific Segment.           **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuTurnON_DotPin(u8 Copy_u8SevenOrder)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_STATE == CONNECTED)
	{
		if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_CATHODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PIN,PIN_HIGH);
			error_enuState = ES_OK;
		}
		else if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_ANODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PIN,PIN_LOW);
			error_enuState = ES_OK;
		}
		else
		{
			error_enuState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		error_enuState = ES_NOT_SELECTED;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuTurnOFF_DotPin.                                **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Segment order to Display.                             **/
/**	Functionality   : Turning off the Dot Led to Specific Segment.          **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuTurnOFF_DotPin(u8 Copy_u8SevenOrder)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_STATE == CONNECTED)
	{
		if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_CATHODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PIN,PIN_LOW);
			error_enuState = ES_OK;
		}
		else if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_ANODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_PIN,PIN_HIGH);
			error_enuState = ES_OK;
		}
		else
		{
			error_enuState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		error_enuState = ES_NOT_SELECTED;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuSetCommonPin.                                  **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Segment order to Display.                             **/
/**	Functionality   : Enabling the Common Pin to Specific Segment.          **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuSetCommonPin(u8 Copy_u8SevenOrder)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_STATE == CONNECTED)
	{
		if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_CATHODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PIN,PIN_LOW);
			error_enuState = ES_OK;
		}
		else if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_ANODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PIN,PIN_HIGH);
			error_enuState = ES_OK;
		}
		else
		{
			error_enuState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		error_enuState = ES_NOT_SELECTED;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuClearCommonPin.                                **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Segment order to Display.                             **/
/**	Functionality   : Disabling the Common Pin to Specific Segment.         **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuClearCommonPin(u8 Copy_u8SevenOrder)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_STATE == CONNECTED)
	{
		if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_CATHODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PIN,PIN_HIGH);
			error_enuState = ES_OK;
		}
		else if(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_ANODE)
		{
			DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_PIN,PIN_LOW);
			error_enuState = ES_OK;
		}
		else
		{
			error_enuState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		error_enuState = ES_NOT_SELECTED;
	}
	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/**	Function Name   : SEV_enuTurnOFF_Segment.                               **/
/**	Return Type     : ERROR_STATES enum.                                    **/
/**	Arguments       : Segment order to Display.                             **/
/**	Functionality   : Turning off a Specific Segment.                       **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES SEV_enuTurnOFF_Segment(u8 Copy_u8SevenOrder)
{
	ERROR_STATES error_enuState = ES_NOT_OK;
	if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_CMN_STATE == CONNECTED)
	{
		SEV_enuClearCommonPin(Copy_u8SevenOrder);
	}
	if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_DOT_STATE == CONNECTED)
	{
		SEV_enuTurnOFF_DotPin(Copy_u8SevenOrder);
	}

	if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_CATHODE)
	{
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PIN,PIN_LOW);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PIN,PIN_LOW);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PIN,PIN_LOW);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PIN,PIN_LOW);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PIN,PIN_LOW);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PIN,PIN_LOW);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PIN,PIN_LOW);
		error_enuState = ES_OK;
	}
	else if (SEV_strNumderOfSev[Copy_u8SevenOrder].u8_SEV_TYPE == CMN_ANODE)
	{
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_A_PIN,PIN_HIGH);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_B_PIN,PIN_HIGH);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_C_PIN,PIN_HIGH);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_D_PIN,PIN_HIGH);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_E_PIN,PIN_HIGH);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_F_PIN,PIN_HIGH);
		DIO_enuSetPinValue(SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PORT,SEV_strNumderOfSev[Copy_u8SevenOrder].u8_G_PIN,PIN_HIGH);
		error_enuState = ES_OK;
	}
	else
	{
		error_enuState = ES_OUT_OF_RANGE;
	}

	return error_enuState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
