#pragma once
#include <iostream>;
#include <iomanip>;
#include <cmath>;
using namespace std;
double Function1(double x);//����������� �� 2 ��������
double Function2(double x, double y);//��������� �� 30 ��������
double CalculationByTrapezoid(double eps, double a, double b, int n, double& R);//���������� ������� ������� �������� 
double CalculationBySimpson(double eps, double a, double b, int n, double& R);//���������� ������� ������� ��������
double CalculatingBySimpsonCubaturn( double a2, double b2, double c, double d);//���������� ������� ���������� ������� �������� (30 �������)