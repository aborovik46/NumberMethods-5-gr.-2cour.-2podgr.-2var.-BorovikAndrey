#pragma once
#include <iostream>;
#include <iomanip>;
#include <cmath>;
using namespace std;
double Function1(double x);//Уравненение из 2 варианта
double Function2(double x, double y);//Уравнение из 30 варианта
double CalculationByTrapezoid(double eps, double a, double b, int n, double& R);//Вычисление Площади Методом трапеций 
double CalculationBySimpson(double eps, double a, double b, int n, double& R);//Вычисления Площади Методом Симпсона
double CalculatingBySimpsonCubaturn( double a2, double b2, double c, double d);//Вычисления Площади Кубатурным Методом Симпсона (30 вариант)