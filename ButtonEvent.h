/*
 * ButtonEvent.h
 *
 *  Created on: 19.06.2012
 *      Author: mse
 */

#ifndef BUTTONEVENT_H_
#define BUTTONEVENT_H_

#include "ICallbackEventHandler.h"
#include "Arduino.h"

class ButtonEvent {
public:
	ButtonEvent(int aAnalogInput);
	virtual ~ButtonEvent();
	void readAndDispatch();
	void registerCallBackEventHandler(ICallbackEventHandler* eventhandler) {
		callback = eventhandler;
	}
	enum BtnKey {
		btnRIGHT, btnUP, btnDOWN, btnLEFT, btnSELECT, btnNONE
	};
private:
	int analogInput;
	int key;
	int oldkey;

	ICallbackEventHandler* callback;
	int transform(unsigned int input);
};

#endif /* BUTTONEVENT_H_ */
