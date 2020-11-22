#include <iostream>
#include <string>
#include <algorithm>
#include "Header.h"
using namespace std;

class ComplexNumbers {
private:
	double a, b, i;

public:

	ComplexNumbers(double A = 0, double B = 0) {
		a = A;
		b = B;
		i = 1;
	}

	ComplexNumbers(const ComplexNumbers& complex) : a(complex.a), b(complex.b) {}

	void seta(double A) {
		a = A;
	}

	void setb(double B) {
		b = B;
	}

	void setab(double A, double B) {
		a = A;
		b = B;
	}

	double geta() {
		return a;
	}

	double getb() {
		return b;
	}

	double LengthComplex() {
		return abs(sqrt((a * a) + (b * b)));
	}

	friend ComplexNumbers operator+(const ComplexNumbers& c1, const ComplexNumbers& c2) {
		return ComplexNumbers(c1.a + c2.a, c1.b + c2.b);
	}

	friend ComplexNumbers operator-(const ComplexNumbers& c1, const ComplexNumbers& c2) {
		return ComplexNumbers(c1.a - c2.a, c1.b - c2.b);
	}

	friend ComplexNumbers operator*(const ComplexNumbers& c1, const ComplexNumbers& c2) {
		return ComplexNumbers(((c1.a * c2.a) + (c1.b * c2.b) * -1), ((c1.b * c2.a) + (c1.a * c2.b)));
	}

	friend ComplexNumbers operator/(const ComplexNumbers& c1, const ComplexNumbers& c2) {
		return ComplexNumbers((((c1.a * c2.a) + (c1.b * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b))), (((c1.b * c2.a) - (c1.a * c2.b)) / ((c2.a * c2.a) + (c2.b * c2.b))));
	}

	bool operator>(ComplexNumbers& complex) {
		return LengthComplex() > complex.LengthComplex();
	}

	bool operator<(ComplexNumbers& complex) {
		return LengthComplex() < complex.LengthComplex();
	}

	bool operator==(ComplexNumbers& complex) {
		return LengthComplex() == complex.LengthComplex();
	}

	bool operator!=(ComplexNumbers& complex) {
		return LengthComplex() != complex.LengthComplex();
	}

	friend ostream& operator<<(ostream& out, const ComplexNumbers& complex) {
		if (complex.i == 0) {
			if (complex.a == 0 && complex.b == 0) out << "0\n";
			else if (complex.a == 0) out << complex.b << endl;
			else if (complex.b == 0) out << complex.a << endl;
			else if (complex.b > 0) out << complex.a << " + " << complex.b << endl;
			else out << complex.a << " " << complex.b << endl;
		}
		else {
			if (complex.a == 0 && complex.b == 0) out << "0\n";
			else if (complex.a == 0) out << complex.b << "*i\n";
			else if (complex.b == 0) out << complex.a << endl;
			else if (complex.b > 0) out << complex.a << " + " << complex.b << "*i\n";
			else out << complex.a << " " << complex.b << "*i\n";
		}
		return out;
	}

	friend istream& operator>> (istream& is, ComplexNumbers& complex) {
		is >> complex.a >> complex.b;
		return is;
	}

};



template<class T> class Vector;
template<class T>
istream& operator>> (istream& is, Vector<T>& vector);

template <class T>
class Vector {
private:
	int size;
	T* x;

public:

	Vector(int NSize = 0, T* Array = NULL) {
		size = abs(NSize);
		x = NULL;
		if (NSize != 0) {
			x = new T[size];
			for (int i = 0; i < size; i++)
				x[i] = Array[i];
		}
	}

	Vector(const Vector<T>& vector) : x(vector.x), size(vector.size) {}

	void ArrayResize(int NewSize) {
		T* Array = new T[NewSize];
		for (int i = 0; (i < size) && (i < NewSize); i++)
			Array[i] = x[i];

		size = NewSize;

		delete[]x;
		x = Array;
	}

	int Size() {
		return size;
	}

	void add(T value) {
		ArrayResize(size);
		x[size - 1] = value;
	}

	double Scolar(Vector<T> vector) {
		return ((x[0] * vector.x[0]) + (x[1] * vector.x[1]));
	}


