/*
 * subject_drive.h
 *
 *  Created on: 08.03.2013
 *      Author: Afinogen
 */

#ifndef SUBJECT_DRIVE_H_
#define SUBJECT_DRIVE_H_

#include <vector>
#include "canal.h"

//Субъект управления
class SubjectDrive
{
	public:
		SubjectDrive();
		~SubjectDrive();
		void CreateCanal(int count);	//Создание каналов
		Canal *GetCanal(unsigned int idx) const;	//Получение канала
		void DecTimeCanal();			//Уменьшение времени обработки заявки в канале
		bool GetAllStateCanal() const;	//Получение состояния каналов
	private:
		vector<Canal*> array_canal_;	//массив каналов

};


#endif /* SUBJECT_DRIVE_H_ */
