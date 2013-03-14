/*
 * Client.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "client.h"

//Конструктор заявки
Client::Client(int id, int type, int prioritet_set)
{
	id_=id;
	prioritet_=prioritet_set;
	type_=type;
	time_gen_=0;
	time_in_system_=0;
	time_in_element_=0;
}

//Деструктор заявки
Client::~Client()
{

}

//Получение ID заявки
int Client::GetID() const
{
	return id_;
}

//Получение приоритета
int Client::GetPrioritet() const
{
	return prioritet_;
}

//Инкримент времени в системе
void Client::IncrimentTIS()
{
	time_in_system_++;
}

//Инкримент времени в системе
void Client::IncrimentTIE()
{
	time_in_element_++;
}

//Установка типа заявки
void Client::setType(int type)
{
	type_=type;
}

//Получение типа заявки
int Client::GetType() const
{
	return type_;
}
//получение времени проведенного в системе
int Client::GetTimeInSystem() const
{
	return time_in_system_;
}


