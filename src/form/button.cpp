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

void Button::CreateButton()
{
	setHWNDElement(CreateWindowEx(0, "BUTTON", GetCaption(), BS_PUSHBUTTON|
				WS_VISIBLE|WS_CHILD|WS_TABSTOP, 70, 55, 60, 25, GetHWNDForm(),
				NULL, GetHInstance(), NULL));
}


