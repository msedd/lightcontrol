/*
 * LightorganStrategy.h
 *
 *  Created on: 03.10.2012
 *      Author: mse
 */

#ifndef LIGHTORGANSTRATEGY_H_
#define LIGHTORGANSTRATEGY_H_

#include "IAudioAnalyser.h"
#include "ILightControlStrategy.h"

class LightorganStrategy : public ILightControlStrategy {
public:
	LightorganStrategy(IAudioAnalyser* pAnalyser);
	virtual ~LightorganStrategy();
	virtual void show();

private:
	IAudioAnalyser* analyser;
	float kdmp;
	int minim;
	int maxim;
	float kary;
	int range;
	int oldvalue_ch1, oldvalue_ch2, oldvalue_ch3, oldvalue_ch4;
};

#endif /* LIGHTORGANSTRATEGY_H_ */
