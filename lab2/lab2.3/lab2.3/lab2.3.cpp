﻿#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

void MENU();
void RESULTS(int** n, int* n1, int a, int b);
void WINNERS(int* n, int a);

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, key = 1;
    MENU();
    cout << endl << ":"; cin >> key;
    srand(time(NULL));
    do
        switch (key)
        {
        case 1:
            n = rand() % 31;
            m = rand() % 11;
            break;
        case 2:
            cout << "Введите n и m\n";
            cin >> n;
            cin >> m;
            break;
        case 0:
            cout << "Выход\n";
            break;
        default:
            cout << "ERROR!\n";
            break;
        }
    while (n == 0 || m == 0 || n == 1 || m == 1);
    cout << "Количество стрелков:" << n << "\nКоличество выстрелов:" << m << "\n";
    int** a;
    a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 11;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d", a[i][j]);
        }
        cout << endl;
    }
    int* res;
    res = new int[n];
    RESULTS(a, res, n, m);
    WINNERS(res, n);
    return 0;
}

void MENU()
{
    cout << "\tДобро пожаловать!\n";
    cout << "Выберите метод заполнения:\n";
    cout << endl;
    cout << "1 - Случайно\n";
    cout << "2 - Вручную\n";
    cout << "0 - Выход\n";
}

void RESULTS(int** n, int* n1, int a, int b)
{
    int s;
    for (int i = 0; i < a; i++)
    {
        s = 0;
        for (int j = 0; j < b; j++)
            s += n[i][j];
        n1[i] = s;
    }
    cout << "\nРезультаты: ";
    for (int i = 0; i < a; i++)
        cout << n1[i] << " ";
}

void WINNERS(int* n, int a)
{
    int max, maxI;
    max = n[0];
    for (int i = 0; i < a; i++)
    {
        if (n[i] > max)
            max = n[i];
    }
    cout << "\n" << max << "\nПобедители:\n";
    for (int i = 0; i < a; i++)
    {
        if (n[i] == max)
        {
            cout << "Номер стрелка " << i + 1 << endl;
        }
    }
}