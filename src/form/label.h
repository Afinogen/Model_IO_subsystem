/*
 * label.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "element.h"

class Label: public Element
{
	public:
		Label(HINSTANCE hInst, HWND hwnd, char *caption);
		~Label();
	private:
};


#endif /* LABEL_H_ */
