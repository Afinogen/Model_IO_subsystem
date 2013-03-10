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

//Контейнер
class Container
{
  public:
   Container();
   ~Container();
   void PutToContainer(Client *data);        // Записать в контейнер
   Client *GetData(int id) const;  // Извлечь из контейнера
   void DelFrom(Client *data);     //удаление из контейнера
   void ClearData();               //очистка контейнера
   int SizeContainer() const;           //Размер контейнера
  private:
   vector<Client*> data_;
 };


#endif /* CONTAINER_H_ */
