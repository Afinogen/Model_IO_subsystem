/*
 * time.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "time.h"

//Конструктор таймера
Time::Time()
{
	time_=0;
}

Time::~Time()
{

}
//Инкримет таймера
void Time::IncTime()
{
	time_++;
}
//Получение текущего состояния тацмера
unsigned int Time::GetTime() const
{
	return time_;
}


