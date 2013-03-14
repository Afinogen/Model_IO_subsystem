/*
 * canal.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef CANAL_H_
#define CANAL_H_

#include <stdlib.h>
#include "client.h"
#include "time.h"

using namespace std;

//Канал
class Canal: public Time
{
	public:
		Canal();
		~Canal();
		int GetTimeStop() const; //получение времени обработки заявки
		void DecTimeS();	//уменьшение времени обработки
		void setTimeStop(int time); //установка времени обработки
		bool setClient(Client *pClient, int time); //добавление в канал заявки и время ее обработки
		Client *GetClient() const; //получение заявки находящейся в обработке
		void DelClient();	//удаление заявки из канала
		bool GetState() const; //Получение состояния канала
	private:
		Client *client_;	//заявка на обработку
		int time_;	//время обработки

};


#endif /* CANAL_H_ */
