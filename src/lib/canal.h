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
		int GetTimeStop() const;
		void DecTimeS();
		void setTimeStop(int time);
		bool setClient(Client *pClient, int time);
		Client *GetClient() const;
		void DelClient();
		bool GetState() const;
	private:
		Client *client_;
		int time_;

};


#endif /* CANAL_H_ */
