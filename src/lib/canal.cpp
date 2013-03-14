/*
 * canal.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "canal.h"

//Конструктор канала
Canal::Canal()
{
	client_=NULL;
	time_=0;
}

Canal::~Canal()
{

}
//добавление в канал заявки и время ее обработки
bool Canal::setClient(Client *pClient, int time)
{
	if (pClient==NULL) return false;
	if (client_!=NULL) return false;

	client_=pClient;
	time_=time;
	return true;
}
//удаление заявки из канала
void Canal::DelClient()
{
	client_=NULL;
	time_=0;
}
//Получение состояния канала
bool Canal::GetState() const
{
	if (client_!=NULL) return true;
	else return false;
}
//получение времени обработки заявки
int Canal::GetTimeStop() const
{
	return time_;
}
//уменьшение времени обработки
void Canal::DecTimeS()
{
	if (time_>0)
	{
		time_--;
		client_->IncrimentTIS();
		//IncTime();
	}
}
//получение заявки находящейся в обработке
Client *Canal::GetClient() const
{
	return client_;
}
//установка времени обработки
void Canal::setTimeStop(int time)
{
	time_=time;
}
