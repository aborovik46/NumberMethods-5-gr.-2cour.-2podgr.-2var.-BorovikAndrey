#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void ZeroingFAnddxAndxAndy(int NIT, double* F, double* dx, double* x, double* y);//������� �������� �������� �������� F,dx,x,y
void CalculatingOfJacobi( double* x, double* y, int i,double** matrix);//������� ������� ����� ������ �������� (������ �� ���������)
void CalculatingOfF(double* x, double* y, int i, double* F);//���������� �������� �������
void CalculatingOfAnotherJacobi(double* x, double* y, int i,double M, double** matrix);//���������� ������� ����� ������ ��������(������ �� ���������)
void ExpandedMatrixComputation(int n, double** matrix, double* F, double* dx,int i);//���������� ������� ������� �����
void IntializationOfMatixElements(int n, double** matrix);//������������� ��������� �������
void ApproximationOfValue(int n,int NIT,int ch,double M,double* dx, double* dx1, double* dx2, double* delta1, double* delta2, double* x, double* y, int i, double* F, double* F1, double* F2, double** matrix);//���������� ������� �������
void SavingResidualVector(int i, double* F1, double* F2, double* F);//��������� ������ ������� ��� ������������ ������
void CoutInitialMatrix(int n,int i, double** matrix, double* F);//����� �������������� ��������� ������� 
void CoutOfXAndYAndDeltaXAndResidualVector(int i, double* x, double* y, double* dx1, double* dx2, double* F1, double* F2);//����� ���������� x,y,dx,F
int CalculationOfdelta(int i, double* delta1, double* delta2, double* x, double* y, double* F);//���������� ����������� ����������� ��� ���������� ������ �� �����
void CoutOfdelta(double* delta1, double* delta2, int i);//����� �����������
void SavingDeltaX(int i, double* dx1, double* dx2, double* dx);//���������� ���� ������������ ��� ������������ ������