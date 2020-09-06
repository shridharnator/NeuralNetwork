#pragma once
#include<iostream>
#include<vector>
#include<assert.h>
#include"Matrix.h"
class MatrixToVector {
public:
	MatrixToVector(Matrix* a);
	vector<double> execute();//changed from vector<double> * execute();
private:
	Matrix* a;
};

