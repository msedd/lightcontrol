/*
 * IAudioAnalyser.h
 *
 *  Created on: 01.10.2012
 *      Author: mse
 */

#ifndef IAUDIOANALYSER_H_
#define IAUDIOANALYSER_H_

class IAudioAnalyser {
public:
	virtual ~IAudioAnalyser(){};
	virtual int * readAndTransform()=0;
};

#endif /* IAUDIOANALYSER_H_ */
