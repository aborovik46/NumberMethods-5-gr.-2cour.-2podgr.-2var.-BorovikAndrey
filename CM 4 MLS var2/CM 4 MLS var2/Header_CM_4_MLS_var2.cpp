#include "Header_CM_4_MLS_var2.h"

double Function1(double x) {
	return 1 / (1 + x);
}
double Function2(double*a,double x) {
	return a[0] + a[1] * x + a[2] * pow(x, 2) + a[3] * pow(x, 3) + a[4] * pow(x, 4);
}
void CalculatingDifferentSums(int m,int N,double* x,double* SumX,double* SumY){
	for (int i = 0; i < (m+1); i++) {
		for (int j = 0; j < N; j++) {
			SumY[i] += Function1(x[j]) * pow(x[j], i);
		}
	}
	for (int i = 0; i < (2*m + 1); i++) {
		for (int j = 0; j < N; j++) {
			SumX[i] += pow(x[j], i);
		}
	}
}
void ZeroingSums(int m, double* SumX, double* SumY) {
	for (int i = 0; i < (m+1); i++) {
		SumX[i] = 0;
		SumY[i] = 0;
	}
}
void MatrixInputation(int m, double** matrix,double* b, double* SumY, double* SumX, double* x) {
	for (int i = 0, n = 0; i < (m + 1); i++, n++) {
		for (int j = 0; j < (m + 1); j++ ) {
			matrix[i][j] = SumX[j + n];
		}
		b[i] = SumY[i];
	}

}
void ExpandedMatrixComputation(int m, double** matrix, double* b, double* a) {
	for (int k = 0; k < m+1; k++) {
		double d = 0;
		if (matrix[k][k] == 0) {
			continue;
		}
		for (int j = k + 1; j < m+1; j++) {
			d = matrix[j][k] / matrix[k][k];
			for (int i = k; i < m+1; i++)
			{
				matrix[j][i] = matrix[j][i] - d * matrix[k][i];
			}
			b[j] = b[j] - d * b[k];

		}
	}
	for (int k = 0; k < m+1; k++) {
		int count = 0;
		for (int j = 0; j < m+1; j++) {
			if (matrix[k][j] == 0) {
				count++;
			}
		}
		if (count == 2)
		{
			for (int j = 0; j < m+1; j++) {
				swap(matrix[k][j], matrix[m][j]);

			}
			swap(b[k], b[m]);
		}
	}
	for (int i = 0; i < m+1; i++) {
		a[i] = 0;
	}
	//x[n - 1] = b[n - 1] / matrix[n - 1][n - 1];
	//matrix[n - 1][n-1] = 1;
	for (int k = m; k >= 0; k--)
	{
		double d = 0;
		double s;
		if (matrix[k][k] == 0) {
			continue;
		}

		for (int j = 0; j < m+1; j++)
		{
			s = matrix[k][j] * a[j];
			d = d + s;
		}
		a[k] = b[k] - d;
		a[k] = a[k] / matrix[k][k];

	}
}
void CoutOfA(int m, double* a) {
	for (int i = 0; i < (m+1); i++) {
		cout << "a[" << i << "]=" <<  a[i] << " "<< endl;
	}
}
void CoutInitialMatrix(int n, double** matrix, double* b) {
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			//cout << "[" << i << "]" << "[" << j << "]";
			cout << matrix[i][j] << "  ";
		}
		cout << "| " << b[i];
		cout << endl << endl;
	}
}
void IntializationOfMatixElements(int m, double** matrix) {
	for (int i = 0; i < m+1; i++) {
		matrix[i] = new double[i];
	}
}void CalculationOfEPS(int m,int n,double S ,double* a,double* x) {
	for (int i = 0; i < m+1; i++) {
		double tmp = Function1(x[i]);
		for (int j = 0; j < m+1; j++) {
			tmp -= a[j] * pow(x[i], j);
		}
		S += tmp * tmp;
	}
	S /= n - m - 1;
	sqrt(S);
}
void CoutOfX(int n, double* x) {
	for (int i = 0; i < n; i++) {
		cout << "x[" << i << "]=" << x[i] << " " << endl;
	}
}
void CoutOfY(int n, double* x) {
	for (int i = 0; i < n; i++) {
		cout << "y[" << i << "]=" <<  Function1(x[i]) << " " << endl;
	}
}

