#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void ZeroingFAnddxAndxAndy(int NIT, double* F, double* dx, double* x, double* y);//Функция зануляет элементы массивов F,dx,x,y
void CalculatingOfJacobi( double* x, double* y, int i,double** matrix);//Задание матрицы Якоби первым способом (исходя из методички)
void CalculatingOfF(double* x, double* y, int i, double* F);//Вычисление векторов невязки
void CalculatingOfAnotherJacobi(double* x, double* y, int i,double M, double** matrix);//Вычисление матрицы Якоби вторым способом(исходя из методички)
void ExpandedMatrixComputation(int n, double** matrix, double* F, double* dx,int i);//Вычисление матрицы методом Гауса
void IntializationOfMatixElements(int n, double** matrix);//Инициализация Элементов Матрицы
void ApproximationOfValue(int n,int NIT,int ch,double M,double* dx, double* dx1, double* dx2, double* delta1, double* delta2, double* x, double* y, int i, double* F, double* F1, double* F2, double** matrix);//Вычисления методом Ньютона
void SavingResidualVector(int i, double* F1, double* F2, double* F);//Сохраняем вектор невязки для последующего вывода
void CoutInitialMatrix(int n,int i, double** matrix, double* F);//Вывод первоначальной полученой матрицы 
void CoutOfXAndYAndDeltaXAndResidualVector(int i, double* x, double* y, double* dx1, double* dx2, double* F1, double* F2);//Вывод переменных x,y,dx,F
int CalculationOfdelta(int i, double* delta1, double* delta2, double* x, double* y, double* F);//Вычисление погрешности необходимой для досрочного выхода из цикла
void CoutOfdelta(double* delta1, double* delta2, int i);//Вывод погрешности
void SavingDeltaX(int i, double* dx1, double* dx2, double* dx);//Сохранение шага апроксимации для последующего вывода