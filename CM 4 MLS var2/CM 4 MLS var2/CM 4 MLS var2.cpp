// CM 4 MLS var2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header_CM_4_MLS_var2.h"// В этом файле расписаны значения функций
using namespace std;

int main()
{
    const int N = 9;//кол-во заданных для нас Х-ов
    double x[N]{ 0,1,2,3,4,5,6,7,8 };//Заданные Х
    int m = 4;//Порядок необходимого для нас полинома
    double** matrix = new double*[m + 1];

    IntializationOfMatixElements(m, matrix);
    double EPS = 0;
    CoutOfX(N, x);
    CoutOfY(N, x);
    double* SumX = new double[2 * m + 1];
    double* SumY = new double[m + 1];
    CalculatingDifferentSums(m, N, x, SumX, SumY);
    double* b = new double[m + 1];
    MatrixInputation(m,matrix, b, SumY,SumX,x);
    CoutInitialMatrix((m+1),matrix,b);
    double* a = new double[m + 1];
    ExpandedMatrixComputation(m,matrix,b,a);
    CoutInitialMatrix((m + 1), matrix, b);
    CoutOfA(m,a);
    for (int i = 0; i < N; i++)
        cout << "Expectation: " << Function2(a,x[i]) << " Reality: " << Function1(x[i]) << endl;
    CalculationOfEPS(m,N,EPS,a,x);
    cout << "EPS =" << EPS << endl;
    cout << "y = " << a[0] << " + " << a[1] << " * x +" << a[2] << " * x^2 + " << a[3] << " * x^3 + " << a[4] << "* x^4" << endl;











}


