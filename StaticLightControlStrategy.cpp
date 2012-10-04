/*
 * StaticLightControlStrategy.cpp
 *
 *  Created on: 01.10.2012
 *      Author: mse
 */

#include "StaticLightControlStrategy.h"
#include <Arduino.h>

int ILightControlStrategy::COLOR_BLUE[LED_SIZE] = {1,0,0,1,0,0,1,0,0,1,0,0};
int ILightControlStrategy::COLOR_RED [LED_SIZE] = {0,1,0,0,1,0,0,1,0,0,1,0};
int ILightControlStrategy::COLOR_GREEN [LED_SIZE] = {0,0,1,0,0,1,0,0,1,0,0,1};
int ILightControlStrategy::COLOR_BLUE_GREEN [LED_SIZE] = {1,0,0,0,0,1,1,0,0,0,0,1};
int ILightControlStrategy::COLOR_BLUE_RED [LED_SIZE] = {1,0,0,0,1,0,1,0,0,0,1,0};

StaticLightControlStrategy::StaticLightControlStrategy(int* color) {
	colorArray = color;

}

StaticLightControlStrategy::~StaticLightControlStrategy() {
}
void StaticLightControlStrategy::show() {

	for (int aa = 0; aa < ILightControlStrategy::LED_SIZE; aa++) {

		if (colorArray[aa] == 1) {
			digitalWrite(aa + ILightControlStrategy::AVR_DIO_START, HIGH);
		} else {
			digitalWrite(aa + ILightControlStrategy::AVR_DIO_START, LOW);
		}
	}

}

