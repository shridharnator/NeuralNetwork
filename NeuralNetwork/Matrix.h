#pragma once
#ifndef _Matrix_H_
#define _Matrix_H_
#include<iostream>
#include<math.h>
#include<vector>
#include<random>
#endif
using namespace std;
class Matrix {
public:
	Matrix(int numRows,int numCols,bool isRandom);
	Matrix *transpose();
	void setValue(int r, int c, double v);
	double getValue(int r, int c);
	double generateRandomNumber();
	int getNumRows();
	int getNumCols();
	void printToConsole();

private:
	int numRows;
	int numCols;
	vector<vector<double> > values;
	


};
