/*
 * AudioAnalyser2.h
 *
 *  Created on: 04.10.2012
 *      Author: mse
 */

#ifndef AUDIOANALYSER_H_
#define AUDIOANALYSER_H_

#include "IAudioAnalyser.h"

class AudioAnalyser: public IAudioAnalyser {
public:
	AudioAnalyser();
	virtual ~AudioAnalyser();
	virtual int * readAndTransform();
	void sampleAudio();
private:
	static const int FFT_SIZE = 64;
	static const int SIZE = 2 * FFT_SIZE;
	static const int sdvig = 32768; //DC bias of the ADC, approxim +2.5V. (kompensaciya post. sostavlyauschei).
	int fx[SIZE];
};

#endif /* AUDIOANALYSER2_H_ */
