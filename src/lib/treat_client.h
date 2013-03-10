/*
 * treat_client.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef TREAT_CLIENT_H_
#define TREAT_CLIENT_H_

#include "client.h"
#include <vector>

using namespace std;

//Обработчик заявок
class TreatClient
 {
  public:
   TreatClient();
   ~TreatClient();
   const Client *GetClientLost() const;     //получение последней заявки
   void ClearClient();
   void AppendClient(Client *Clinet);
   vector<Client> GetVClient();
  private:
     vector<Client> client_; //
 };


#endif /* TREAT_CLIENT_H_ */
