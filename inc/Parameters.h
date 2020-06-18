/*
 * Parameters.h
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#ifndef INC_PARAMETERS_H_
#define INC_PARAMETERS_H_

typedef unsigned int uint;

const uint DEMENSION = 2;                                  //免疫个体维数
const uint NUM_OF_ANTIBODY = 50;                                //免疫个体数目
const uint NUM_OF_CLONE = 5;                                //克隆个数
const uint MAX_GEN = 50;                                //最大免疫代数  应该是50  暂时写为5

const int H_BOUNDARY = 4;                                 //上限
const int L_BOUNDARY = -4;                                //下限
const int ALPHA = 2;                               //激励度参数
const int BETA = 1;                              //激励度参数

const double PROB_OF_MUTAION = 0.7;                               //变异概率
const double DELTA = 0.2;                            //相似度阈值
const double NEIGHBOR = 0.5*H_BOUNDARY;          //邻域范围初值

#endif /* INC_PARAMETERS_H_ */
