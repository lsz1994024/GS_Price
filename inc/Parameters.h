/*
 * Parameters.h
 *
 *  Created on: 2020年6月16日
 *      Author: LSZ
 */

#ifndef INC_PARAMETERS_H_
#define INC_PARAMETERS_H_

const double D=2;                                  //免疫个体维数
const double NP=50;                                //免疫个体数目
const double Xs=4;                                 //上限
const double Xx=-4;                                //下限
const double G=50;                                //最大免疫代数
const double pm=0.7;                               //变异概率
const double alfa=2;                               //激励度参数
const double belta=1;                              //激励度参数
const double detas=0.2;                            //相似度阈值
const double gen=0;                                //免疫代数
const double Nc1=5;                                //克隆个数
const double deta0=0.5*Xs;

//const double D = 2;                                  //免疫个体维数
//const double NUM_P = 50;                                //免疫个体数目
//const double MAX_X = 4;                                 //上限
//const double MIN_X = -4;                                //下限
//const double MAX_GEN = 50;                                //最大免疫代数
//const double MUT_PROB = 0.7;                               //变异概率
//const double ALPHA = 2;                               //激励度参数
//const double BETA = 1;                              //激励度参数
//const double DELTA = 0.2;                            //相似度阈值
//const double GEN = 0;                                //免疫代数
//const double NUM_C = 5;                                //克隆个数
//const double INIT = 0.5*MIN_X;                    //邻域范围初值

#endif /* INC_PARAMETERS_H_ */
