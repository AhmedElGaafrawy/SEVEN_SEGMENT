/*
 * DIO_int.h
 *
 *  Created on: Apr 2, 2020
 *      Author: hp
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_


/*****************************************************************************/
/**********   Use these enumerators to pass them to your function   **********/
/*****************************************************************************/

enum
{
	PORT_A,			PORT_B,			PORT_C,			PORT_D,

	PIN0=0,			PIN1,			PIN2,			PIN3,
	PIN4,			PIN5,			PIN6,			PIN7,
	PIN8,			PIN9,			PIN10,			PIN11,
	PIN12,			PIN13,			PIN14,			PIN15,
	PIN16,			PIN17,			PIN18,			PIN19,
	PIN20,			PIN21,			PIN22,			PIN23,
	PIN24,			PIN25,			PIN26,			PIN27,
	PIN28,			PIN29,			PIN30,			PIN31,

	DIO_PIN_INPUT=0,	DIO_PIN_OUTPUT,
	DIO_PIN_LOW=0,		DIO_PIN_HIGH,

	MASKED_ALL_PORT_INPUT=0,				MASKED_ALL_PORT_OUTPUT=0xFF,
	MASKED_ALL_PORT_LOW=0,					MASKED_ALL_PORT_HIGH=0xFF,

}DIO;

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/**************   Use these function to configure DIO by PINS   **************/
/*****************************************************************************/


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_PINS_enuInit. 									**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: void.					   								**/
/**	Functionality	: Setting the initial direction of DIO pins. 		    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_PINS_enuInit			(void);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_PINS_enuSetPinDirection.							**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Pin number and Direction(Input or Output).   			**/
/**	Functionality	: Setting the direction of specific pin at run time.    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_PINS_enuSetPinDirection(u8 Copy_u8PinID , u8 Copy_u8PinDirection);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_PINS_enuSetPinValue.								**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Pin number and Value(High or Low).		   			**/
/**	Functionality	: Setting the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_PINS_enuSetPinValue	(u8 Copy_u8PinID , u8 Copy_u8PinValue);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_PINS_enuTogglePin.								**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Pin number.								   			**/
/**	Functionality	: Toggling the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_PINS_enuTogglePin		( u8 Copy_u8PinID );



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_PINS_enuGetPinValue.								**/
/**	Return Type		: ERROR_STATES enum and The the pin value as a pointer. **/
/**	Arguments		: Pin number.								   			**/
/**	Functionality	: Getting the value of specific pin at run time		    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_PINS_enuGetPinValue	(u8 Copy_u8PinID , u8 * Copy_Pu8PinValue);

/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*************   Use these function to  configure DIO by PORTS   *************/
/*****************************************************************************/


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuSetPinDirection.								**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Port and Pin number and Direction(Input or output).	**/
/**	Functionality	: Setting the direction of specific pin at run time.    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuSetPinDirection 	(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinDirection);



/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuSetPinValue.									**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Port and Pin number and Value(High or Low).			**/
/**	Functionality	: Setting the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuSetPinValue			(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuTogglePinValue.								**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Port and Pin number.									**/
/**	Functionality	: Toggling the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuTogglePinValue		(u8 Copy_u8PortID , u8 Copy_u8PinID );


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuGetPinValue.									**/
/**	Return Type		: ERROR_STATES enum and The the pin value as a pointer. **/
/**	Arguments		: Port and Pin number.						   			**/
/**	Functionality	: Getting the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuGetPinValue			(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_Pu8PinValue);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuSetPortDirection.								**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Port number and the value of Direction.				**/
/**	Functionality	: Setting the direction of specific port at run time.   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuSetPortDirection 	(u8 Copy_u8PortID , u8 Copy_u8PortDirection);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuSetPortValue.									**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Port number and the Value.							**/
/**	Functionality	: Setting the value of specific port at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuSetPortValue		(u8 Copy_u8PortID , u8 Copy_u8PortValue);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuTogglePortValue.								**/
/**	Return Type		: ERROR_STATES enum.					   		   		**/
/**	Arguments		: Port number.											**/
/**	Functionality	: Toggling the value of specific port at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuTogglePortValue		(u8 Copy_u8PortID);


/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: DIO_enuGetPortValue.									**/
/**	Return Type		: ERROR_STATES enum and The the port value as a pointer.**/
/**	Arguments		: Port number.								   			**/
/**	Functionality	: Getting the value of specific port at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES DIO_enuGetPortValue		(u8 Copy_u8PortID , u8 * Copy_Pu8PortValue);

/*****************************************************************************/
/*****************************************************************************/


#endif /* DIO_INT_H_ */