	double Angle(Vector vector) {

		return cos(Scolar(vector) / (LengthVector() * vector.LengthVector()));
	}


	double LengthVector() {
		double Summ = 0;
		for (int i = 0; i < size - 1; i++)
			Summ += abs(sqrt((x[i] * x[i]) + (x[i + 1] * x[i + 1])));
		return Summ;
	}

	friend istream& operator>> <T>(istream& is, Vector& vector);

	friend ostream& operator<<(ostream& out, const Vector& vector) {
		if (vector.size == 0) {
			out << "This array empty.\n" << endl;
			return out;
		}
		else {
			for (int i = 0; i < vector.size; i++) {
				out << i + 1 << ": " << vector.x[i] << endl;
			}

			return out;
		}
	}

	friend Vector operator+(const Vector& v1, const Vector& v2) {
		Vector vector;
		if (v1.size != v2.size) {
			cout << "Error, different size vectors.\n";
			exit(0);
		}
		else {
			vector.ArrayResize(v1.size);
			for (int i = 0; i < vector.size; i++) vector.x[i] = v1.x[i] + v2.x[i];
		}
		return vector;
	}

	friend Vector operator*(const Vector& v1, int a) {
		Vector vector;
		vector.ArrayResize(v1.size);
		for (int i = 0; i < v1.size; i++) vector.x[i] = v1.x[i] * a;
		return vector;
	}

	bool operator>(Vector& vector) {

		return LengthVector() > vector.LengthVector();
	}

	bool operator<(Vector& vector) {
		return LengthVector() < vector.LengthVector();
	}

	bool operator==(Vector& vector) {
		return LengthVector() == vector.LengthVector();
	}

	bool operator!=(Vector& vector) {
		return LengthVector() != vector.LengthVector();
	}

	T& operator[](int index) {
		if (size <= index || index < 0) {
			cout << "Error, there is no variable with this index\n";
			exit(0);
		}
		else return x[index];
	}

	~Vector() {
	}

};

template<>
double Vector<ComplexNumbers>::LengthVector() {
	double Summ = 0;
	for (int i = 0; i < size - 1; i++)
		Summ += abs(sqrt((x[i].geta() * x[i].geta()) + (x[i].getb() * x[i].getb())));
	return Summ;
}

template <>
istream& operator>>(istream& is, Vector<ComplexNumbers>& vector) {
	for (int i = 0; i < vector.size; i++) if (vector.x[i].geta() == NULL && vector.x[i].geta() != 0) {
		is >> vector.x[i];
		return is;
	}

	vector.ArrayResize(vector.size + 1);
	is >> vector.x[vector.size - 1];
	return is;

}

template <class T>
istream& operator>>(istream& is, Vector<T>& vector) {
	for (int i = 0; i < vector.size; i++) if (vector.x[i] == NULL && vector.x[i] != 0) {
		is >> vector.x[i];
		return is;
	}

	vector.ArrayResize(vector.size + 1);
	is >> vector.x[vector.size - 1];
	return is;

}

template <>
double Vector<ComplexNumbers>::Scolar(Vector<ComplexNumbers> vector) {
	return ((x[0] * vector.x[0]).geta() + (x[1] * vector.x[1]).geta()) + ((x[0] * vector.x[0]).getb() + (x[1] * vector.x[1]).getb());
}


