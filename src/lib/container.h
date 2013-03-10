/*
 * container.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <vector>
#include "client.h"

using namespace std;

//���������
class Container
{
  public:
   Container();
   ~Container();
   void PutToContainer(Client *data);        // �������� � ���������
   Client *GetData(int id) const;  // ������� �� ����������
   void DelFrom(Client *data);     //�������� �� ����������
   void ClearData();               //������� ����������
   int SizeContainer() const;           //������ ����������
  private:
   vector<Client*> data_;
 };


#endif /* CONTAINER_H_ */
