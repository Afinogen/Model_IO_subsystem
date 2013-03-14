/*
 * Client.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "client.h"

//����������� ������
Client::Client(int id, int type, int prioritet_set)
{
	id_=id;
	prioritet_=prioritet_set;
	type_=type;
	time_gen_=0;
	time_in_system_=0;
	time_in_element_=0;
}

//���������� ������
Client::~Client()
{

}

//��������� ID ������
int Client::GetID() const
{
	return id_;
}

//��������� ����������
int Client::GetPrioritet() const
{
	return prioritet_;
}

//��������� ������� � �������
void Client::IncrimentTIS()
{
	time_in_system_++;
}

//��������� ������� � �������
void Client::IncrimentTIE()
{
	time_in_element_++;
}

//��������� ���� ������
void Client::setType(int type)
{
	type_=type;
}

//��������� ���� ������
int Client::GetType() const
{
	return type_;
}
//��������� ������� ������������ � �������
int Client::GetTimeInSystem() const
{
	return time_in_system_;
}


