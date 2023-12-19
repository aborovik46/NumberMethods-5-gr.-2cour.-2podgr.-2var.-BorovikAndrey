// CM 2 Newton var2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "Header_CM_2_Newton_var2.h"
using namespace std;

void main()
{
	int NIT=20;//Кол-во заданных иттераций
	int n = 2;//Порядок матрицы 
	int ch;
	double M=0;
	
	double* x = new double[NIT];
	double* y = new double[NIT];
	double* F = new double[n];	
	double* dx = new double[NIT];
	ZeroingFAnddxAndxAndy(NIT, F, dx, x, y);
	cout << "Enter of initial approximation of x " << endl;//Ввод певоначальных значений
	cin >> x[0];
	cout << "Enter of initial approximation of y " << endl;
	cin >> y[0];
	cout << endl;
	
	double** matrix = new double* [n];
	IntializationOfMatixElements(n,matrix);
	double* delta2 = new double[NIT];
	double* delta1 = new double[NIT];
	double* F1 = new double[NIT];
	double* F2 = new double[NIT];
	double* dx1 = new double[NIT];
	double* dx2 = new double[NIT];

	cout << "The first method for specifying the Jacobian matrix" << endl;
	cout << endl;
	ch = 1;
	for (int i = 0; i < NIT; i++) {//Вычисление и вывод решения по методу Ньютона
		int result;//Переменная необходимая для того чтобы проверять достигла ли погрешность необходимой для выхода из цикла
		ApproximationOfValue(n,NIT, ch, M, dx, dx1, dx2, delta1, delta2, x, y, i, F, F1, F2, matrix);
		if (i != 0) {
			result = CalculationOfdelta(i, delta1, delta2, x, y, F);
			if (result == 1) {
				CoutOfXAndYAndDeltaXAndResidualVector(i, x, y, dx1, dx2, F1, F2);
				CoutOfdelta(delta1, delta2, i);
				break;
			}
		}
	}
	cout << "The second method for specifying the Jacobian matrix, with coefficient M = 0.01" << endl;
	cout << endl;
	ch = 2;
	M = 0.01;
	for (int i = 0; i < NIT; i++) {//Вычисление и вывод решения по методу Ньютона
		int result;//Переменная необходимая для того чтобы проверять достигла ли погрешность необходимой для выхода из цикла
		ApproximationOfValue(n,NIT, ch, M, dx, dx1, dx2, delta1, delta2, x, y, i, F, F1, F2, matrix);
		if (i != 0) {
			result = CalculationOfdelta(i, delta1, delta2, x, y, F);
			if (result == 1) {
				CoutOfXAndYAndDeltaXAndResidualVector(i, x, y, dx1, dx2, F1, F2);
				CoutOfdelta(delta1, delta2, i);
				break;
			}
		}
	}

	cout << "The second method for specifying the Jacobian matrix, with coefficient M = 0.05" << endl;
	cout << endl;
	ch = 2;
	M = 0.05;
	for (int i = 0; i < NIT; i++) {//Вычисление и вывод решения по методу Ньютона
		int result;//Переменная необходимая для того чтобы проверять достигла ли погрешность необходимой для выхода из цикла
		ApproximationOfValue(n,NIT, ch, M, dx, dx1, dx2, delta1, delta2, x, y, i, F, F1, F2, matrix);
		if (i != 0) {
			result = CalculationOfdelta(i, delta1, delta2, x, y, F);
			if (result == 1) {
				CoutOfXAndYAndDeltaXAndResidualVector(i, x, y, dx1, dx2, F1, F2);
				CoutOfdelta(delta1, delta2, i);
				break;
			}
		}
	}

	cout << "The second method for specifying the Jacobian matrix, with coefficient M = 0.1" << endl;
	cout << endl;
	ch = 2;
	M = 0.1;
	for (int i = 0; i < NIT; i++) {//Вычисление и вывод решения по методу Ньютона
		int result;//Переменная необходимая для того чтобы проверять достигла ли погрешность необходимой для выхода из цикла
		ApproximationOfValue(n,NIT, ch, M, dx, dx1, dx2, delta1, delta2, x, y, i, F, F1, F2, matrix);
		if (i != 0) {
			result = CalculationOfdelta(i, delta1, delta2, x, y, F);
			if (result == 1) {
				CoutOfXAndYAndDeltaXAndResidualVector(i, x, y, dx1, dx2, F1, F2);
				CoutOfdelta(delta1, delta2, i);
				break;
			}
		}
	}
	
		


}

