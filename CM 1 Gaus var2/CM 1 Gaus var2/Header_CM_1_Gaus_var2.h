#pragma once
#include <iostream>
using namespace std;
void IntializationOfMatrixElements(int n, double** matrix, double** matrixs);
void ZeroingFandAx(int n, double* F, double* Ax);
void EnterMethod(int& n);
void EnterElements(int n, double** matrix, double** matrixs);
void EnterFreeElements(int n, double* b, double* bs);
void CoutInitialMatrix(int n, double** matrix, double* b);
void ExpandedMatrixComputation(int n, double** matrix, double* b, double* x);
void CoutOfX(int n, double* x);
void CalculationOfResidualVectorAndNorm(int n, double** matrixs, double* x, double* bs, double* F, double& Delta);
void CoutOfFAndDelta(int n, double* F, double Delta);
void CalculationOfAx(int n, double* Ax, double** matrix, double** matrixs, double* x);
void CalculationOfdelta(int n, double* x, double* xs, double& delta);