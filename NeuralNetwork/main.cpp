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
	Matrix* m = new Matrix(3, 2,true);
	m->printToConsole();
	cout << "---------------------------------------------------"<<endl;
	Matrix* mT = m->transpose();
	mT->printToConsole();
	return 0;
}