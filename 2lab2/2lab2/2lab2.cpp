#include "Header.h"

	int main()
	{
		Complex a, b;
		a.real = 3; a.img = 3;
		b.real = 3; b.img = 6;
		cout <<"a = "<< a <<" b = " << b << endl;
		int i = 3; cout << "i = " << i << endl;
		cout << "a < i"<<" "; a < i;
		cout << "a < b" << " "; a < b;
		cout << "a > i" << " "; a > i;
		cout << "a > b" << " "; a > b;
		cout << "a == i" << " "; a == i;
		cout << "a == b" << " "; a == b;
		cout << "a != i" << " "; a != i;
		cout << "a != b" << " "; a != b;
		cout <<"a + b = "<< a + b << endl;
		cout <<"a * i = "<< a * i << " b*i = " << b * i << endl;
		cout <<"a * b = "<< a * b << endl;
		a += b;
		cout <<"a +=b " << a << " " << b << endl;
		a *= b;
		cout << "a *=b " << a << " " << b << endl;
		a *= i; b *= i;
		cout << "a *=i " << a << " b*=i " << b << endl;
		
		return 0;
	}

