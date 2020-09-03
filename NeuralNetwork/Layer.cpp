#include "Layer.h"

Layer::Layer(int size)
{
	for (int i = 0; i < size; i++) {
		Neuron* n = new Neuron(0.00);
		this->neurons.push_back(n);
	}
}

void Layer::setVal(int i,double v )
{
	this->neurons.at(i)->setVal(v);

}

Matrix* Layer::matrixifyVals()
{
	Matrix* m = new Matrix(1, this->neurons.size(), false);
	for (size_t i = 0; i< this->neurons.size(); i++) {
		m->setValue(0,i,this->neurons.at(i)->getVal());
	}
	return m;
}

Matrix* Layer::matrixifyActivatedVals()
{
	Matrix* m = new Matrix(1, this->neurons.size(), false);
	for (size_t i = 0; i < this->neurons.size(); i++) {
		m->setValue(0, i, this->neurons.at(i)->getActivatedVal());
	}
	return m;
}

Matrix* Layer::matrixifyDerivedVals()
{
	Matrix* m = new Matrix(1, this->neurons.size(), false);
	for (size_t i = 0; i < this->neurons.size(); i++) {
		m->setValue(0, i, this->neurons.at(i)->getDerivedVal());
	}
	return nullptr;
}

