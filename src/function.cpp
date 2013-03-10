/*
 * function.cpp
 *
 *  Created on: 10.03.2013
 *      Author: Afinogen
 */

#include "function.h"


//������� ������������ ������ ��� �������
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
//��������� ������� ������� � �������
void setCursosPosition(short x, short y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //��������� ������ �������
	COORD cor = {x,y};       //����������� ������ �� �������
	SetConsoleCursorPosition(hConsole,cor);
}

double CutNumderDouble(double num, int pos)
{
	double degree=(pow(10,pos));
	int new_num=num*degree;
	return static_cast<double>(new_num)/static_cast<double>(degree);
}
