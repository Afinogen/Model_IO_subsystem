/*
 * function.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "function.h"

Form *pFormSMO;
Button *pButtonStartPause;
Button *pButtonStop;
Label *pLabelCountQuery;
Label *pLabelCountQueryTrun;
Label *pLabelSK1;
Label *pLabelSK2;
Label *pLabelDescNMD1;
Label *pLabelDescNMD2;
Label *pLabelDescNMD3;
Label *pLabelDescNMD4;
Label *pLabelDescNMD5;
Label *pLabelDescNMD6;
Label *pLabelTimeNMD1;
Label *pLabelTimeNMD2;
Label *pLabelTimeNMD3;
Label *pLabelTimeNMD4;
Label *pLabelTimeNMD5;
Label *pLabelTimeNMD6;
Label *pLabelCollectionClient;
Label *pLabelTimeWork;
Label *pLabelLoadSK1;
Label *pLabelLoadSK2;
Label *plabelLoadNMD1;
Label *plabelLoadNMD2;
Label *plabelLoadNMD3;
Label *plabelLoadNMD4;
Label *plabelLoadNMD5;
Label *plabelLoadNMD6;
Label *pLabelMidleTimeClinet;
Edit *pEditCountQuery;


//Функция руссификации текста для консоли
string Rus(const char *text)
{
  char *buffer=new char[strlen(text)+1];
  if (NULL == buffer)
  return "";
  AnsiToOem(text,buffer);
  string result(buffer);
  delete[] buffer;
  return result;
}
//Установка позиции курсора в консоли
void setCursosPosition(short x, short y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //получения хендла консоли
	COORD cor = {x,y};       //коордионаты вывода на консоль
	SetConsoleCursorPosition(hConsole,cor);
}

double CutNumderDouble(double num, int pos)
{
	double degree=(pow(10,pos));
	int new_num=num*degree;
	return static_cast<double>(new_num)/static_cast<double>(degree);
}

void InitButton()
{
	pButtonStartPause=new Button(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Старт");
	pButtonStartPause->CreateButton(20,50,60,35);

	pButtonStop=new Button(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Стоп");
	pButtonStop->CreateButton(90,50,60,35);
}

void InitLabel()
{
	pLabelCountQuery=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Количество заявок");
	pLabelCountQuery->CreateLabel(10,10,180,20);

	pLabelCountQueryTrun=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Заявок в очереди: 0");
	pLabelCountQueryTrun->CreateLabel(10,100,280,20);

	pLabelSK1=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"СК 1: свободен");
	pLabelSK1->CreateLabel(10,130,180,20);

	pLabelSK2=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"СК 2: свободен");
	pLabelSK2->CreateLabel(230,130,180,20);

	/*pLabelDescNMD=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"");
	pLabelDescNMD->CreateLabel(230,130,180,20);*/

	pLabelDescNMD1=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"НМД1");
	pLabelDescNMD1->CreateLabel(10,170,60,20);

	pLabelDescNMD2=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"НМД2");
	pLabelDescNMD2->CreateLabel(80,170,60,20);

	pLabelDescNMD3=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"НМД3");
	pLabelDescNMD3->CreateLabel(160,170,60,20);

	pLabelDescNMD4=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"НМД4");
	pLabelDescNMD4->CreateLabel(240,170,60,20);

	pLabelDescNMD5=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"НМД5");
	pLabelDescNMD5->CreateLabel(320,170,60,20);

	pLabelDescNMD6=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"НМД6");
	pLabelDescNMD6->CreateLabel(400,170,60,20);

	pLabelTimeNMD1=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"0");
	pLabelTimeNMD1->CreateLabel(10,190,60,20);

	pLabelTimeNMD2=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"0");
	pLabelTimeNMD2->CreateLabel(80,190,60,20);

	pLabelTimeNMD3=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"0");
	pLabelTimeNMD3->CreateLabel(160,190,60,20);

	pLabelTimeNMD4=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"0");
	pLabelTimeNMD4->CreateLabel(240,190,60,20);

	pLabelTimeNMD5=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"0");
	pLabelTimeNMD5->CreateLabel(320,190,60,20);

	pLabelTimeNMD6=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"0");
	pLabelTimeNMD6->CreateLabel(400,190,60,20);

	pLabelCollectionClient=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Обработано заявок: 0");
	pLabelCollectionClient->CreateLabel(10,230,270,20);

	pLabelTimeWork=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Общее время работы: 0");
	pLabelTimeWork->CreateLabel(10,260,270,20);

	pLabelLoadSK1=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка СК1: 0%");
	pLabelLoadSK1->CreateLabel(10,290,270,20);

	pLabelLoadSK2=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка СК2: 0%");
	pLabelLoadSK2->CreateLabel(10,320,270,20);

	plabelLoadNMD1=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка НМД1 0%");
	plabelLoadNMD1->CreateLabel(10,360,180,20);

	plabelLoadNMD2=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка НМД2 0%");
	plabelLoadNMD2->CreateLabel(10,390,180,20);

	plabelLoadNMD3=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка НМД3 0%");
	plabelLoadNMD3->CreateLabel(10,420,180,20);

	plabelLoadNMD4=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка НМД4 0%");
	plabelLoadNMD4->CreateLabel(10,450,180,20);

	plabelLoadNMD5=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка НМД5 0%");
	plabelLoadNMD5->CreateLabel(10,480,180,20);

	plabelLoadNMD6=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Загрузка НМД6 0%");
	plabelLoadNMD6->CreateLabel(10,510,180,20);

	pLabelMidleTimeClinet=new Label(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"Среднее время обслуживания заппроса: 0");
	pLabelMidleTimeClinet->CreateLabel(10,540,400,20);
}

