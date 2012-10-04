/*
 * AudioAnalyser2.cpp
 *
 *  Created on: 04.10.2012
 *      Author: mse
 */

#include "AudioAnalyser.h"
#include "fft.h"
#include <Arduino.h>

AudioAnalyser::AudioAnalyser() {
	// TODO Auto-generated constructor stub

}

AudioAnalyser::~AudioAnalyser() {
	// TODO Auto-generated destructor stub
}

void AudioAnalyser::sampleAudio() {
	int i;

	int x[SIZE];
	ADCSRA = 0x87;
	// turn on adc, freq = 1/128 , 125 kHz.
	ADMUX = 0x60;
	//Bit 5  ADLAR: ADC Left Adjust Result
	ADCSRA |= (1 << ADSC);
	//    while((ADCSRA&(1<<ADIF)) == 0); //Discard first conversion result.
	while (!(ADCSRA & 0x10))
		;

	for (i = 0; i < SIZE; i++) {
		ADCSRA |= (1 << ADSC);
		//    while((ADCSRA&(1<<ADIF)) == 0);
		while (!(ADCSRA & 0x10))
			;

		x[i] = ADCL;
		x[i] += (ADCH << 8);
	}

	ADCSRA = 0x00;

	for (i = 0; i < SIZE; i++) {
		x[i] -= sdvig;
		if (i & 0x01)
			fx[(SIZE + i) >> 1] = x[i];
		else
			fx[i >> 1] = x[i];
	}
}

int * AudioAnalyser::readAndTransform() {

	sampleAudio();

	fix_fftr(fx, log2N);

	// Calculation of the magnitude:
	for (int i = 0; i < N / 2; i++) {
		fx[i] = sqrt(
				(long) fx[i] * (long) fx[i]
						+ (long) fx[i + N / 2] * (long) fx[i + N / 2]);
	}

	return fx;

}
