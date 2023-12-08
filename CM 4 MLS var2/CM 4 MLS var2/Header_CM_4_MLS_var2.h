#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Function1(double x);//Функция данная в условии
double Function2(double* a, double x);//Вид степенного полинома в нашем случае
void CalculatingDifferentSums(int m, int N, double* x, double* SumX, double* SumY);//Вычисление различных сумм(например для х,х^2 и т.п.)
void MatrixInputation(int m, double** matrix, double* b, double* SumY, double* SumX, double* x);//Заносим полученные значения сумм в матрицу со свобдными элементами
void ExpandedMatrixComputation(int m, double** matrix, double* b, double* a);//Вычисление матрицы методом Гауса
void CoutOfA(int m, double* a);//Вывод коэффициентов полинома
void CoutInitialMatrix(int n, double** matrix, double* b);//Вывод Матрицы
void IntializationOfMatixElements(int m, double** matrix);//Инициализация элементов матрицы
void CalculationOfEPS(int m, int n, double S, double* a, double* x);//Вычисление погрешности
void CoutOfX(int n, double* x);//Вывод Х
void CoutOfY(int n, double* x);//Вывод Y

