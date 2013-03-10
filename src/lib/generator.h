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
   bool procces;
   Client *CreateClient(int,int);
  private:
  	int count_gen_client_;
 };


#endif /* GENERATOR_H_ */