int main() {
	setlocale(LC_ALL, "Russian");
	double s[] = { 1.5,2.7,3.3,4.9,5.1 };
	Vector<double> v1(5, s), v2;
	cout << "Double " << endl;

	cout << "Введите вектор 2: " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> v2;
	}
	cout << "Vec1:\n" << v1 << "Vec2:\n" << v2;

	cout << "Сумма: ";
	cout << v1 + v2;

	cout << "Произведение: ";
	cout << v1 * 5;

	cout << "Скалярное произведение: ";
	cout << v1.Scolar(v2) << endl;

	cout << "Угол: ";
	cout << v1.Angle(v2) << endl;

	cout << "v1 больше v2: ";
	cout << (v1 > v2) << endl;

	cout << "v1 меньше v2: ";
	cout << (v1 < v2) << endl;


	Vector<double> v3{ 5,s }, v4{ 5,s };

	cout << endl << "Vec3:\n" << v3 << "Vec4:\n" << v4;

	cout << "Равны: ";
	cout << (v3 == v4) << endl;

	cout << "Не равны: ";
	cout << (v4 != v3) << endl;

	double x[] = { 1.7,2.1,3.4,4.5,5.5 };
	Vector<double> v5{ 5,s }, v6{ 5,x };

	cout << endl << "Vec5:\n" << v5 << "Vec6:\n" << v6;

	cout << "Равны: ";
	cout << (v5 == v6) << endl;

	cout << "Не равны: ";
	cout << (v5 != v6) << endl;

	int a[] = { 5,7,3,9,1 };
	Vector<int> n1(5, a), n2;
	cout << "Введите вектор 2: " << endl;

	cout << "Int " << endl;

	for (int i = 0; i < 5; i++) {
		cin >> n2;
	}

	cout << "Vec1:\n" << n1 << "Vec2:\n" << n2;

	cout << "Сумма: ";
	cout << n1 + n2;

	cout << "Произведение: ";
	cout << n1 * 5;

	cout << "Скалярное произведение: ";
	cout << n1.Scolar(n2) << endl;

	cout << "Угол: ";
	cout << n1.Angle(n2) << endl;

	cout << "Больше: ";
	cout << (n1 > n2) << endl;

	cout << "Меньше: ";
	cout << (n1 < n2) << endl;


	Vector<int> n3{ 5,a }, n4{ 5,a };

	cout << endl << "Vec3:\n" << n3 << "Vec4:\n" << n4;

	cout << "Равны: ";
	cout << (n3 == n4) << endl;

	cout << "Не равны: ";
	cout << (n4 != n3) << endl;

	int d[] = { 9,8,7,6,5 };
	Vector<int> n5{ 5,d }, n6{ 5,d };

	cout << endl << "Vec5:\n" << n5 << "Vec6:\n" << n6;

	cout << "Равны: ";
	cout << (n5 == n6) << endl;

	cout << "Не равны: ";
	cout << (n5 != n6) << endl;


	ComplexNumbers c[5] = { ComplexNumbers(1,2),ComplexNumbers(2,3),ComplexNumbers(3,4),ComplexNumbers(4,5),ComplexNumbers(5,6) };
	Vector<ComplexNumbers> k1(5, c), k2;

	cout << "Complex: " << endl;

	cout << "Введите комплексное число: " << endl;
	for (int i = 0; i < 5; i++) {
		cin >> k2;
	}
	cout << "Vec1:\n" << k1 << "Vec2:\n" << k2;

	cout << "Сумма: ";
	cout << k1 + k2;

	cout << "Произведение: ";
	cout << k1 * 5;

	cout << "Скалярное произведение: ";
	cout << k1.Scolar(k2) << endl;

	cout << "Угол: ";
	cout << k1.Angle(k2) << endl;

	cout << "Больше: ";
	cout << (k1 > k2) << endl;

	cout << "Меньше: ";
	cout << (k1 < k2) << endl;




	ComplexNumbers c1[5] = { ComplexNumbers(1,2),ComplexNumbers(2,3),ComplexNumbers(3,4),ComplexNumbers(4,5),ComplexNumbers(5,6) };
	Vector<ComplexNumbers> p3{ 5,c1 }, p4{ 5,c1 };

	cout << endl << "Vec3:\n" << p3 << "Vec4:\n" << p4;

	cout << "Равны: ";
	cout << (p3 == p4) << endl;

	cout << "Не равны: ";
	cout << (p4 != p3) << endl;

	ComplexNumbers c2[5] = { ComplexNumbers(6,5),ComplexNumbers(5,4),ComplexNumbers(4,3),ComplexNumbers(3,2),ComplexNumbers(2,1) };
	Vector<ComplexNumbers> p5{ 5,c1 }, p6{ 5,c2 };

	cout << endl << "Vec5:\n" << p5 << "Vec6:\n" << p6;

	cout << "Равны: ";
	cout << (p5 == p6) << endl;

	cout << "Не равны: ";
	cout << (p5 != p6) << endl;
}