void InitEdit()
{
	pEditCountQuery=new Edit(pFormSMO->GetHInstance(),pFormSMO->GetHWND(),"30");
	pEditCountQuery->CreateEdit(190,10,50,20);
}

bool InitForm(HINSTANCE hThisInstance)
{
	char szClassName[ ] = "SMO";

	pFormSMO=new Form(hThisInstance,szClassName);
	pFormSMO->setTitle("Система массового обслуживания");
	pFormSMO->CreateForm();

	InitButton();
	InitLabel();
	InitEdit();

	return true;
}

void DestroyForm()
{
	delete pFormSMO;
	delete pButtonStartPause;
	delete pLabelCountQuery;
	delete pEditCountQuery;
	delete pButtonStop;
	delete pLabelCountQueryTrun;
	delete pLabelSK1;
	delete pLabelSK2;
	delete pLabelDescNMD1;
	delete pLabelDescNMD2;
	delete pLabelDescNMD3;
	delete pLabelDescNMD4;
	delete pLabelDescNMD5;
	delete pLabelDescNMD6;
	delete pLabelTimeNMD1;
	delete pLabelTimeNMD2;
	delete pLabelTimeNMD3;
	delete pLabelTimeNMD4;
	delete pLabelTimeNMD5;
	delete pLabelTimeNMD6;
	delete pLabelCollectionClient;
	delete pLabelTimeWork;
	delete pLabelLoadSK1;
	delete pLabelLoadSK2;
	delete plabelLoadNMD1;
	delete plabelLoadNMD2;
	delete plabelLoadNMD3;
	delete plabelLoadNMD4;
	delete plabelLoadNMD5;
	delete plabelLoadNMD6;
	delete pLabelMidleTimeClinet;
}

char *IntToChar(int num)
{
	char name[50]={'\0'};
	itoa(num,name,10);
	return name;
}

char *DoubleToChar(double num)
{
	int wholeNum = num;
	int decimalNum = (int) ((num - wholeNum) * 100);

	char wholeNumStr[10]={'\0'};
	char decNumStr[5]={'\0'};
	char numStr[17]={'\0'};
	itoa(wholeNum, wholeNumStr, 10);
	itoa(decimalNum, decNumStr, 10);
	strcpy(numStr, wholeNumStr);
	strcat(numStr, ".");
	strcat(numStr, decNumStr);
	return numStr;
}
