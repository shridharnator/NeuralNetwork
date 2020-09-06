#pragma once
#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_
#include<iostream>
#include<math.h>
#include"Matrix.h"
#include"Layer.h"
#include"MultiplyMatrix.h"
#include<vector>

using namespace std;
class NeuralNetwork {
public:
	NeuralNetwork(vector<int> topology);
	void setCurrentInput(vector<double> input);
	void setCurrentTarget(vector<double> target);
	int topologySize;
	void printToConsole();
	void feedForward();
	void setErrors();
	Matrix* getNeuronMatrix(int index);
	Matrix* getActivatedNeuronMatrix(int index);
	Matrix* getDerivedNeuronMatrix(int index);
	Matrix* getWeightMatrix(int index);
	void setNeuronValue(int indexLayer, int indexNeuron, double val);
	double getTotalError();
	vector<double> getErrors();
	//void seterrors();

private:
	int topologysize;
	
	vector<int> topology;
	vector<Layer*> layers;
	vector<Matrix*> weightMatrices;
	vector<double> input;
	double error;
	vector<double> target;
	vector<double> errors{ 0,0,0 };
	vector<double> historicalErrors;
	//int indexLayer;


};
#endif

