/*
 * time.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "time.h"

Time::Time()
{
	time_=0;
}

Time::~Time()
{

}

void Time::IncTime()
{
	time_++;
}

unsigned int Time::GetTime() const
{
	return time_;
}


