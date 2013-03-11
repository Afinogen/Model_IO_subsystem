/*
 * edit.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "edit.h"

Edit::Edit(HINSTANCE hInst, HWND hwnd, char *caption):Element(hInst, hwnd, caption)
{

}

Edit::~Edit()
{

}

void Edit::CreateEdit(int x1, int y1, int x2, int y2)
{
	setPosition(x1,y1,x2,y2);
	setHWNDElement(CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", GetCaption(), ES_LEFT|ES_NUMBER|
				WS_VISIBLE|WS_CHILD, x1, y1, x2, y2, GetHWNDForm(),
				NULL, GetHInstance(), NULL));
}



