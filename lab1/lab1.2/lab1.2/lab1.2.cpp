#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	int a, b, n=0, c, k;
	int* mass;
	cout << "Enter the size of massive: ";
	cin >> n;
	mass = new int[n];
	cout << "Enter the diapazone:" << endl;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;

	for (int i = 0; i < n; i++)
	{
		mass[i] = rand() % (b - a + 1) + a;
		cout << mass[i] << " ";
	}

	cout << endl;
	cout << "k = ";
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		if (mass[i] < 0)
		{
			int z = k;
			c = 0;
			while (z > 0)
			{
				z = z / 10;
				c++;
			}
			while (c != 0)
			{
				mass[i] = mass[i] * 10;
				c=c-1;
			}
			mass[i] = mass[i] - abs(k);
		}
		cout << mass[i] << " ";
	}
	return 0;
}