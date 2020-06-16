/*
 * ImmuneAlg.cpp
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#include "../inc/ImmuneAlg.h"
#include <stdlib.h>

Pop initPop(NP);
MSLL initMSLL(NP);


void popInitiation()
{
	int index = 0;
	for (vector<Point >::iterator p = initPop.begin(); p < initPop.end(); p++)
	{
		p->x = rand()*(Xs-Xx) + Xx;
		p->y = rand()*(Xs-Xx) + Xx;
		initMSLL[index] = gsPrice(*p);
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

