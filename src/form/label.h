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
		void CreateLabel(int x1, int y1, int x2, int y2);
	private:
};


#endif /* LABEL_H_ */
