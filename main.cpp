/*
 * main.cpp
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */
#include "inc/ImmuneAlg.h"
#include <iostream>
#include "time.h"
#include <algorithm>
using namespace std;

int main()
{
	srand((unsigned)(time(NULL) )*1);
	PntVec initPop(NP);
	DblVec initMSLL(NP);
	DblVec naMSLL(NP);

	popInitiation(initPop, initMSLL);

	DblVec nD = density(initPop);
	updateMSLL(initMSLL, nD);

	IntVec initIndex = sortAndGetIndex(initMSLL);
	sortPopWithIndex(initPop, initIndex);

	for(int gen = 0; gen < G+50; gen++)
	{
		DblVec bestMSLL;
		PntVec bestClone;
		for(int i = 0; i < NP/2; i++)
		{
			PntVec NaPop(Nc1, initPop[i]);
			double deta = deta0/gen;   // 也得到了inf  但是和matlab是一样的吗？

			for(int j = 0; j < Nc1; j++)
			{
				if(rand() < pm)
				{
					NaPop[j].x += (rand() - 0.5)*deta;
					NaPop[j].y += (rand() - 0.5)*deta;
				}

				if(NaPop[j].x > Xs || NaPop[j].x < Xx) NaPop[j].x = rand()*(Xs - Xx) + Xx;

				if(NaPop[j].y > Xs || NaPop[j].y < Xx) NaPop[j].y = rand()*(Xs - Xx) + Xx;
			}

			NaPop[0] = initPop[i];

			for(int j = 0; j < Nc1; j++)
			{
				naMSLL[j] = gsPrice(NaPop[j]);
			}

			IntVec naIndex = sortAndGetIndex(naMSLL);
//			sortPopWithIndex(initPop, naIndex);
			bestMSLL.push_back(naMSLL[0]);
			sortPopWithIndex(NaPop, naIndex);
			bestClone.push_back(NaPop[0]);
		}

		DblVec nDofBest = density(bestClone);
		updateMSLL(bestMSLL, nDofBest);

		PntVec bPop(NP/2);
		DblVec bMSLL(NP/2);

		popInitiation(bPop, bMSLL);
		DblVec bnD = density(bPop);
		updateMSLL(bMSLL, bnD);

//		PntVec newPop;
//		newPop = bestClone;
		bestClone.insert(bestClone.end(), bPop.begin(), bPop.end());
		bestMSLL.insert(bestMSLL.end(), bMSLL.begin(), bMSLL.end());

		IntVec newIndex = sortAndGetIndex(bestMSLL);
		sortPopWithIndex(bestClone, newIndex);

		initPop = bestClone;
	}

	printf("Best pop x, y = %f, %f\n", initPop[0].x, initPop[0].y);
	printf("Min GSPrice is %f\n", gsPrice(initPop[0]));
	Point a;
	a.x = 0; a.y = -1;
	printf("lsz GSPrice is %f\n", gsPrice(a));

//	double b = sqr(a.x+a.y);
//
//	printf("lsz b is %f\n", b);
//	double a[3] = {1,0.1,2.1};
//	vector<double > testv(a, a+3);
//	IntVec testi = sortAndGetIndex(testv);
//	for(int i = 0;i<3; i++)
//	{
//		printf("%f ", testv[i]);
//		printf("\n");
//		printf("%d ", testi[i]);
//				printf("\n");
//	}
	return 0;
}


