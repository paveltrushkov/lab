#include <iostream>
#include <cmath>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	double s[] = { 1,2,3 };
	Matrix Matr1(3, 3), Matr2;
	Vector vec1;
	Matr2.setSize(3, 3);
	cout << "Введите матрицу номер 1:\n"; cin >> Matr1;
	cout << "Введите матрицу номер 2:\n"; cin >> Matr2;
	cout << "1 матрица:\n" << Matr1
		<< "2 матрица:\n" << Matr2 << "\n"
		<< "Сумма матриц: " << Matr1 + Matr2 << "\n"
		<< "Умножение матрицы на число: \n"
		<< "Введите число: "; cin >> k;
	cout << Matr1 * k << "\n"
		<< "Умножение матриц: " << Matr1 * Matr2 << "\n"
		<< "Умножение матриц на вектор:\n";
	for (int i = 0; i < 3; i++)
	{
		cin >> vec1;
	}
	cout << "Вектор: \n" << vec1 << "\n" << Matr1 * vec1;
}