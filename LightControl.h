/*
 * LightControl.h
 *
 *  Created on: 01.10.2012
 *      Author: mse
 */

#ifndef LIGHTCONTROL_H_
#define LIGHTCONTROL_H_

#include "ButtonEvent.h"
#include "ICallbackEventHandler.h"
#include "ILightControlStrategy.h"
#include "IAudioAnalyser.h"

class LightControl: public ICallbackEventHandler{
public:
	LightControl();
	virtual ~LightControl();
	void testSpotlight();
	void onLoop();
	virtual void handleEvent(int btnEvent);

private:
	ButtonEvent* buttonEvent;
	IAudioAnalyser* analyser;
	ILightControlStrategy* lightorganStrategy;
	ILightControlStrategy* staticStrategy1,* staticStrategy2,* staticStrategy3;
	int state;
	enum states{LIGHTORGAN=0,STATIC_BLUE=1,STATIC_RED=2,STATIC_GREEN};
};

#endif /* LIGHTCONTROL_H_ */
