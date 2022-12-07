/*
 * global.h
 *
 *  Created on: Nov 8, 2022
 *      Author: MY-PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "input_reading.h"

#define INIT			1
#define AUTO_RED		2
#define AUTO_GREEN		3
#define AUTO_YELLOW		4
#define RED_GREEN		5
#define RED_YELLOW		6
#define GREEN_RED		7
#define YELLOW_RED		8

extern int status;
extern int mode;
extern int CYCLE;
extern int redDuration;
extern int yellowDuration;
extern int greenDuration;
extern int counter1;
extern int counter2;
extern int tmp;

#endif /* INC_GLOBAL_H_ */
