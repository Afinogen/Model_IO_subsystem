/*
 * time.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef TIME_H_
#define TIME_H_

class Time
{
	public:
		Time();
		~Time();
		unsigned int GetTime() const;
		void IncTime();
	private:
		unsigned int time_;
};


#endif /* TIME_H_ */
