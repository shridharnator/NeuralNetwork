#pragma once
#pragma once
#ifndef _Layer_H_
#define _Layer_H_
#include<iostream>
#include<math.h>
#include"Neuron.h"
#include<vector>
#endif
using namespace std;
class Layer {
public:
	Layer(int size);

private:
	int size;
	vector<Neuron *> neurons;


};
