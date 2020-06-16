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

typedef vector<Point > Pop;
typedef vector<double > MSLL;

double sqr(double x);

double gsPrice(Point& point);



#endif /* INC_IMMUNEALG_H_ */
