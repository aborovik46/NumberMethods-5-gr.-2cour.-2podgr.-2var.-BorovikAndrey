#include "Header_CM_5_Integral_var2.h";
double Function1(double x) {
	return 1/ (sqrt(x * x * x - 1));		
}
double Function2(double x,double y) {
	return 1 / pow((x + y),2);
}
double CalculationByTrapezoid(double eps,double a,double b,int n, double& R) {
	double h = (b - a) / n;
	double IntegralByTrapezoidH = 0;
	double IntegralByTrapezoidH2 = 0;
	do {
		IntegralByTrapezoidH = IntegralByTrapezoidH2;
		h /= 2;
		IntegralByTrapezoidH2 = ((Function1(a) + Function1(b)) * h)/2 ;
		for (double x = a + h; x < b; x += h)
			IntegralByTrapezoidH2 += h * Function1(x);
	} while (abs(IntegralByTrapezoidH2 - IntegralByTrapezoidH) >= (3 * eps));
	R = (IntegralByTrapezoidH - IntegralByTrapezoidH2) * (0.5 * 0.5 - 1);
	cout << IntegralByTrapezoidH << endl;
	return IntegralByTrapezoidH2;
}
double CalculationBySimpson(double eps, double a, double b, int n, double& R) {
	double h = (b - a) / n;
	int m = n / 2;
	double IntegralBySimpsonH = 0;
	double IntegralBySimpsonH2 = 0;
	do {
		IntegralBySimpsonH = IntegralBySimpsonH2;
		IntegralBySimpsonH2 = (Function1(a) + Function1(b)) * h / 3;
		double x = a + h;
		for (int i = 1; i <= m; i++) {
			IntegralBySimpsonH2 += 4 * h / 3 * Function1(x);
			x += 2 * h;
		}
		x = a + 2 * h;
		for (int i = 1; i < m; i++) {
			IntegralBySimpsonH2 += 2 * h / 3 * Function1(x);
			x += 2 * h;
		}
		h /= 2;
		m *= 2;
	} while (abs(IntegralBySimpsonH2 - IntegralBySimpsonH) >= (15 * eps));
	R = (IntegralBySimpsonH - IntegralBySimpsonH2) * (0, 5 * 0, 5 * 0, 5 * 0, 5 - 1);
	return IntegralBySimpsonH2;
}
double CalculatingBySimpsonCubaturn(double a2,double b2,double c,double d,double M,double N) {		
	double hx = (b2 - a2) / (2*N);
	double hy = (d - c) / (2*M);
	double IntegralBySimpsonCubaturn = 0;
	for (int i = 0; i <= N - 1; i++) {
		for (int j = 0; j <= M - 1; j++) {
			IntegralBySimpsonCubaturn += Function2(a2, c) + 4 * Function2(a2 + hx, c) +
				Function2(b2, c) + 4 * Function2(a2, c + hy) +
				16 * Function2(a2 + hx, c + hy) + 4 * Function2(b2, c + hy) +
				Function2(a2, d) + 4 * Function2(a2 + hx, d) +
				Function2(b2, d);
		}
	}
	IntegralBySimpsonCubaturn *= (hx * hy) / 9;
	return IntegralBySimpsonCubaturn;
}