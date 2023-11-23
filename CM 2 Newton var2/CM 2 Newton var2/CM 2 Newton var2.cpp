// CM 2 Newton var2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include "Header_CM_2_Newton_var2.h"
using namespace std;

void main()
{
	int NIT=6;//Кол-во заданных иттераций
	int n;
	int ch;
	double M=0;
	
	double* x = new double[NIT];
	double* y = new double[NIT];
	cout << "Enter Quantity of initial approximation" << endl;//Кол-во начальных заданных значений
	cin >> n;
	cout << "In what way do you want to define the Jacobian?(1 or 2,(According of manual))" << endl;//Выбор способа вычисления Якобиана
	cin >> ch;
	switch (ch) {
	case 1:
	
	break;
	case 2:
		cout << "Enter the increment(For example:0,01 or 0,05 or 0,1" << endl;//Выбор погрешности с которой будет посчитан Якобиан если выбран второй способ его задания 
		cin >> M;
	break;
	default:
		cout << "ERROR" << endl;//Введено некоректное значение
		exit;
	break;
	}
	double* F = new double[n];	
	double* dx = new double[NIT];
	ZeroingFAnddxAndxAndy(NIT, F, dx, x, y);
	cout << "Enter of initial approximation of x " << endl;//Ввод певоначальных значений
	cin >> x[0];
	cout << "Enter of initial approximation of y " << endl;
	cin >> y[0];
	
	double** matrixs = new double* [n];
	double** matrix = new double* [n];
	IntializationOfMatixElements(n,matrix,matrixs);
	double* delta2 = new double[NIT];
	double* delta1 = new double[NIT];
	double* F1 = new double[NIT];
	double* F2 = new double[NIT];
	double* dx1 = new double[NIT];
	double* dx2 = new double[NIT];

	for (int i = 0; i < NIT; i++) {//Вычисление и вывод решения по методу Ньютона
		int result;//Переменная необходимая для того чтобы проверять достигла ли погрешность необходимой для выхода из цикла
		ApproximationOfValue(n,ch,M ,dx,dx1,dx2, x, y, i, F,F1,F2, matrix, matrixs);
		CoutOfXAndYAndDeltaXAndResidualVector(i, x, y, dx1, dx2, F1, F2);
		if (i != 0) {
			result = CalculationOfdelta(i, delta1, delta2, x, y, F);
			CoutOfdelta(delta1, delta2, i);
			if (result == 1) {
				break;
			}
		}
	}
	
	
		


}

