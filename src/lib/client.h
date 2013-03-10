/*
 * Client.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef CLIENT_H_
#define CLIENT_H_

//������
class Client
 {
  public:
   Client(int id,int type,int prioritet_set);
   ~Client();
   int GetID() const;   //��������� id
   int GetPrioritet() const;  //��������� ����������
   void IncrimentTIS(); //��������� ������� � �������
   void IncrimentTIE(); //��������� ������� � ��������
   void setType(int type);	//��������� ���� ������
   int GetType() const;		//��������� ���� ������
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
