#include<iostream>
#include"Neuron.h"
#include"Matrix.h"
using namespace std;
int main(int argc, char** argv) {
	//double input = 1.5;
	//Neuron* n = new Neuron(input);
	//cout << "Val :" << n->getVal()<<endl;
	//cout << "Activated Val :" << n->getActivatedVal() << endl;
	//cout << "Derived Val :" << n->getDerivedVal() << endl;
	Matrix* m = new Matrix(1000, 1000,true);
	m->printToConsole();
	return 0;
}