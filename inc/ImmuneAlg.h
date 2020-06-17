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

typedef vector<Point > Mat2;
typedef vector<double > Mat1;

double sqr(double x);

double gsPrice(Point& point);

void popInitiation(Mat2& pop, Mat1& mSLL);

double sumND(Mat1& nD);
void density(Mat2& pop, Mat1& nD);

void updateMSLL(Mat1& mSLL, Mat1& nD);


#endif /* INC_IMMUNEALG_H_ */
