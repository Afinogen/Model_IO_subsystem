/*
 * function.h
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#include "form\form.h"

using namespace std;

extern Form *pFormSMO;

extern Button *pButtonStartPause;
extern Button *pButtonStop;

extern Label *pLabelCountQuery;
extern Label *pLabelCountQueryTrun;

extern Label *pLabelSK1;
extern Label *pLabelSK2;

extern Label *pLabelDescNMD1;
extern Label *pLabelDescNMD2;
extern Label *pLabelDescNMD3;
extern Label *pLabelDescNMD4;
extern Label *pLabelDescNMD5;
extern Label *pLabelDescNMD6;

extern Label *pLabelTimeNMD1;
extern Label *pLabelTimeNMD2;
extern Label *pLabelTimeNMD3;
extern Label *pLabelTimeNMD4;
extern Label *pLabelTimeNMD5;
extern Label *pLabelTimeNMD6;

extern Label *pLabelTimeWork;

extern Label *pLabelCollectionClient;

extern Label *pLabelLoadSK1;
extern Label *pLabelLoadSK2;

extern Label *plabelLoadNMD1;
extern Label *plabelLoadNMD2;
extern Label *plabelLoadNMD3;
extern Label *plabelLoadNMD4;
extern Label *plabelLoadNMD5;
extern Label *plabelLoadNMD6;

extern Label *pLabelMidleTimeClinet;

extern Edit *pEditCountQuery;

//Функция руссификации текста для консоли
string Rus(const char *text);

//Установка позиции курсора в консоли
void setCursosPosition(short x, short y);

//Обрезание кол-ва цифр после запятой
double CutNumderDouble(double num, int pos);

void InitButton();

void InitLabel();

void InitEdit();

bool InitForm(HINSTANCE hThisInstance,int nFunsterStil);

void DestroyForm();

char *IntToChar(int num);

char *DoubleToChar(double num);

int CharToInt(const char *str);

#endif /* FUNCTION_H_ */
