/*
 * edit.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef EDIT_H_
#define EDIT_H_

#include "element.h"

class Edit: public Element
{
	public:
		Edit(HINSTANCE hInst, HWND hwnd, char *caption);
		~Edit();
	private:
};


#endif /* EDIT_H_ */
