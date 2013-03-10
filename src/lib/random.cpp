/*
 * random
 *
 *  Created on: 07.03.2013
 *      Author: Afinogen
 */
#include "random.h"

//---------------------------------------------------------------------------
// ��������� ��������� ��������, ���������� ������������ � ��������� [0, 1]
double GetRand()
{
	time_t t;
	t=time(NULL);
	//srand(rand());
	//double r=rand();
	//return( ((ptd->_holdrand = ptd->_holdrand * 214013L+ 2531011L) >> 16) & 0x7fff );
	int r=((rand()* 214013L+ 2531011L) >> 16) & t;
	r%=RAND_MAX;

	return r;
}

//---------------------------------------------------------------------------
// ��������� ��������� ��������, ���������� �������������� � ��������� [a, b]
double GetRand(int a, int b)
{
	int r=GetRand();

   //r=a+(b-a)*r;
   r=a+r%(b-a+1);
   if (r<a) r=a;
   if (r>b) r=b;
   return r;
}

//---------------------------------------------------------------------------
// ���������� �������� ������� ����������� ����������� �������������
// p - ������������ �������
double InverseNormalDistribution(double p)
{
   bool flag=true; // �������� ��� ����� ��������� �������������
   double t=0;

   if (p < 0.5)
        p=1-p;
   else if (p==0.5)
     return 0.0;
   else flag=false;

   // ���������� � ���
   t=sqrt(-2.0*log(1.0-p));
   t-=(2.515517+0.802853*t+0.010328*t*t)/(1.0+1.432788*t+0.189269*t*t+0.001308*t*t*t);

   if (!flag)
      return t;
   else
      return -t;
}

//---------------------------------------------------------------------------
// ��������� ��������� ��������, ��������� �������������� � ����������� [0, 1]
double GetNormalDistribution()
{
   double r=GetRand(0,RAND_MAX);

   r=InverseNormalDistribution(r);

   return fabs(r);
}

//---------------------------------------------------------------------------
// ��������� ��������� ��������, ��������� �������������� � ����������� [m, s*s]
// m - �������������� ��������
// s - �������������������� ���������
double GetNormalDistribution(double m, double s)
{
   double r=GetNormalDistribution();

   r=m+s*r;

   return r;
}
