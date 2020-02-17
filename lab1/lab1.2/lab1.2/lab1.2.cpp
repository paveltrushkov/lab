#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main()
{
	int a, b, n, y = 0, k, count = 0;
	int* mass;
	cout << "Enter the size of massive:";
	cin >> n;
	mass = new int[n];
	cout << "Enter the diapazone:"; cin >> a; cin >> b; cout << endl;
	for (int i = a; i < b; i++)
	{
		mass[i] = (rand() % 10 - 10);
		cout << mass[i] << "\n";
		count++;
	}
	cout << "k = ";
	cin >> k;
	for (int i = a; i < b; i++)
	{
		mass[i] = mass[i] * 10 + (-k);
		cout << mass[i] << "\n";
	}
	return 0;
}