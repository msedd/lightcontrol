/*
 * StaticLightControlStrategy.h
 *
 *  Created on: 01.10.2012
 *      Author: mse
 */

#ifndef STATICLIGHTCONTROLSTRATEGY_H_
#define STATICLIGHTCONTROLSTRATEGY_H_

#include "ILightControlStrategy.h"

class StaticLightControlStrategy: public ILightControlStrategy {
public:
	StaticLightControlStrategy(int* color);
	virtual ~StaticLightControlStrategy();
	virtual void show();


private:
	int* colorArray;
};

#endif /* STATICLIGHTCONTROLSTRATEGY_H_ */
