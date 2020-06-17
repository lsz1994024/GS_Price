/*
 * ImmuneAlg.h
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#ifndef INC_IMMUNEALG_H_
#define INC_IMMUNEALG_H_

#include "Parameters.h"
#include <vector>
using namespace std;

struct Point
{
	double x{0};
	double y{0};
};

typedef vector<Point > PntVec;
typedef vector<double > DblVec;
typedef vector<int > IntVec;

double sqr(double x);

double gsPrice(Point& point);

void popInitiation(PntVec& pop, DblVec& mSLL);

double sumND(DblVec& nD);
DblVec density(PntVec& pop);

void updateMSLL(DblVec& mSLL, DblVec& nD);

IntVec sortAndGetIndex(DblVec& mat);

void sortPopWithIndex(PntVec& pop, IntVec& index);
#endif /* INC_IMMUNEALG_H_ */
