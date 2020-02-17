#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream input("massive.txt");
	float ch; int count = 0;
	while (input >> ch)
		count++;
	cout << count << endl;
	int* mass;
	mass = new int[count];
	string path = "C:\\Users\\Fabillippa\\source\\repos\\lab1.1\\massive.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error";
	}
	for (int i = 0; i < count; i++)
		fin >> mass[i];
	for (int i = 0; i < count; i++)
		cout << mass[i] << "\n";
	return 0;
}