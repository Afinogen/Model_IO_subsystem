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

class SubjectDrive
{
	public:
		SubjectDrive();
		~SubjectDrive();
		void CreateCanal(int count);
		Canal *GetCanal(int idx) const;
		void DecTimeCanal();
		bool GetAllStateCanal() const;
	private:
		vector<Canal*> array_canal_;

};


#endif /* SUBJECT_DRIVE_H_ */
