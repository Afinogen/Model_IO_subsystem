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
		void CreateEdit(int x1, int y1, int x2, int y2);
		const char *GetCaption() const;
	private:
};


#endif /* EDIT_H_ */
