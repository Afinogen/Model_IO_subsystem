/*
 * collection.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <stdlib.h>
#include "container.h"

//Сборщик
class Collection: virtual public Container
{
	public:
		Collection(int CountClinet);
		~Collection();
		int GetCountAllClient() const;	//Получение кол-ва всех заявок
		const Container* GetContainer(unsigned int idx) const;	//Получение контейнера с нужным номером
		void PutToContainer(int id_container, Client *pClient); //Добавление заявки в контейнер
		int GetAllTimeClinetInSystem() const;	//Подсчет общего времени проведенного заявками в системе
	private:
		vector<Container*> collection_;	//массив контейнеров
 };


#endif /* COLLECTION_H_ */
