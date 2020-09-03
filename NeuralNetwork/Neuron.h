#pragma once
#ifndef _NEURON_H_
#define _NEURON_H_
#include<iostream>
#include<math.h>
#endif
using namespace std;
class Neuron {
public:
	//activation function(Fast Sigmoid)
	//f(x)=x/(1+|x|)
	void activate();
	//Derivitive of Fast Sigmoid
	//f'(x)=f(x)*(1-f(x))
	void derive();
	double getVal() { return this->val; }
	double getActivatedVal() { return this->activatedVal; }
	double getDerivedVal() { return this->derivedVal; }

private:
	double val;
	double activatedVal;
	double derivedVal;


};
