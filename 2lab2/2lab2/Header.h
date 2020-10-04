#pragma once
#include <iostream>
using namespace std;

class Complex
{
public:
	float real;
	float img;

public:
	Complex()
	{
	};

	Complex(float C1)
	{
		real = C1;
		img = 0;
	}

	Complex(float C1, float C2)
	{
		real = C1;
		img = C2;
	}

	Complex(const Complex& c)
	{
		real = c.real;
		img = c.img;
	}

	double abs()
	{
		return sqrt(real * real + img * img);
	}

	Complex operator+(const Complex& c)
	{
		return Complex(real + c.real, img + c.img);
	}

	Complex operator*(int n)
	{
		return Complex(real * n, img * n);
	}

	Complex operator*(const Complex& c)
	{
		return Complex(real * c.real, img * c.img);
	}

	Complex operator+=(Complex& c)
	{
		real += c.real;
		img += c.img;
		return *this;
	}
	Complex operator*=(Complex& c)
	{
		real *= c.real;
		img *= c.img;
		return *this;
	}
	Complex operator*=(int n)
	{
		real *= n;
		img *= n;
		return *this;
	}

	bool operator<(int i)
	{
		if ((real < i) && (img < i))
		{
			cout << "True"<<endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	bool operator<(Complex& c)
	{
		if ((real < c.real) && (img < c.img))
		{
			cout << "True" << endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	bool operator>(int i)
	{
		if ((real > i) && (img > i))
		{
			cout << "True" << endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	bool operator>(Complex& c)
	{
		if ((real > c.real) && (img > c.img))
		{
			cout << "True" << endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	bool operator==(int i)
	{
		if ((real == i) && (img == i))
		{
			cout << "True" << endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	bool operator==(Complex& c)
	{
		if ((real == c.real) && (img == c.img))
		{
			cout << "True" << endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	bool operator!=(int i)
	{
		if ((real != i) && (img != i))
		{
			cout << "True" << endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	bool operator!=(Complex& c)
	{
		if ((real != c.real) && (img != c.img))
		{
			cout << "True" << endl; return true;
		}
		else
		{
			cout << "False" << endl; return false;
		}
	}

	friend ostream& operator<< (ostream&, const Complex&);
	friend istream& operator>> (istream&, Complex&);
};

ostream& operator<< (ostream& out, const Complex& c)
{
	out << "(" << c.real << ", " << c.img << ")";
	return out;
}

istream& operator>> (istream& in, Complex& c)
{
	in >> c.real >> c.img;
	return in;
}
