#pragma once
#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_
#include<iostream>
#include<math.h>
#include"Matrix.h"
#include"Layer.h"
#include<vector>

using namespace std;
class NeuralNetwork {
public:
	NeuralNetwork(vector<int> topology);
	void setCurrentInput(vector<double> input);
	int topologySize;
	void printToConsole();


private:
	int size;
	
	vector<int> topology;
	vector<Layer*> layers;
	vector<Matrix*> weightMatrices;
	vector<double> input;


};
#endif

