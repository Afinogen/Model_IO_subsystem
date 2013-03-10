/*
 * random
 *
 *  Created on: 07.03.2013
 *      Author: Afinogen
 */
#include "random.h"

//---------------------------------------------------------------------------
// √енераци€ случайной величины, равномерно распреденной в интервале [0, 1]
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
// √енераци€ случайной величины, равномерно распределенной в интервале [a, b]
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
// ¬ычисление обратной функции стандатного нормального распределени€
// p - доверитеьный уровень
double InverseNormalDistribution(double p)
{
   bool flag=true; // ѕараметр дл€ учета симметрии распределени€
   double t=0;

   if (p < 0.5)
        p=1-p;
   else if (p==0.5)
     return 0.0;
   else flag=false;

   // –азложение в р€д
   t=sqrt(-2.0*log(1.0-p));
   t-=(2.515517+0.802853*t+0.010328*t*t)/(1.0+1.432788*t+0.189269*t*t+0.001308*t*t*t);

   if (!flag)
      return t;
   else
      return -t;
}

//---------------------------------------------------------------------------
// √енераци€ случайной величины, нормально распределенной с параметрами [0, 1]
double GetNormalDistribution()
{
   double r=GetRand(0,RAND_MAX);

   r=InverseNormalDistribution(r);

   return fabs(r);
}

//---------------------------------------------------------------------------
// √енераци€ случайной величины, нормально распределенной с параметрами [m, s*s]
// m - математическое ожидание
// s - среднеквадратическое оклонение
double GetNormalDistribution(double m, double s)
{
   double r=GetNormalDistribution();

   r=m+s*r;

   return r;
}
