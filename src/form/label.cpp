/*
 * label.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "label.h"

Label::Label(HINSTANCE hInst, HWND hwnd, char *caption):Element(hInst, hwnd, caption)
{

}

Label::~Label()
{

}

void Label::CreateLabel(int x1, int y1, int x2, int y2)
{
	setPosition(x1,y1,x2,y2);
	setHWNDElement(CreateWindowEx(0, "STATIC", GetCaption(), ES_LEFT|WS_VISIBLE|
				WS_CHILD, x1, y1, x2, y2, GetHWNDForm(),
				NULL, GetHInstance(), NULL));
}


