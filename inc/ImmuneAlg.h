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

double rand01();
double sqr(double x);
double rastrigin(Point& p);
double gsPrice(Point& point);
double aveDen(DblVec& nD);

void popAndStimuInit(PntVec& pop, DblVec& mSLL);

DblVec density(PntVec& pop);

void updateStimu(DblVec& mSLL, DblVec& nD);

IntVec sortStimuAndGetIndex(DblVec& mat);

void sortPopWithIndex(PntVec& pop, IntVec& index);

void adjustIfOutOfBound(Point& p);

void output(PntVec& pop);

#endif /* INC_IMMUNEALG_H_ */
