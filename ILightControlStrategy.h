/*
 * ILightControlStrategy.h
 *
 *  Created on: 01.10.2012
 *      Author: mse
 */

#ifndef ILIGHTCONTROLSTRATEGY_H_
#define ILIGHTCONTROLSTRATEGY_H_

class ILightControlStrategy {
public:
	static const int LED_SIZE = 12;
	static const int AVR_DIO_START = 2;
	static int COLOR_BLUE[];
	static int COLOR_RED[];
	static int COLOR_GREEN [];
	static int COLOR_BLUE_GREEN [];
	static int COLOR_BLUE_RED [];


	virtual ~ILightControlStrategy(){};
	virtual void show()=0;

};



#endif /* ILIGHTCONTROLSTRATEGY_H_ */


