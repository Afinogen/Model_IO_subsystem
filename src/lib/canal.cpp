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

bool Canal::setClient(Client *pClient, int time)
{
	if (pClient==NULL) return false;
	if (client_!=NULL) return false;

	client_=pClient;
	time_=time;
	return true;
}

void Canal::DelClient()
{
	client_=NULL;
	time_=0;
}

bool Canal::GetState() const
{
	if (client_!=NULL) return true;
	else return false;
}

int Canal::GetTimeStop() const
{
	return time_;
}

void Canal::DecTimeS()
{
	if (time_>0)
	{
		time_--;
		client_->IncrimentTIS();
		//IncTime();
	}
}

Client *Canal::GetClient() const
{
	return client_;
}

void Canal::setTimeStop(int time)
{
	time_=time;
}
