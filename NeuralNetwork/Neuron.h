#pragma once
#pragma once
#ifndef _NEURON_H_
#define _NEURON_H_
#include<iostream>
#include<math.h>
#endif
using namespace std;
class Neuron {
public:
	Neuron(double val);

	
	//Fast Sigmoid
	void activate();
	//Derivitive of the Fast Sigmoid
	void derive(); 
		//

	
	//activation function(Fast Sigmoid)
	//Derivitive of Fast Sigmoid
	//f'(x)=f(x)*(1-f(x))
	double getVal() { return this->val; }
	double getActivatedVal() { return this->activatedVal; }
	double getDerivedVal() { return this->derivedVal; }

private:
	double val;
	double activatedVal;
	double derivedVal;


};

