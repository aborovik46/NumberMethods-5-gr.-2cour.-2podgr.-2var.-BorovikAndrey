// CM 5 Integral var2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header_CM_5_Integral_var2.h"


int main()
{
    double a = 1.3;//Данные из 2 варианта
    double b = 2.621;//Данные из 2 варианта
    double eps1 = 1e-4;//Критерий завершения
    double eps2 = 1e-5;//Критерий завершения
    double R = 0;//Переменная для Погрешности
    double a2 = 3;//Данные из 30 варианта
    double b2 = 4;//Данные из 30 варианта
    double c = 1;//Данные из 30 варианта
    double d = 2;//Данные из 30 варианта
    int n=2;
    int ch;
    cout << "With what error do you want to calculate the integrals?(1 - 10^-4,2 - 10^-5)"<<endl;
    cin >> ch;
    switch (ch) {
    case 1:
        cout << "Area by Trapezoid with eps ( " << eps1 << ") = " << setprecision(10) << CalculationByTrapezoid(eps1,a,b,n,R) << ", R = " << R << endl;
        cout << "Area by Simpson with eps (" << eps1 << ") = " << CalculationBySimpson(eps1,a,b,n, R) << ", R = " << R << endl;
    break;
    case 2:
        cout << "Area by Trapezoid with eps (" << eps2 << ") = " << setprecision(10) << CalculationByTrapezoid(eps2, a, b, n, R) << ", R = " << R << endl;
        cout << "Area by Simpson with eps (" << eps2 << ") = " << CalculationBySimpson(eps2, a, b, n, R) << ", R = " << R << endl;
    break;
    default:
        cout << "Error" << endl;
        exit(0);
    break;
    }
    cout << "Area by Simpson cubaturn : " << CalculatingBySimpsonCubaturn(a2,b2,c,d) << endl;



}

