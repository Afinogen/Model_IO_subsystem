/*
 * valve.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef VALVE_H_
#define VALVE_H_

#include "subject_drive.h"
#include "time.h"

//Клапан
class Valve: public Time
{
	public:
		Valve(SubjectDrive*);
		~Valve();
		void setState(int state);
		int GetState() const;
	private:
		SubjectDrive *subject_drive_;
		int state_;
};


#endif /* VALVE_H_ */
