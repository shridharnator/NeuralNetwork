#include"Neuron.h"
//Constructor
Neuron::Neuron(double val) {
	this->val = val;
	activate();
	derive();

}
//Fast Sigmoid
void Neuron::activate() {
	this->activatedVal = this->val / (1 +abs( this->val));
}
//Derivitive of the Fast Sigmoid
void Neuron::derive() {
	this->derivedVal = this->activatedVal * (1 - this->activatedVal);

}