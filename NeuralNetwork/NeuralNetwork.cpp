#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(vector<int> topology)
{
	this->topology = topology;
	this->topologySize = topology.size();
	for (int i =0 ; i < topologySize; i++) {
		Layer *l = new Layer(topology.at(i));
		this->layers.push_back(l);
	}
	for (int i = 0; i < (topologySize - 1); i++) {
		Matrix *m = new Matrix(topology.at(i),topology.at(i+1),true);

		this->weightMatrices.push_back(m);
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

void NeuralNetwork::setCurrentTarget(vector<double> target)
{
	this->target = target;
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
		cout << "==================================" << endl;
		if (i < this->layers.size() - 1) {
			cout << "Weight Matrix : " << i << endl;
			this->getWeightMatrix(i)->printToConsole();
		}
		cout << "=====================================" << endl;
	}
}

void NeuralNetwork::feedForward()
{
	for (size_t i = 0; i < (this->layers.size() - 1); i++) {
		Matrix* a = this->getNeuronMatrix(i);
		if (i != 0) {
			a = this->getActivatedNeuronMatrix(i);
		}
		Matrix* b = this->getWeightMatrix(i);
		Matrix* c = (new MultiplyMatrix(a, b))->execute();
		vector<double> vals;
		for (int c_index = 0; c_index < c->getNumCols(); c_index++) {
			this->setNeuronValue(i + 1, c_index, c->getValue(0, c_index));

		}
	}
}

void NeuralNetwork::setErrors()
{
	if (this->target.size() == 0) {
		cerr << "No target for this neural network" << endl;
		assert(false);
	}
	if (this->target.size() != this->layers.at(this->layers.size() - 1)->getNeurons().size()) {
		cerr << "Target size is not the same as output layer size : " << this->layers.at(this->layers.size() - 1)->getNeurons().size() << endl;
		assert(false);
	}
	this->error = 0.00;
	int outputLayerIndex = this->layers.size() - 1;
	vector<Neuron*>outputNeurons = this->layers.at(outputLayerIndex)->getNeurons();
	for (size_t i = 0; i < target.size(); i++) {
		double tempErr = ((outputNeurons.at(i)->getActivatedVal()) - target.at(i));
		this->errors.at(i) = tempErr;
		this->error += tempErr;
	}
	historicalErrors.push_back(this->error);
}




Matrix* NeuralNetwork::getNeuronMatrix(int index)
{
	return this->layers.at(index)->matrixifyVals();
	
}

Matrix* NeuralNetwork::getActivatedNeuronMatrix(int index)
{
	return this->layers.at(index)->matrixifyActivatedVals();
}

Matrix* NeuralNetwork::getDerivedNeuronMatrix(int index)
{
	return this->layers.at(index)->matrixifyDerivedVals();
}

Matrix* NeuralNetwork::getWeightMatrix(int index)
{
	return this->weightMatrices.at(index);
}

void NeuralNetwork::setNeuronValue(int indexLayer, int indexNeuron, double val)
{
	this->layers.at(indexLayer)->setVal(indexNeuron, val);
}

double NeuralNetwork::getTotalError()
{
	return this->error;
}

vector<double> NeuralNetwork::getErrors()
{
	return this->errors;
}

void NeuralNetwork::seterrors()
{

}
