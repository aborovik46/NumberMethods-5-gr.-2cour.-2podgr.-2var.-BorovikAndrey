#include "Header_CM_2_Newton_var2.h"
void CalculatingOfF( double* x, double* y, int i, double* F) {

	F[0] = (-1)*(x[i] - y[i] - 6 * log10(x[i]) - 1);
	F[1] = (-1)*(x[i] - 3 * y[i] - 6 * log10(y[i]) - 2);

}
void CalculatingOfJacobi(double* x, double* y, int i, double** matrix) {

	matrix[0][0] = (1 - (6 / (log(10) * x[i])));
	matrix[0][1] = (-1);
	matrix[1][0] = (1);
	matrix[1][1] = (-3 - (6 / (log(10) * y[i])));
}
void CalculatingOfAnotherJacobi(double* x, double* y, int i,double M, double** matrix) {

	matrix[0][0] = (((x[i]+x[i]*M - y[i] - 6 * log10(x[i] + x[i] * M) - 1)-(x[i] - y[i] - 6 * log10(x[i]) - 1))/(x[i]*M));
	matrix[0][1] = (((x[i] - y[i] - y[i] * M - 6 * log10(x[i]) - 1) - (x[i] - y[i] - 6 * log10(x[i]) - 1)) / (y[i] * M));
	matrix[1][0] = (((x[i]+x[i]*M - 3 * y[i] - 6 * log10(y[i]) - 2) - (x[i] - 3 * y[i] - 6 * log10(y[i]) - 2))/ (x[i] * M));
	matrix[1][1] = (((x[i] - 3 * (y[i]+y[i]*M) - 6 * log10(y[i] + y[i] * M) - 2)- (x[i] - 3 * y[i] - 6 * log10(y[i]) - 2))/ (y[i] * M));
}
void IntializationOfMatixElements(int n, double** matrix) {
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n];
	}
}
void ZeroingFAnddxAndxAndy(int NIT, double* F, double* dx,double*x,double*y) {
	for (int i = 0; i < NIT; i++) {
		F[i] = 0;
		dx[i] = 0;
		x[i] = 0;
		y[i] = 0;
	}
}
void ExpandedMatrixComputation(int n, double** matrix, double* F, double* dx, int i) {
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
			F[j] = F[j] - d * F[k];

		}
	}
	for (int k = 0; k < n; k++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (matrix[k][j] == 0) {
				count++;
			}
		}
		if (count == 1)
		{
			for (int j = 0; j < n; j++) {
				swap(matrix[k][j], matrix[n - 1][j]);

			}
			swap(F[k], F[n - 1]);
		}
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
			s = matrix[k][j] * dx[j];
			d = d + s;
		}
		dx[k] = F[k] - d;
		dx[k] = dx[k] / matrix[k][k];

	}
}
void ApproximationOfValue(int n,int NIT,int ch,double M,double* dx, double* dx1, double* dx2, double* delta1, double* delta2, double* x, double* y, int i, double* F, double* F1, double* F2, double** matrix) {
	dx[0] = 0;
	dx[1] = 0;
	CalculatingOfF(x, y, i, F);
	switch (ch) {
	case 1:
		CalculatingOfJacobi(x,y, i,matrix);
	break;
	case 2:
		CalculatingOfAnotherJacobi(x, y, i, M, matrix);
	break;
	default:
		cout << "ERROR" << endl;
		exit;
		break;
	}
	if ((i == NIT - 1)||(1 == CalculationOfdelta(i,delta1,delta2,x,y,F))) {
		CoutInitialMatrix(n, i, matrix, F);
	}
	SavingResidualVector( i, F1, F2, F);
	ExpandedMatrixComputation(n, matrix, F, dx,i);
	SavingDeltaX(i, dx1, dx2, dx);
	x[i + 1] = x[i] + dx1[i];
	y[i + 1] = y[i] + dx2[i];

}
void SavingResidualVector(int i, double* F1, double* F2,double* F) {
	F1[i] = F[0];
	F2[i] = F[1];
}
void CoutInitialMatrix(int n,int i, double** matrix, double* F) {
	cout << "Initial Matrix her solution at iteration  " << i << endl;
	for (int it = 0; it < n; it++) {

		for (int j = 0; j < n; j++) {
			//cout << "[" << i << "]" << "[" << j << "]";
			cout << matrix[it][j] << "  ";
		}
		cout << "| " << ((-1)*F[it]);
		cout << endl << endl;
	}
}
void CoutOfXAndYAndDeltaXAndResidualVector(int i, double* x, double* y, double *dx1, double* dx2, double* F1, double* F2) {
	
		cout << "x[" << i << "]=" <<setprecision(13)<< x[i] << " " << endl;
		cout << "y[" << i << "]=" << setprecision(13) << y[i] << " " << endl;
		cout << endl;
		cout << "dx1[" << i << "]=" << setprecision(13) << dx1[i] << " " << endl;
		cout << "dx2[" << i << "]=" << setprecision(13) << dx2[i] << " " << endl;
		cout << endl;
		cout << "F1[" << i << "]=" << setprecision(13) << (-1)*F1[i] << " " << endl;
		cout << "F2[" << i << "]=" << setprecision(13) << (-1)*F2[i] << " " << endl;
		cout << endl;

	
}
void SavingDeltaX(int i, double* dx1, double* dx2, double* dx) {
	dx1[i] = dx[0];
	dx2[i] = dx[1];
}
int CalculationOfdelta(int i,double* delta1, double* delta2, double* x,double* y,double* F ){
	double max;
	double max1;
	double eps = pow(10, -9);
	if (abs(F[1]) >= abs(F[2])) {
		max = abs(F[1]);
	}
	else {
		max = abs(F[0]);
	}
	if (abs(x[i]) >= 1) {
		
		max1 = abs((x[i] - x[i - 1]) / x[i]);
	}
	else {
		max1 = abs(x[i] - x[i - 1]);
	}
	if (abs(y[i]) >= 1) {
		if (max1 < abs(y[i] - y[i - 1])) {
			max1 = abs(y[i] - y[i - 1]);
		}
	}
	else {
		if (max1 < abs((y[i] - y[i - 1]) / y[i])) {
			max1 = abs((y[i] - y[i - 1]) / y[i]);
		}
	}
	delta1[i] = max;
	delta2[i] = max1;

	if ((eps > max) && (eps > max1)) {
		return 1;
	}
	else {
		return 0;
	}

}
void CoutOfdelta(double* delta1, double* delta2,int i) {
		cout << "delta1[" << i << "] = " << setprecision(13) << delta1[i] << endl;
		cout << "delta2[" << i << "] = " << setprecision(13) << delta2[i] << endl;
		cout << endl;
	
}