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

//������� ������������ ������ ��� �������
string Rus(const char *text);

//��������� ������� ������� � �������
void setCursosPosition(short x, short y);

//��������� ���-�� ���� ����� �������
double CutNumderDouble(double num, int pos);

#endif /* FUNCTION_H_ */
