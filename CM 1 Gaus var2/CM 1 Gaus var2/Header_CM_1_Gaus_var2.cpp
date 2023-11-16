#include "Header_CM_1_Gaus_var2.h"
using namespace std;
void IntializationOfMatrixElements(int n, double** matrix,double** matrixs) {
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
		matrixs[i] = new double[n];
	}
}
void ZeroingFandAx(int n, double* F, double* Ax) {
	for (int i = 0; i < n; i++) {
		F[i] = 0;
		Ax[i] = 0;
	}
}
void EnterMethod(int& n){
	cin >> n;
}
void EnterElements(int n, double** matrix,double** matrixs) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			matrixs[i][j] = matrix[i][j];
		}
	}
}
void EnterFreeElements(int n,double* b,double*bs){
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		bs[i] = b[i];
	}
}
void CoutInitialMatrix(int n, double** matrix,double* b){
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			//cout << "[" << i << "]" << "[" << j << "]";
			cout << matrix[i][j] << "  ";
		}
		cout << "| " << b[i];
		cout << endl << endl;
	}
}
void ExpandedMatrixComputation(int n, double** matrix, double* b,double*x) {
	for (int k = 0; k < n; k++) {
		double d = 0;
		if (matrix[k][k] == 0) {
			continue;
		}
		for (int j = k + 1; j < n; j++) {
			d = matrix[j][k] / matrix[k][k];
			for (int i = k; i < n; i++)
			{
				matrix[j][i] = matrix[j][i] - d * matrix[k][i];
			}
			b[j] = b[j] - d * b[k];

		}
	}
	for (int k = 0; k < n; k++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (matrix[k][j] == 0) {
				count++;
			}
		}
		if (count == 2)
		{
			for (int j = 0; j < n; j++) {
				swap(matrix[k][j], matrix[n - 1][j]);
				swap(b[k], b[n - 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	//x[n - 1] = b[n - 1] / matrix[n - 1][n - 1];
	//matrix[n - 1][n-1] = 1;
	for (int k = n - 1; k >= 0; k--)
	{
		double d = 0;
		double s;
		if (matrix[k][k] == 0) {
			continue;
		}

		for (int j = 0; j < n; j++)
		{
			s = matrix[k][j] * x[j];
			d = d + s;
		}
		x[k] = b[k] - d;
		x[k] = x[k] / matrix[k][k];

	}
}
void CoutOfX(int n, double* x) {
	for (int i = 0; i < n; i++) {
		cout << "x[" << i << "]=" << x[i] << " " << endl;
	}
}
void CalculationOfResidualVectorAndNorm(int n,double** matrixs, double* x,double*bs,double* F,double& Delta){
	double max = F[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			F[i] = F[i] + (matrixs[i][j] * x[j]);
		}
		F[i] = F[i] - bs[i];
	}
	for (int i = 0; i < n; i++) {
		if (abs(F[i]) > max) {
			max = abs(F[i]);
		}
		if (i == n - 1) {
			Delta = abs(max);
		}
	}
}
void CoutOfFAndDelta(int n,double*F,double Delta) {
	for (int i = 0; i < n; i++) {
		cout << "F[" << i << "]=" << F[i] << endl;
	}
	cout << "Delta:" << endl;
	cout << Delta << endl;
}
void CalculationOfAx(int n,double* Ax, double** matrix,double** matrixs,double *x) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Ax[i] = Ax[i] + (matrixs[i][j] * x[j]);
		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			matrix[i][j] = matrixs[i][j];
		}
	}
}
void CalculationOfdelta(int n,double*x,double* xs,double& delta) {
	double max = 0;
	double max1 = 0;
	for (int i = 0; i < n; i++) {
		if (abs(x[i]) > max) {
			max = abs(x[i]);
		}
		if (abs(xs[i] - x[i]) > max1) {
			max1 = abs(xs[i] - x[i]);
		}
		if (i == n - 1) {
			delta = abs(max1) / abs(max);
		}
	}
}