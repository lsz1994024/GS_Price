/*
 * ImmuneAlg.cpp
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#include "../inc/ImmuneAlg.h"
#include <stdlib.h>

void popInitiation(Mat2& pop, Mat1& mSLL)
{
	int index = 0;
	for (Mat2::iterator p = pop.begin(); p < pop.end(); p++)
	{
		p->x = rand()*(Xs-Xx) + Xx;
		p->y = rand()*(Xs-Xx) + Xx;
		mSLL[index] = gsPrice(*p);
		index++;
	}
};

double sqr(double x)
{
	return x*x;
}

double gsPrice(Point& p)
{
	return  (1 + sqr((1 + p.x + p.y))*(19 - 14*p.x + 3*sqr(p.x) - 14*p.y + 6*p.x*p.y + 3*sqr(p.y)))
		  * (30 + sqr(2*p.x -3*p.y)*(18 - 32*p.x + 12*sqr(p.x) + 48*sqr(p.y) - 36*p.x*p.y + 27*sqr(p.y)));
}

double sumND(Mat1& nD)
{
	double sum = 0;
	for (Mat1::iterator i  = nD.begin(); i < nD.end(); i++)
	{
		sum += *i;
	}
	return sum;
}

//计算个体浓度和激励度
void density(Mat2& pop, Mat1& nD)
{
	int indexI = 0;
	for (Mat2::iterator i = pop.begin(); i < pop.end(); i++)
	{
		Mat1 tempND(NP);
		int indexJ = 0;
		for (Mat2::iterator j = pop.begin(); j < pop.end(); j++)
		{
			tempND[indexJ] = sqr(i->x - j->x) + sqr(i->y - j->y) < detas ? 1 : 0;
			indexJ++;
		}
		nD[indexI] = sumND(tempND);
	}
}

void updateMSLL(Mat1& mSLL, Mat1& nD)
{
	for(int index = 0; index < NP; index++)
	{
		mSLL[index] = alpha*mSLL[index] - beta*nD[index];
	}
}

