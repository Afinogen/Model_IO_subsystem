/*
 * button.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "element.h"

class Button: public Element
{
	public:
		Button(HINSTANCE hInst, HWND hwnd, char *caption);
		~Button();
		void CreateButton();
	private:

};


#endif /* BUTTON_H_ */
