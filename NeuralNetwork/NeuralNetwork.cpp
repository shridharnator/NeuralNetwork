#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(vector<int> topology)
{
	topology = topology;
	topologySize = topology.size();
	for (int i =0 ; i < topologySize; i++) {
		Layer *l = new Layer(topology.at(i));
		layers.push_back(l);
	}
	for (int i = 0; i < (topologySize - 1); i++) {
		Matrix *m = new Matrix(topology.at(i),topology.at(i+1),true);

		weightMatrices.push_back(m);
	}
}

void NeuralNetwork::setCurrentInput(vector<double> input)
{
	this->input = input;
	for (size_t i = 0; i < input.size(); i++) {
		this->layers.at(0)->setVal(i, input.at(i));
	}
	//this->layers.at(0);
}

void NeuralNetwork::printToConsole()
{
	for (size_t i = 0; i < this->layers.size(); i++) {
		cout << "LAYER: " << i << endl;
		if (i == 0) {
			Matrix* m = this->layers.at(i)->matrixifyVals();
			m->printToConsole();
			
		}
		else {
			Matrix* m = this->layers.at(i)->matrixifyActivatedVals();
			m->printToConsole();

		}
	}
}
