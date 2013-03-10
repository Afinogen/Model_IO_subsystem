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

using namespace std;

//Функция руссификации текста для консоли
string Rus(const char *text);

//Установка позиции курсора в консоли
void setCursosPosition(short x, short y);

//Обрезание кол-ва цифр после запятой
double CutNumderDouble(double num, int pos);

#endif /* FUNCTION_H_ */
