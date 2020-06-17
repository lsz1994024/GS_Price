/*
 * main.cpp
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */
#include "inc/ImmuneAlg.h"
#include <iostream>
using namespace std;

int main()
{
	Mat2 initPop(NP);
	Mat1 initMSLL(NP);
	Mat1 nD(NP);

	popInitiation(initPop, initMSLL);
	density(initPop, nD);
	return 0;
}


