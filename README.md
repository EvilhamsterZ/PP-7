# Lab-6
## Лабораторная номер 6 Шифр Цезаря
## Описание программы
Написать на любом языке программу, реализующую метод анализа иерархий Томаса Саати для одного уровня.
Входные данные: количество критериев, данные попарного сравнения критериев.
Выходные данные: весовые коэффициенты в виде 0.00
Код программы должен содержать комментарии для созданных функций и основных блоков, а также качественный диалог с пользователем для минимизации отказов при неправильном вводе.
## Ограничение по входным данным
ограничимся 4-7 критериями Томаса Саати, где критерии 
###### 1 - равноценность;
###### 3	- умеренное превосходство;
###### 5	- сильное превосходство;
###### 7	- очень сильное превосходство;
###### 9	- высшее (крайнее) превосходство;
## Описание среды программирования проекта 
Для использования приложения требуется Visual studio 2019, а также скачать файлы с данного репозитория а именно
ConsoleApplication1.sln
ConsoleApplication1.cpp
ConsoleApplication1.vcxproj


Открывать следует ConsoleApplication1.cpp это исходник приложения
В программе запуск осуществляется клавишей F5;
Ввод осуществляется с клавиатуры//завершение ввода через ENTER;

### КОД
```
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
```
## Отладка
для 4 критериев

![image](https://user-images.githubusercontent.com/90544365/147556251-2670f2d1-ea9d-418b-ae8b-a5e8d3f57f52.png)

для 7 критериев
![image](https://user-images.githubusercontent.com/90544365/147556535-b7188328-cc81-4f3f-840e-e7f2e734ce81.png)
