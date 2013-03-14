/*
 * container.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "container.h"

//����������� ����������
Container::Container()
{
}

Container::~Container()
{

}

// �������� � ���������
void Container::PutToContainer(Client *data)
{
	data_.push_back(data);
}

// ������� �� ����������
Client *Container::GetData(int id) const
{
	return data_[id];
}

//�������� �� ����������
void Container::DelFrom(Client *data)
{
	vector<Client*> ndata;
	for(unsigned int i=0;i<data_.size();i++)
		if (data_[i]->GetID()!=data->GetID()) ndata.push_back(data_[i]);
		data_.clear();
	for(unsigned int i=0;i<ndata.size();i++)
		data_.push_back(ndata[i]);
}

//��������� ������� ����������
unsigned int Container::SizeContainer() const
{
	return data_.size();
}

