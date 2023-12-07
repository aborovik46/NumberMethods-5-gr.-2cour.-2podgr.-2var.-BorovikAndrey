#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Function1(double x);
double Function2(double* a, double x);
void CalculatingDifferentSums(int m, int N, double* x, double* SumX, double* SumY);
void ZeroingSums(int m, double* SumX, double* SumY);
void MatrixInputation(int m, double** matrix, double* b, double* SumY, double* SumX, double* x);
void ExpandedMatrixComputation(int m, double** matrix, double* b, double* a);
void CoutOfA(int m, double* a);
void CoutInitialMatrix(int n, double** matrix, double* b);
void IntializationOfMatixElements(int m, double** matrix);
void CalculationOfEPS(int m, int n, double S, double* a, double* x);
void CoutOfX(int n, double* x);
void CoutOfY(int n, double* x);

