/*
 * Parameters.h
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#ifndef INC_PARAMETERS_H_
#define INC_PARAMETERS_H_

typedef unsigned int uint;

const uint DEMENSION = 2;                 //Dimension of antibody
const uint NUM_OF_ANTIBODY = 50;          //number of antibody
const uint NUM_OF_CLONE = 5;              //number of clone copies
const uint MAX_GEN = 50;                  //maximum of immune generation

const int H_BOUNDARY = 2;                 //upper limit of position
const int L_BOUNDARY = -2;                //lower limit of position
const int ALPHA = 2;                      //parameter of stimulation operator
const int BETA = 1;                       //parameter of stimulation operator

const double PROB_OF_MUTAION = 0.7;       //probability of mutation
const double DELTA = 0.2;                 //threshold of similarity
const double NEIGHBOR = 0.5*H_BOUNDARY;   //initial value of neighbor scope

#endif /* INC_PARAMETERS_H_ */
