#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void selectionSort(int* num, int size)
{
	int min, temp;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (num[j] < num[min])
				min = j;
		}
		temp = num[i];
		num[i] = num[min];
		num[min] = temp;
	}
}

int main()
{
	ifstream input("massive.txt");
	int a, count = 0;
	while (input >> a)
		count++;
	cout << "amount of numbers: " << count << endl;
	int* mass;
	mass = new int[count];
	string path = "C:\\Users\\Fabillippa\\Desktop\\lab1\\lab1.1\\lab1.1\\massive.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error";
		return 0;
	}
	int countIndexMas = 0;
	for (int i = 0; i < count; i++)
	{
		int temp;
		fin >> temp;
		if (temp < 0)
		{
			mass[countIndexMas++] = temp;
		}
	}
	selectionSort(mass, countIndexMas);
	for (int i = 0; i < countIndexMas; i++)
		cout << mass[i] << "\n";

	return 0;
}