/*
 * generator.cpp
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#include "generator.h"

// онструктор генератора
Generator::Generator()
{
	//pGenerator=NULL;
	procces=false;
	count_gen_client_=0;
}

Generator::~Generator()
{

}

//генерирование за€вки
Client *Generator::CreateClient(int SetPrioritet, int SetType)
{
	return new Client(++count_gen_client_,SetType,SetPrioritet);
}



