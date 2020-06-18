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
	srand((unsigned)time(NULL));
	PntVec initPop(NUM_OF_ANTIBODY);
	DblVec initStimu(NUM_OF_ANTIBODY);
	DblVec cloneStimu(NUM_OF_CLONE);

	popAndStimuInit(initPop, initStimu);

	DblVec initDen = density(initPop);

	updateStimu(initStimu, initDen);

	IntVec initIndex = sortStimuAndGetIndex(initStimu);
	sortPopWithIndex(initPop, initIndex);

	for(uint gen = 0; gen < MAX_GEN; gen++)
	{
		DblVec bestStimu;
		PntVec bestPop;
		for(uint i = 0; i < NUM_OF_ANTIBODY/2; i++)
		{
			PntVec clonePop(NUM_OF_CLONE, initPop[i]);

			double newNeigh = NEIGHBOR/gen;

			for(uint j = 0; j < NUM_OF_CLONE; j++)
			{
				if(rand01() < PROB_OF_MUTAION)
				{
					clonePop[j].x += (rand01() - 0.5)*newNeigh;
					clonePop[j].y += (rand01() - 0.5)*newNeigh;
				}

				if(clonePop[j].x > H_BOUNDARY || clonePop[j].x < L_BOUNDARY) clonePop[j].x = rand01()*(H_BOUNDARY - L_BOUNDARY) + L_BOUNDARY;

				if(clonePop[j].y > H_BOUNDARY || clonePop[j].y < L_BOUNDARY) clonePop[j].y = rand01()*(H_BOUNDARY - L_BOUNDARY) + L_BOUNDARY;
			}

			clonePop[0] = initPop[i];

			for(uint j = 0; j < NUM_OF_CLONE; j++)
			{
				cloneStimu[j] = gsPrice(clonePop[j]);
			}

			IntVec cloneIndex = sortStimuAndGetIndex(cloneStimu);

			bestStimu.push_back(cloneStimu[0]);
			sortPopWithIndex(clonePop, cloneIndex);
			bestPop.push_back(clonePop[0]);
		}

		DblVec bestDen = density(bestPop);
		updateStimu(bestStimu, bestDen);

		PntVec newPop(NUM_OF_ANTIBODY/2);
		DblVec newStimu(NUM_OF_ANTIBODY/2);

		popAndStimuInit(newPop, newStimu);
		DblVec newDen = density(newPop);
		updateStimu(newStimu, newDen);

		bestPop.insert(bestPop.end(), newPop.begin(), newPop.end());
		bestStimu.insert(bestStimu.end(), newStimu.begin(), newStimu.end());

		IntVec newIndex = sortStimuAndGetIndex(bestStimu);
		sortPopWithIndex(bestPop, newIndex);

		initPop = bestPop;
	}

	printf("Calculated min value of GSPrice is %f at (%f, %f) \n", gsPrice(initPop[0]), initPop[0].x, initPop[0].y);

	Point a;
	a.x = 0; a.y = -1;
	printf("Theoretical min value of GSPrice is %f at (0, -1) \n", gsPrice(a));

	return 0;
}


