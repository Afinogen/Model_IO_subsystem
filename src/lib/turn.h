/*
 * turn.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef TURN_H_
#define TURN_H_

#include "container.h"

//Очередь
class Turn: public Container
{
	public:
		Turn();
		~Turn();
		Client *GetLastClient() const;	//получение последней заявки
		Client *GetFirstClient() const;	//Получение первой заявки
	private:
};

#endif /* TURN_H_ */
