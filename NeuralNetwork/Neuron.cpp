#include"Neuron.h"
Neuron::Neuron(double val)
{
	this->val = val;
	activate();
	derive();

}

void Neuron::setVal(double v)
{
	this->val = v;//this was this->val=val;
	activate();
	derive();
}

void Neuron::activate()
{
	
	this->activatedVal = (this->val) / (1 + abs(this->val));
	
}

void Neuron::derive()
{
	this->derivedVal =( this->activatedVal) * ((1) - (this->activatedVal));//this line is giving incorrect output due to faultu placement of brckets check after completing project
}
