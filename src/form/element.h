/*
 * element.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <windows.h>

class Element
{
	public:
		Element(HINSTANCE hInst, HWND hwnd, char *caption);
		virtual ~Element();
		void setCaption(const char *caption);
		void setPosition(int x1, int y1, int x2, int y2);
		virtual const char *GetCaption() const;
		HWND GetHWNDForm() const;
		HWND GetHWNDElement() const;
		HINSTANCE GetHInstance() const;
		void setHWNDElement(HWND element);
	private:
		HWND form_;
		HWND element_;
		HINSTANCE hInst_;
		char *caption_;
		int x1_;
		int y1_;
		int x2_;
		int y2_;
};



#endif /* ELEMENT_H_ */
