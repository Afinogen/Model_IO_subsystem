/*
 * form.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "form.h"

Form::Form(HINSTANCE hThisInstance,char *szClassName)
{
	hThisInstance_=hThisInstance;
	szClassName_=new char[1];
	szClassName_[0]='\0';
	strcpy(szClassName_,szClassName);
	title_=new char[1];
	title_[0]='\0';
	hwnd_=NULL;
}

Form::~Form()
{
	delete szClassName_;
	delete title_;
}

bool Form::CreateForm()
{
	/* The Window structure */
	wincl_.hInstance = hThisInstance_;
	wincl_.lpszClassName = szClassName_;
	wincl_.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
	wincl_.style = CS_DBLCLKS;                 /* Catch double-clicks */
	wincl_.cbSize = sizeof (WNDCLASSEX);

	/* Use default icon and mouse-pointer */
	wincl_.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wincl_.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
	wincl_.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl_.lpszMenuName = NULL;                 /* No menu */
	wincl_.cbClsExtra = 0;                      /* No extra bytes after the window class */
	wincl_.cbWndExtra = 0;                      /* structure or the window instance */
	/* Use Windows's default color as the background of the window */
	wincl_.hbrBackground = (HBRUSH) (COLOR_WINDOW);

	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx (&wincl_))
	{
		MessageBox(NULL,
				"Call to RegisterClassEx failed!",
				"Win32 Guided Tour",
				NULL);

		return false;
	}

	/* The class is registered, let's create the program*/
	hwnd_ = CreateWindowEx (
		   0,                   /* Extended possibilites for variation */
		   szClassName_,         /* Classname */
		   title_,       /* Title Text */
		   WS_MINIMIZEBOX|WS_VISIBLE|WS_CLIPCHILDREN|WS_CLIPSIBLINGS|
		   WS_CAPTION|WS_BORDER|WS_SYSMENU|WS_POPUP,
		   //WS_OVERLAPPEDWINDOW, /* default window */
		   CW_USEDEFAULT,       /* Windows decides the position */
		   CW_USEDEFAULT,       /* where the window ends up on the screen */
		   544,                 /* The programs width */
		   375,                 /* and height in pixels */
		   HWND_DESKTOP,        /* The window is a child-window to desktop */
		   NULL,                /* No menu */
		   hThisInstance_,       /* Program Instance handler */
		   NULL                 /* No Window Creation data */
		   );

	/* Make the window visible on the screen */

	return true;
}
void Form::setTitle(char *title)
{
	strcpy(title_,title);
}

HWND Form::GetHWND() const
{
	return hwnd_;
}
