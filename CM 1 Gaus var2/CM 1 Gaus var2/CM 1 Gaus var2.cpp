
#include <iostream>
#include "Header_CM_1_Gaus_var2.h"

using namespace std;

int main()
{
	int n=0;
	double d,s;
	double Delta = 0;
	double delta = 0;
	cout << "Enter method";
	EnterMethod(n);
	cout << endl;
	double* b = new double[n];
	double* bs = new double[n];
	double** matrixs = new double* [n];
	double** matrix = new double* [n];
	double* x = new double[n];
	double* xs = new double[n];
	double* F = new double[n];
	double* Ax = new double[n];
	IntializationOfMatrixElements(n, matrix, matrixs);
	ZeroingFandAx(n, F, Ax);
	cout << "Enter Elements" << endl;
	EnterElements(n, matrix,matrixs);
	cout << "Enter Free Elements" << endl;
	EnterFreeElements(n, b, bs);
	cout << "Initial matrix" << endl;
	CoutInitialMatrix(n, matrix, b);
	ExpandedMatrixComputation(n, matrix, b, x);
	cout << "Point 1:" << endl;
		cout << "X:" << endl;
		CoutOfX(n, x);
		CalculationOfResidualVectorAndNorm(n, matrixs, x, bs, F, Delta);
		cout << "Point 2:" << endl;
		cout << "F:" << endl;
		CoutOfFAndDelta(n, F, Delta);
		CalculationOfAx(n, Ax, matrix, matrixs, x);
		ExpandedMatrixComputation(n, matrix, Ax, xs);
		cout << "Point 3:" << endl;
		cout << "XS:" << endl;
		CoutOfX(n, xs);
		CalculationOfdelta(n, x, xs, delta);
		cout << "delta:" << endl;
		cout << delta << endl;



	
}

