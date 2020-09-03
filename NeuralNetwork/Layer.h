#pragma once
#ifndef _Layer_H_
#define _Layer_H_
#include<iostream>
#include<math.h>
#include"Neuron.h"
#include"Matrix.h"
#include<vector>
#endif
using namespace std;
class Layer {
public:
	Layer(int size);
	void setVal(int i,double v );
	Matrix *matrixifyVals();
	Matrix *matrixifyActivatedVals();
	Matrix *matrixifyDerivedVals();

private:
	int size;
	vector<Neuron *> neurons;


};
