/*
 * main.c
 *
 *  Created on	: Mar 28, 2020
 *  Version		: 1.0.0
 *      Author	: Ahmed El-Gaafarwy
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"

#include "../LIBRARY/AVR_REG.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/Seven_Segment_int.h"

#include <util/delay.h>



int main(void)
{
	SEV_enuInit();

	while(1)
	{
		_delay_ms(2000);
		SEV_enuSetCommonPin(FIRST_SEGMENT);
		for (u8 i=0;i<10;i++)
		{
			SEV_enuDisplayNumber(i,FIRST_SEGMENT);
			SEV_enuDisplayNumber(9-i,SECOND_SEGMENT);
			_delay_ms(1000);
		}
		SEV_enuTurnOFF_Segment(FIRST_SEGMENT);
		SEV_enuTurnOFF_Segment(SECOND_SEGMENT);
		_delay_ms(2000);
		SEV_enuSetCommonPin(FIRST_SEGMENT);
		SEV_enuTurnON_DotPin(FIRST_SEGMENT);
		SEV_enuTurnON_DotPin(SECOND_SEGMENT);
		_delay_ms(2000);
		SEV_enuTurnOFF_DotPin(FIRST_SEGMENT);
		SEV_enuTurnOFF_DotPin(SECOND_SEGMENT);
	}
	return 0;
}
