/*
 * button.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "button.h"

Button::Button(HINSTANCE hInst, HWND hwnd, char *caption):Element(hInst, hwnd, caption)
{

}

Button::~Button()
{

}

void Button::CreateButton(int x1, int y1, int x2, int y2)
{
	setPosition(x1,y1,x2,y2);
	setHWNDElement(CreateWindowEx(0, "BUTTON", GetCaption(), BS_PUSHBUTTON|
				WS_VISIBLE|WS_CHILD|WS_TABSTOP, x1, y1, x2, y2, GetHWNDForm(),
				NULL, GetHInstance(), NULL));
}


