/*
 * ImmuneAlg.cpp
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#include "../inc/ImmuneAlg.h"
#include <stdlib.h>
#include <algorithm>

void popInitiation(PntVec& pop, DblVec& mSLL)
{
	int index = 0;
	for (PntVec::iterator p = pop.begin(); p < pop.end(); p++)
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

double aveND(DblVec& nD)
{
	double sum = 0;
	for (DblVec::iterator i  = nD.begin(); i < nD.end(); i++)
	{
		sum += *i;
	}
	return sum/nD.size();
}

//计算个体浓度和激励度
DblVec density(PntVec& pop)
{
	DblVec nD;
	for (PntVec::iterator i = pop.begin(); i < pop.end(); i++)
	{
		DblVec tempND(pop.size());
		int indexJ = 0;
		for (PntVec::iterator j = pop.begin(); j < pop.end(); j++)
		{
			tempND[indexJ] = sqr(i->x - j->x) + sqr(i->y - j->y) < detas ? 1 : 0;
			indexJ++;
		}
		nD.push_back(aveND(tempND));
	}
	return nD;
}

void updateMSLL(DblVec& mSLL, DblVec& nD)
{
	for(size_t index = 0; index < mSLL.size(); index++)
	{
		mSLL[index] = alpha*mSLL[index] - beta*nD[index];
	}
}

IntVec sortAndGetIndex(DblVec& mat)
{
	IntVec index;

	DblVec temp = mat;
	sort(mat.begin(), mat.end());
	for(DblVec::iterator i = mat.begin(); i < mat.end(); i++)
	{
		index.push_back(find(temp.begin(), temp.end(), *i) - temp.begin());
	}
	return index;
}

void sortPopWithIndex(PntVec& pop, IntVec& index)
{
	PntVec tempPop = pop;
	for(size_t i = 0; i < pop.size(); i++)
	{
		pop[i] = tempPop[index[i]];
	}
}



