/*
 * ImmuneAlg.cpp
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#include "../inc/ImmuneAlg.h"
#include "math.h"
#include "time.h"
#include <algorithm>
#include <iostream>

double rand01()  //produce a random enough double in (0,1)
{
	return time(NULL) % 3 == 0 ? rand()/(RAND_MAX + 1.0) : (1 - rand()/(RAND_MAX + 1.0));
};


double sqr(double x)  //square operator
{
	return x*x;
}

double gsPrice(Point& p)   //Gold-Stein Price function, the antigen
{
	return  (1 + sqr(1 + p.x + p.y)*(19 - 14*p.x + 3*sqr(p.x) - 14*p.y + 6*p.x*p.y + 3*sqr(p.y)))
		  * (30 + sqr(2*p.x - 3*p.y)*(18 - 32*p.x + 12*sqr(p.x) + 48*p.y - 36*p.x*p.y + 27*sqr(p.y)));
}

double aveDen(DblVec& den)   //average of antibody density
{
	double sum = 0;
	for (DblVec::iterator i  = den.begin(); i < den.end(); i++)
	{
		sum += *i;
	}
	return sum/den.size();
}

void popAndStimuInit(PntVec& pop, DblVec& stimu)
{
	int index = 0;
	for (PntVec::iterator p = pop.begin(); p < pop.end(); p++)
	{
		p->x = rand01()*(H_BOUNDARY-L_BOUNDARY) + L_BOUNDARY;
		p->y = rand01()*(H_BOUNDARY-L_BOUNDARY) + L_BOUNDARY;
		stimu[index] = gsPrice(*p);
		index++;
	}
};

DblVec density(PntVec& pop)
{
	DblVec den;
	for (PntVec::iterator i = pop.begin(); i < pop.end(); i++)
	{
		DblVec tempDen;
		for (PntVec::iterator j = pop.begin(); j < pop.end(); j++)
		{
			tempDen.push_back(sqrt(sqr(i->x - j->x) + sqr(i->y - j->y)) < DELTA ? 1 : 0);
		}
		den.push_back(aveDen(tempDen));
	}
	return den;
}

void updateStimu(DblVec& stm, DblVec& den)
{
	for(size_t index = 0; index < stm.size(); index++)
	{
		stm[index] = ALPHA*stm[index] - BETA*den[index];   //stimulation operator
	}
}

IntVec sortStimuAndGetIndex(DblVec& stm)
{
	IntVec index;
	DblVec tempStm = stm;

	sort(stm.begin(), stm.end());

	for(DblVec::iterator i = stm.begin(); i < stm.end(); i++)
	{
		index.push_back(find(tempStm.begin(), tempStm.end(), *i) - tempStm.begin());   //get the index of each stimulation
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

void adjustIfOutOfBound(Point& p)
{
	if(p.x > H_BOUNDARY || p.x < L_BOUNDARY) p.x = rand01()*(H_BOUNDARY - L_BOUNDARY) + L_BOUNDARY;

	if(p.y > H_BOUNDARY || p.y < L_BOUNDARY) p.y = rand01()*(H_BOUNDARY - L_BOUNDARY) + L_BOUNDARY;
}
