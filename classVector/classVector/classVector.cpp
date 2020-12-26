#include <iostream>

using namespace std;

class Vector {

private:
	int size;
	double* x;

public:

	Vector(int NSize = 0, double* Array = NULL) {
		size = abs(NSize);
		x = NULL;
		if (NSize != 0) {
			x = new double[size];
			for (int i = 0; i < size; i++)
				x[i] = Array[i];
		}
	}

	Vector(const Vector& vector) : x(vector.x), size(vector.size) {}

	void ArrayResize(int NewSize) {
		double* Array = new double[NewSize];
		for (int i = 0; (i < size) && (i < NewSize); i++)
			Array[i] = x[i];

		size = NewSize;

		delete[]x;
		x = Array;
	}

	int Size() {
		return size;
	}

	void add(double value) {
		ArrayResize(size);
		x[size - 1] = value;
	}

	double Scolar(Vector vector) {
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

	friend istream& operator>> (istream& is, Vector& vector) {
		for (int i = 0; i < vector.size; i++) if (vector.x[i] == NULL && vector.x[i] != 0) {
			is >> vector.x[i];
			return is;
		}

		vector.ArrayResize(vector.size + 1);
		is >> vector.x[vector.size - 1];
		return is;

	}

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

	double& operator[](int index) {
		if (size <= index || index < 0) {
			cout << "Error, there is no variable with this index\n";
			exit(0);
		}
		else return x[index];
	}

	~Vector() {
	}

};

int main()
{
	double s[] = { 1,2,3,4,5 };
	Vector v1(5, s), v2;

	for (int i = 0; i < 5; i++) {
		cin >> v2;
	}
	cout << "Vec1:\n" << v1 << "Vec2:\n" << v2;
	cout << "Sum: ";
	cout << v1 + v2;
	cout << "Multi: ";
	cout << v1 * 5;
	cout << "Scolar: ";
	cout << v1.Scolar(v2) << endl;
	cout << "Angle: ";
	cout << v1.Angle(v2) << endl;
	cout << "Large: ";
	cout << (v1 > v2) << endl;
	cout << "Less: ";
	cout << (v1 < v2) << endl;
	Vector v3{ 5,s }, v4{ 5,s };
	cout << endl << "Vec3:\n" << v3 << "Vec4:\n" << v4;
	cout << "Equally: ";
	cout << (v3 == v4) << endl;
	cout << "Not equally: ";
	cout << (v4 != v3) << endl;
	double x[] = { 9,8,7,6,5 };
	Vector v5{ 5,s }, v6{ 5,x };
	cout << endl << "Vec5:\n" << v5 << "Vec6:\n" << v6;
	cout << "Equally: ";
	cout << (v5 == v6) << endl;
	cout << "Not equally: ";
	cout << (v5 != v6) << endl;
	
}
