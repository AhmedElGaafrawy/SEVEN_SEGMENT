/*
 * Seven_Segment_config.h
 *
 *  Created on : Mar 28, 2020
 *  Version    : 1.0.1
 *  Author     : Ahmed El-Gaafarwy
 */

#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

/*****************************************************************************/
/**            write here how many seven segments you connect               **/
/*****************************************************************************/
#define 		NUM_OF_SEGMENT					2
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/**                                                                         **/
/**         Definitions of Seven Segment Data as the following :            **/
/**        (you must follow the same sequence of Data arrangement)          **/
/**                                                                         **/
/**   u8_A_PORT,  u8_A_PIN,  u8_B_PORT,  u8_B_PIN,  u8_C_PORT,  u8_C_PIN,   **/
/**   u8_D_PORT,  u8_D_PIN,  u8_E_PORT,  u8_E_PIN,  u8_F_PORT,  u8_F_PIN,   **/
/**                                                                         **/
/**   u8_G_PORT,  u8_G_PIN,  u8_DOT_PORT,           u8_DOT_PIN,             **/
/**   u8_CMN_PORT,                       u8_CMN_PIN,                        **/
/**                                                                         **/
/**   u8_SEV_TYPE,           u8_DOT_STATE,          u8_CMN_STATE            **/
/*****************************************************************************/
/*****************************************************************************/
SEV_str SEV_strNumderOfSev [NUM_OF_SEGMENT]=
{
	{
	 DIO_PORTA , DIO_PIN0 , DIO_PORTA , DIO_PIN1 , DIO_PORTA , DIO_PIN2,
	 DIO_PORTA , DIO_PIN3 , DIO_PORTA , DIO_PIN4 , DIO_PORTA , DIO_PIN5,
	 DIO_PORTA , DIO_PIN6 , DIO_PORTA , DIO_PIN7 , DIO_PORTC , DIO_PIN0,
	 CMN_ANODE , 			CONNECTED ,			   CONNECTED
	},/*1st seven segment*/

	{DIO_PORTB , DIO_PIN0 , DIO_PORTB , DIO_PIN1 , DIO_PORTB , DIO_PIN2,
	 DIO_PORTB , DIO_PIN3 , DIO_PORTB , DIO_PIN4 , DIO_PORTB , DIO_PIN5,
	 DIO_PORTB , DIO_PIN6 , DIO_PORTB , DIO_PIN7 , DIO_PORTC , DIO_PIN1,
	 CMN_CATHODE,CONNECTED,NOT_CONNECTED
	}/*2nd seven segment*/

};
/*****************************************************************************/
/*****************************************************************************/

#endif /* SEVEN_SEGMENT_CONFIG_H_ */
