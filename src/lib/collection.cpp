/*
 * collection.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "collection.h"

//конструктор сборщика
Collection::Collection(int CountClient)
{
	for(char i=0;i<CountClient;i++)
		collection_.push_back(new Container);
}

Collection::~Collection()
{

}

//Получение доступа к одному из контейнеров
const Container* Collection::GetContainer(int num) const
{
	if (num>collection_.size()) return NULL;
	else if (num<0) return NULL;
	return collection_[num];
}
//Подсчет всех заявок в сборщике
int Collection::GetCountAllClient() const
{
	int Count=0;
	for(unsigned int i=0;i<collection_.size();i++)
		Count+=collection_[i]->SizeContainer();
	return Count;
}

void Collection::PutToContainer(int id_container, Client *pClient)
{
	collection_[id_container]->PutToContainer(pClient);
}

