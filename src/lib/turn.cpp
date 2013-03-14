/*
 * turn.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "turn.h"

//конструктор очереди
Turn::Turn()
{

}

Turn::~Turn()
{

}
//получение последней заявки
Client *Turn::GetLastClient() const
{
	return GetData(SizeContainer()-1);
}
//Получение первой заявки
Client *Turn::GetFirstClient() const
{
    return GetData(0);
}



