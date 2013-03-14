/*
 * time.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef TIME_H_
#define TIME_H_

//Nfqvth
class Time
{
	public:
		Time();
		~Time();
		unsigned int GetTime() const;	//Получение текущего состояния тацмера
		void IncTime();	//Инкримет таймера
	private:
		unsigned int time_;	//время
};


#endif /* TIME_H_ */
