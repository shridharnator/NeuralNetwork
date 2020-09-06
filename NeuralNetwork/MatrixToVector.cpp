#include "MatrixToVector.h"

MatrixToVector::MatrixToVector(Matrix* a)
{
	this->a = a;
}

vector<double> MatrixToVector::execute()
{
	 vector<double> result;
	for (int r = 0; r < a ->getNumRows(); r++) {
		for (int c = 0; c < a->getNumCols(); c++) {
			result.push_back(a->getValue(r, c));
		}
	}
	return result;
}
