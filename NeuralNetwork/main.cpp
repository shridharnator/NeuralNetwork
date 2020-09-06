#include<iostream>
#include"Neuron.h"
#include"Matrix.h"
#include"Layer.h"
#include"NeuralNetwork.h"
using namespace std;
int main(int argc, char** argv) {
	//double input = 1.5;
	//Neuron* n = new Neuron(input);
	//cout << "Val :" << n->getVal()<<endl;
	//cout << "Activated Val :" << n->getActivatedVal() << endl;
	//cout << "Derived Val :" << n->getDerivedVal() << endl;
	//Matrix* m = new Matrix(3, 2,true);
	//m->printToConsole();
	//cout << "---------------------------------------------------"<<endl;
	//Matrix* mT = m->transpose();
	//mT->printToConsole();
	//vector<int> topology;
	//topology.push_back(3);
	//topology.push_back(2);
	//topology.push_back(3);
	//vector<double> input;
	//input.push_back(1.0);
	//input.push_back(0.0);
	//input.push_back(1.0);

	//NeuralNetwork *nn = new NeuralNetwork(topology);
	//nn->setCurrentInput(input);
	//nn->printToConsole();
	vector<double> input;
	input.push_back(1.0);
	input.push_back(0.0);
	input.push_back(1.0);
	vector<int> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(3);
	NeuralNetwork* nn = new NeuralNetwork(topology);
	nn->setCurrentInput(input);
	nn->setCurrentTarget(input);
	nn->feedForward();
	nn->setErrors();
	nn->printToConsole();
	cout << "Total Error: " << nn->getTotalError()<<endl;


	return 0;
}