/*
 * generator.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "treat_client.h"

//Генератор
class Generator: public TreatClient
 {
  public:
   Generator();
   ~Generator();
   Client *CreateClient(int,int);	//Создание заявки
  private:
  	int count_gen_client_;	//Кол-во созданных заявок
 };


#endif /* GENERATOR_H_ */
