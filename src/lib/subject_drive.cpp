/*
 * subject_drive.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "subject_drive.h"

//�����������
SubjectDrive::SubjectDrive()
{

}

SubjectDrive::~SubjectDrive()
{

}
//�������� �������
void SubjectDrive::CreateCanal(int count)
{
	for(int i=0;i<count;i++)
	{
		array_canal_.push_back(new Canal());
	}
}
//��������� ������
Canal *SubjectDrive::GetCanal(unsigned int idx) const
{
	if (idx>=array_canal_.size()) return NULL;
	return array_canal_[idx];
}
//���������� ������� ��������� ������ � ������
void SubjectDrive::DecTimeCanal()
{
	for(unsigned int i=0;i<array_canal_.size();i++)
	{
		array_canal_[i]->DecTimeS();
		if (array_canal_[i]->GetState()) array_canal_[i]->IncTime();
	}
}
//��������� ��������� �������
bool SubjectDrive::GetAllStateCanal() const
{
	bool state=false;
	for(unsigned int i=0;i<array_canal_.size();i++)
	{
		if (array_canal_[i]->GetState()==true)
		{
			state=true;
			break;
		}
	}

	return state;
}

