/*
 * element.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "element.h"

Element::Element(HINSTANCE hInst, HWND hwnd, char *caption)
{
	form_=hwnd;
	element_=NULL;
	hInst_=hInst;
	caption_=new char[strlen(caption)+1];
	caption_[0]='\0';
	strcpy(caption_,caption);
	x1_=0;
	y1_=0;
	x2_=0;
	y2_=0;
}

Element::~Element()
{
	delete caption_;
}

void Element::setCaption(const char *caption)
{
	strcpy(caption_,caption);
	if (element_!=NULL) SetWindowText(element_,caption_);
}

void Element::setPosition(int x1, int y1, int x2, int y2)
{
	x1_=x1;
	y1_=y1;
	x2_=x2;
	y2_=y2;
}

const char *Element::GetCaption() const
{
	return caption_;
}

HWND Element::GetHWNDForm() const
{
	return form_;
}

HWND Element::GetHWNDElement() const
{
	return element_;
}

HINSTANCE Element::GetHInstance() const
{
	return hInst_;
}

void Element::setHWNDElement(HWND element)
{
	element_=element;
}

