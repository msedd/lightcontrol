/*
 * LightControl.cpp
 *
 *  Created on: 01.10.2012
 *      Author: mse
 */

#include <Arduino.h>
#include "LightControl.h"
#include "StaticLightControlStrategy.h"
#include "AudioAnalyser.h"
#include "LightorganStrategy.h"
#include <SerialDebug.h>

LightControl::LightControl() {
	//analog read on Pin 1
	buttonEvent = new ButtonEvent(1);
	buttonEvent->registerCallBackEventHandler(this);

	analyser = new AudioAnalyser();
	lightorganStrategy = new LightorganStrategy(analyser);
	staticStrategy1 = new StaticLightControlStrategy(
			ILightControlStrategy::COLOR_BLUE);
	staticStrategy2 = new StaticLightControlStrategy(
			ILightControlStrategy::COLOR_RED);
	staticStrategy3 = new StaticLightControlStrategy(
			ILightControlStrategy::COLOR_BLUE_GREEN);
	state = LIGHTORGAN;

}

LightControl::~LightControl() {
	delete buttonEvent;
	delete analyser;
	delete lightorganStrategy;
	delete staticStrategy1;
	delete staticStrategy2;
	delete staticStrategy3;
}
void LightControl::testSpotlight() {
	for (int aa = 2; aa < 14; aa++) {
		pinMode(aa, OUTPUT);
		digitalWrite(aa, HIGH);
		delay(500);
		digitalWrite(aa, LOW);
	}
}
void LightControl::onLoop() {

	buttonEvent->readAndDispatch();
	char buffer[50];
	sprintf(buffer, "State: %d", state);
	SerialDebugger.debug(STATUSUPDATE, "onLoop", buffer);
	switch (state) {
	case LIGHTORGAN:
		if (lightorganStrategy != 0) {
			lightorganStrategy->show();
		}
		break;
	case STATIC_BLUE:
		if (staticStrategy1 != 0) {
			staticStrategy1->show();
		}
		break;
	case STATIC_RED:
		if (staticStrategy2 != 0) {
			staticStrategy2->show();
		}
		break;
	case STATIC_GREEN:
		if (staticStrategy3 != 0) {
			staticStrategy3->show();
		}
		break;
	}

}
void LightControl::handleEvent(int event) {
	state++;
	if (state == 4) {
		state = 0;
	}

}
