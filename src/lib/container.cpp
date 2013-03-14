/*
 * container.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "container.h"

//Конструктор контейнера
Container::Container()
{
}

Container::~Container()
{

}

// Записать в контейнер
void Container::PutToContainer(Client *data)
{
	data_.push_back(data);
}

// Извлечь из контейнера
Client *Container::GetData(int id) const
{
	return data_[id];
}

//Удаление из контейнера
void Container::DelFrom(Client *data)
{
	vector<Client*> ndata;
	for(unsigned int i=0;i<data_.size();i++)
		if (data_[i]->GetID()!=data->GetID()) ndata.push_back(data_[i]);
		data_.clear();
	for(unsigned int i=0;i<ndata.size();i++)
		data_.push_back(ndata[i]);
}

//Получение размера контейнера
unsigned int Container::SizeContainer() const
{
	return data_.size();
}

