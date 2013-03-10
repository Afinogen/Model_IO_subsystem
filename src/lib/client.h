/*
 * Client.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef CLIENT_H_
#define CLIENT_H_

//Заявка
class Client
 {
  public:
   Client(int id,int type,int prioritet_set);
   ~Client();
   int GetID() const;   //Получение id
   int GetPrioritet() const;  //Получение приоритета
   void IncrimentTIS(); //Инкремент времени в системе
   void IncrimentTIE(); //Инкремент времени в элементе
   void setType(int type);	//Установка типа заявки
   int GetType() const;		//Получение типа заявки
   int GetTimeInSystem() const;
  private:
   int id_;
   int prioritet_;
   int type_;
   int time_gen_;
   int time_in_system_;
   int time_in_element_;
 };


#endif /* CLIENT_H_ */
