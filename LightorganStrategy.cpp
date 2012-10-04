/*
 * LightorganStrategy.cpp
 *
 *  Created on: 03.10.2012
 *      Author: mse
 */

#include "LightorganStrategy.h"
#include <Arduino.h>

LightorganStrategy::LightorganStrategy(IAudioAnalyser* pAnalyser) {
	analyser = pAnalyser;
	kdmp = 0.95; //Smoothing constant.
	minim = 0;
	// maxim = 32000;
	maxim = 12000;
	kary = 0.999; //AGC time constant.
	range = 3;
	oldvalue_ch1 = 0;
	oldvalue_ch2 = 0;
	oldvalue_ch3 = 0;
	oldvalue_ch4 = 0;

}

LightorganStrategy::~LightorganStrategy() {
}
void LightorganStrategy::show() {
	int value_ch1 = 0, value_ch2 = 0, value_ch3 = 0, value_ch4 = 0;

	int count = 0, vrem = 0;
	int * fx = analyser->readAndTransform();


	for (count = 1; count < 8; count++) {
		value_ch1 = value_ch1 + fx[count]; //Ch 1
	}

	for (count = 8; count < 16; count++) {
		value_ch2 = value_ch2 + fx[count]; //Ch 2
	}

	for (count = 16; count < 24; count++) {
		value_ch3 = value_ch3 + fx[count]; //Cu 3
	}
	for (count = 24; count < 32; count++) {
		value_ch4 = value_ch4 + fx[count]; //Ch 4
	}

	//Smoothing, so it fall down gradually.
	if (value_ch1 < (oldvalue_ch1 * kdmp))
		value_ch1 = (oldvalue_ch1 * kdmp);
	if (value_ch2 < (oldvalue_ch2 * kdmp))
		value_ch2 = (oldvalue_ch2 * kdmp);
	if (value_ch3 < (oldvalue_ch3 * kdmp))
		value_ch3 = (oldvalue_ch3 * kdmp);
	if (value_ch4 < (oldvalue_ch4 * kdmp))
		value_ch4 = (oldvalue_ch4 * kdmp);

	//Visual Display AGC for all three band
	if (value_ch1 > maxim || value_ch2 > maxim || value_ch3 > maxim
			|| value_ch4 > maxim) {
		vrem = max( value_ch1, value_ch2 );
		vrem = max( vrem, value_ch3 );
		vrem = max( vrem, value_ch4 );
		maxim = vrem;
	} else {
		maxim *= kary;
	}

	int value = map(value_ch1, minim, maxim, 0, range);
	int thisLed = 1;
	if (thisLed < value) {
		digitalWrite(2, HIGH);
	} else {
		digitalWrite(2, LOW);
	}

	value = map(value_ch2, minim, maxim, 0, range);
	thisLed = 0;
	if (thisLed < value) {
		digitalWrite(6, HIGH);
	} else {
		digitalWrite(6, LOW);
	}

	value = map(value_ch3, minim, maxim, 0, range);
	thisLed = 0;
	if (thisLed < value) {
		digitalWrite(10, HIGH);
	} else {
		digitalWrite(10, LOW);
	}

	value = map(value_ch4, minim, maxim, 0, range);
	thisLed = 0;
	if (thisLed < value) {
		digitalWrite(12, HIGH);
		digitalWrite(13, HIGH);
	} else {
		digitalWrite(12, LOW);
		digitalWrite(13, LOW);
	}

	oldvalue_ch1 = value_ch1;
	oldvalue_ch2 = value_ch2;
	oldvalue_ch3 = value_ch3;
	oldvalue_ch4 = value_ch4;


}

