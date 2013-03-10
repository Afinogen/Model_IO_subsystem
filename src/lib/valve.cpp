/*
 * valve.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "valve.h"

//Конструктор клапана
Valve::Valve(SubjectDrive *pSubjectDrive)
{
	subject_drive_=pSubjectDrive;
	state_=-1;
}

Valve::~Valve()
{

}

void Valve::setState(int state)
{
	state_=state;
}

int Valve::GetState() const
{
	return state_;
}
