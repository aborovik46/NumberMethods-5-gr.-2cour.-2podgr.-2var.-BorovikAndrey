
#include <iostream>
#include "Header_CM_1_Gaus_var2.h"

using namespace std;

int main()
{
	int n=0;//Порядок матрицы
	cout << "Enter method";
	EnterMethod(n);
	cout << endl;
	double** matrixs = new double* [n];// Начальная матрица сохраненная для второго пункта
	double** matrix = new double* [n];// Матрица в которой мы будем проводить все вычисления
	IntializationOfMatrixElements(n, matrix, matrixs);
	double* F = new double[n];//Вектор невязки
	double* Ax = new double[n];//Свободные элементы матрицы из пункта 3
	ZeroingFandAx(n, F, Ax);
	cout << "Enter Elements" << endl;
	EnterElements(n, matrix,matrixs);
	cout << "Enter Free Elements" << endl;
	double* b = new double[n]; //Начальные свободные элементы матрицы
	double* bs = new double[n];//Начальные свободные элементы матрицы сохраненные для 2 пункта
	EnterFreeElements(n, b, bs);
	cout << "Initial matrix" << endl;
	CoutInitialMatrix(n, matrix, b);
	double* x = new double[n];// Решение нашей начальной системы уравнений 
	ExpandedMatrixComputation(n, matrix, b, x);//Функция вычисляет x
	cout << "Point 1:" << endl;
		cout << "X:" << endl;
		CoutOfX(n, x);
		double Delta = 0;//Норма 
		CalculationOfResidualVectorAndNorm(n, matrixs, x, bs, F, Delta); //Вычисление Векторов невязки F и нормы Delta
		cout << "Point 2:" << endl;
		cout << "F:" << endl;
		CoutOfFAndDelta(n, F, Delta);
		CalculationOfAx(n, Ax, matrix, matrixs, x);// вычисление Ах
		double* xs = new double[n];//Решение системы полученное в 3 пункте
		ExpandedMatrixComputation(n, matrix, Ax, xs);//Функция вычисляет xs
		cout << "Point 3:" << endl;
		cout << "XS:" << endl;
		CoutOfX(n, xs);
		double delta = 0;// Погрешность
		CalculationOfdelta(n, x, xs, delta);//Вычисление погрешности delta
		cout << "delta:" << endl;
		cout << delta << endl;



	
}

