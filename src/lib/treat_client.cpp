/*
 * treat_client.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "treat_client.h"

TreatClient::TreatClient()//int type,int prioritet_set):Client(type,prioritet_set)
{

}

TreatClient::~TreatClient()
{

}

//��������� ��������� ������
const Client *TreatClient::GetClientLost() const
{
	return &client_.at(client_.size()-1); //return __pClient.end();
}

//�������� ������ �� �����������
void TreatClient::ClearClient()
{
	client_.clear();
}

//���������� ������ � ����������
void TreatClient::AppendClient(Client *Client)
{
    client_.push_back(*Client);
}

vector<Client> TreatClient::GetVClient()
{
    return client_;
}
