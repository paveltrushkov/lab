#include <iostream>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>
using namespace std;

void fieldView(int** a, int n, int m);
int livingPoints(int** a, int n, int m);
void neighborhood(int nb[][2], int x, int y);
int amountLivingNB(int** a, int n, int m, int x, int y);
void nextgen(int** a, int** a1, int n, int m);
void copy(int** a, int** a1, int n, int m);
int fieldsCompare(int** a, int** a1, int n, int m);
void menu();//меню


int main()
{
    setlocale(LC_ALL, "Russian");
    int n, m, key;
    menu();
    cout << endl << ":"; cin >> key;
    srand(time(NULL));
    do
        switch (key)
        {
        case 1:
            n = rand() % 21;
            m = rand() % 21;
            break;
        case 2:
            cout << "Введите количество строк(n) и столбцов(m)\n";
            cout << "Количество строк(n) = "; cin >> n;
            cout << "Количество столбцов(m) = "; cin >> m;
            break;
        case 0:
            cout << "Пока пока\n";
            break;
        default:
            cout << "Произошли технические шоколадки\n";
            break;
        }
    while (n < 3 || m < 3);
    cout << "\nРазмер поля: " << n << " строк и " << m << " столбцов\n";
    int** field;
    field = new int* [n];
    for (int i = 0; i < n; i++)
        field[i] = new int[m];
    if (key==1)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 10000);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int num = dis(gen);
                if (num % 2 == 0)
                    field[i][j] = 1;
                else
                    field[i][j] = 0;
            }
    }
    else
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cout << "X[" << i + 1 << "]" << " Y[" << j+1 << "] = ";
                cin >> field[i][j];

            }
    }
    int** PreviousField;
    PreviousField = new int* [n];
    for (int i = 0; i < n; i++)
    {
        PreviousField[i] = new int[m];
    }
    int livingpoints = -1;
    int answer = 0;
    bool Edem = false;
    do
    {
        fieldView(field, n, m);
        copy(field, PreviousField, n, m);
        nextgen(field, PreviousField, n, m);
        cout << "Дальше?\n0 - Да\n1 - Нет\nОтвет: "; cin >> answer;
        Edem = fieldsCompare(field, PreviousField, n, m) == 0;
        livingpoints = livingPoints(field, n, m);
        if (answer || Edem || livingpoints == 0)
        {
            cout << "End.\n";
            return 0;
        }
    } while (livingpoints != 0 || !Edem || answer ==0);
    return 0;
}

void menu()
{
    cout << "\tOh, hi user\n";
    cout << "Выберите метод заполнения поля:\n";
    cout << endl;
    cout << "1 - Заполнить поле случайным образом\n";
    cout << "2 - Вручную заполнить поле\n";
    cout << "0 - Выход\n";
}

void fieldView(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                cout << '*';
            else
                cout << ' ';
            cout << ' ';
        }
        cout << endl;
    }
}

int livingPoints(int** a, int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 1)
                count++;
    return count;
}

void neighborhood(int nb[][2], int x, int y)
{
    int k = 0;
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i == x && j == y)
                continue;
            nb[k][0] = i;
            nb[k][1] = j;
            k++;
        }
}

int amountLivingNB(int** a, int n, int m, int x, int y)
{
    int count = 0;
    int nb[8][2];
    int x_, y_;
    neighborhood(nb, x, y);
    for (int i = 0; i < 8; i++)
    {
        x_ = nb[i][0];
        y_ = nb[i][1];
        if (x_ < 0 || y_ < 0)
            continue;
        if (x_ >= n || y_ >= m)
            continue;
        if (a[x_][y_] == 1)
            count++;
    }
    return count;
}

void nextgen(int** a, int** a1, int n, int m)
{
    int livingNB, p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            p = a1[i][j];
            livingNB = amountLivingNB(a1, n, m, i, j);
            if (p == 0)
            {
                if (livingNB == 3)
                    a[i][j] = 1;
            }
            else
                if (livingNB < 2 || livingNB > 3)
                    a[i][j] = 0;
        }
}

void copy(int** a, int** a1, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a1[i][j] = a[i][j];
}

int fieldsCompare(int** a, int** a1, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != a1[i][j])
                return -1;
    return 0;
}