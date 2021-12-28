#include <iostream>
#include <windows.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int ErrorofEnter()
{
    while (true)
    {
        int n;
        cout << "Введите количество критериев от 3 до 7 : " ;
        cin >> n;
        if ((n > 0)& (n < 8))
            return(n);
        else
            cout << "Error" << endl;
        cin.clear();
        cin.ignore();
    }
}
int ErrorofEnter1(int i, int j)
{
    while (true)
    {
        int n;
        cout << "Введите элемент матрицы ["<<j<<" "<<i<< "] парных значений : " ;
        cin >> n;
        if ((n > 0)& (n < 10))
            return(n);
        else
            cout << "Error" << endl;
        cin.clear();
        cin.ignore();
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Программа оценки критериальных значений Томаса Саати" << endl;
    cout << "Значения критериев: " << endl;
    cout << "1- равноценность;" << endl;
    cout << "3- умеренное превосходство;" << endl;
    cout << "5- сильное превосходство;" << endl;
    cout << "7- очень сильное превосходство;" << endl;
    cout << "9- высшее (крайнее) превосходство;" << endl;
    int n=ErrorofEnter();
    vector<vector<float> > a(n, vector<float>(n, 1.0));
    vector<float> sum(n,1);
    float sumofsum=0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1 + j; i < n; i++)
        {   
            a[j][i]= ErrorofEnter1(i,j);
            a[i][j] = 1 / a[j][i];
        }
    }
    cout << endl;
    cout << "Матрица попарных критериев :" << endl << endl;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0 ; i < n; i++)
        {   
            sum[j] = a[j][i] + sum[j];
            printf ( "%4.2f",a[j][i]);
            cout << " ";
        }
        cout << endl << endl;
    }
    for (int j = 0; j < n; j++)
    {   
        sum[j] = sum[j] - 1;
        sumofsum = sumofsum + sum[j];
    }
    for (int j = 0; j < n; j++)
    {
        sum[j] = sum[j] / sumofsum;
        cout << "Весовой коэффициент для "<<j<<" строки   ";
        printf("%4.2f", sum[j]);
        cout << endl;
    }
   
	return(0);
}