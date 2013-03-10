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

//—борщик
class Collection: virtual public Container
{
	public:
		Collection(int CountClinet);
		~Collection();
		int GetCountAllClient() const;
		const Container* GetContainer(int num) const;
		void PutToContainer(int id_container, Client *pClient);
	private:
		vector<Container*> collection_;
 };


#endif /* COLLECTION_H_ */
