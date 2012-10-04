/*
 * CallbackEventHandler.h
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#ifndef CALLBACKEVENTHANDLER_H_
#define CALLBACKEVENTHANDLER_H_

class ICallbackEventHandler {
public:
	virtual ~ICallbackEventHandler(){};
	virtual void handleEvent(int bthEvent)=0;
};

#endif /* CALLBACKEVENTHANDLER_H_ */
