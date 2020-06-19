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
	//initialization of the antibody population, stimulation randomly
	srand((unsigned)time(NULL));
	PntVec initPop(NUM_OF_ANTIBODY);
	DblVec initStimu(NUM_OF_ANTIBODY);
	popAndStimuInit(initPop, initStimu);

	DblVec initDen = density(initPop); //get initial antibody density

	updateStimu(initStimu, initDen);

	IntVec initIndex = sortStimuAndGetIndex(initStimu); // sort the stimulation from low to high and return the sorted index
	sortPopWithIndex(initPop, initIndex);  //sort the population by sorted index

	DblVec cloneStimu(NUM_OF_CLONE);       //initialization of clone stimulation

	for(uint gen = 0; gen < MAX_GEN; gen++)  //start the immune cycle
	{
		DblVec bestStimu;                //initialization of the best stimulation and population
		PntVec bestPop;

		for(uint i = 0; i < NUM_OF_ANTIBODY/2; i++)  //chose the first half of population to for genovariation
		{
			PntVec clonePop(NUM_OF_CLONE, initPop[i]);   //initialization of the clone population

			double newNeigh = NEIGHBOR/gen;              //neighbor range. Narrowing with generations go on.

			for(uint j = 0; j < NUM_OF_CLONE; j++)        //for every antibody to be cloned 4 copies
			{
				if(rand01() < PROB_OF_MUTAION)            // genovariation
				{
					clonePop[j].x += (rand01() - 0.5)*newNeigh;
					clonePop[j].y += (rand01() - 0.5)*newNeigh;
				}

				adjustIfOutOfBound(clonePop[j]);          //adjust antibody when it is out of boundary
			}

			clonePop[0] = initPop[i];              //reserve the original antibody in the cloned population

			for(uint j = 0; j < NUM_OF_CLONE; j++)   //get the affinity of clone population
			{
				cloneStimu[j] = gsPrice(clonePop[j]);
			}

			IntVec cloneIndex = sortStimuAndGetIndex(cloneStimu);   //sort the clone stimulation

			bestStimu.push_back(cloneStimu[0]);
			sortPopWithIndex(clonePop, cloneIndex);
			bestPop.push_back(clonePop[0]);        //keep the best clone antibody in the best population
		}

		DblVec bestDen = density(bestPop);
		updateStimu(bestStimu, bestDen);         //update the best population

		// start to generate new random population
		PntVec newPop(NUM_OF_ANTIBODY/2);
		DblVec newStimu(NUM_OF_ANTIBODY/2);

		popAndStimuInit(newPop, newStimu);
		DblVec newDen = density(newPop);
		updateStimu(newStimu, newDen);

		bestPop.insert(bestPop.end(), newPop.begin(), newPop.end());  //merge the new population and the best population
		bestStimu.insert(bestStimu.end(), newStimu.begin(), newStimu.end());

		IntVec newIndex = sortStimuAndGetIndex(bestStimu);
		sortPopWithIndex(bestPop, newIndex);

		initPop = bestPop;        //assign the merged best population to initial population for iteration
	}

	printf("Calculated min value of GSPrice is %f at (%f, %f) \n", gsPrice(initPop[0]), initPop[0].x, initPop[0].y);

	Point answer;
	answer.x = 0; answer.y = -1;
	printf("Theoretical min value of GSPrice is %f at (0, -1) \n", gsPrice(answer));

	return 0;
}


