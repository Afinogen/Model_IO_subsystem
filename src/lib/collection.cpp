/*
 * collection.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "collection.h"

//����������� ��������
Collection::Collection(int CountClient)
{
	for(char i=0;i<CountClient;i++)
		collection_.push_back(new Container);
}

Collection::~Collection()
{

}

//��������� ������� � ������ �� �����������
const Container* Collection::GetContainer(unsigned int idx) const
{
	if (idx>=collection_.size()) return NULL;
	return collection_[idx];
}
//������� ���� ������ � ��������
int Collection::GetCountAllClient() const
{
	int Count=0;
	for(unsigned int i=0;i<collection_.size();i++)
		Count+=collection_[i]->SizeContainer();
	return Count;
}
//���������� ������ � ���������
void Collection::PutToContainer(int id_container, Client *pClient)
{
	collection_[id_container]->PutToContainer(pClient);
}
//������� ������ ������� ������������ �������� � �������
int Collection::GetAllTimeClinetInSystem() const
{
	int time=0;
	for(unsigned int i=0;i<collection_.size();i++)
		for(unsigned int j=0;j<collection_[i]->SizeContainer();j++)
			time+=collection_[i]->GetData(j)->GetTimeInSystem();
	return time;
}

