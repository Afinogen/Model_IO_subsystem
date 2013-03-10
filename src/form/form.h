/*
 * form.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef FORM_H_
#define FORM_H_

#include <windows.h>
#include "button.h"

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

class Form
{
	public:
		Form(HINSTANCE hThisInstance,char *szClassName);
		~Form();
		bool CreateForm();
		void setTitle(char *title);
		HWND GetHWND() const;
	private:
		WNDCLASSEX wincl_;        /* Data structure for the windowclass */
		HINSTANCE hThisInstance_;
		char *szClassName_;
		HWND hwnd_;               /* This is the handle for our window */
		char *title_;
};


#endif /* FORM_H_ */
