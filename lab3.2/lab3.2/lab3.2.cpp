#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

template <class T>
class Many {
private:
	int size;
	T* x;
public:

	Many(int Nsize = 0, T* Array = NULL) {
		size = abs(Nsize);
		x = NULL;
		if (Nsize != 0) {
			x = new T[size];
			for (int i = 0; i < size; i++)
				x[i] = Array[i];
		}
	}


	int relation(Many& many) {
		bool rel, cross = false;
		for (int i = 0; i < many.size; i++) {
			rel = false;
			for (int j = 0; j < size; j++) {
				if (many[i] == x[j]) {
					cross = true;
					rel = true;
					break;
				}
			}
			if (!rel) break;
		}

		if (!rel)
			for (int i = 0; i < size; i++) {
				rel = false;
				for (int j = 0; j < many.size; j++) {
					if (x[i] == many[j]) {
						rel = true;
						break;
					}
				}
				if (!rel) break;
			}



		if (rel) return -1;
		else if (cross) return 1;
		else return 0;
	}

	int getSize() {
		return size;
	}

	void ArrayResize(int NewSize) {
		T* Array = new T[NewSize];
		for (int i = 0; (i < size) && (i < NewSize); i++)
			Array[i] = x[i];

		size = NewSize;

		delete[]x;
		x = Array;
	}

	bool find(T f) {
		for (int i = 0; i < size; i++)
			if (x[i] == f) return true;
		return false;
	}

	int findElement(T f) {
		for (int i = 0; i < size; i++)
			if (x[i] == f) return i;
		return -1;
	}

	void insert(T val) {
		ArrayResize(size + 1);
		x[size - 1] = val;
	}

	void deleteLast() {
		if (size != 0) ArrayResize(size - 1);
	}

	void deleteIndex(int index) {
		if (index >= 0 && index < size) {
			for (int i = index; i < size - 1; i++)
				x[i] = x[i + 1];
			deleteLast();
		}
		else cout << "Element with such index was not found.\n";
	}

	void deleteDuplicate() {
		Many Nmany;
		for (int i = 0; i < size; i++)
			if (!Nmany.find(x[i])) Nmany.insert(x[i]);
		delete[] x;
		x = Nmany.x;
		size = Nmany.size;
		sort(x, x + size);
	}

	Many operator*(Many& many) {
		Many Nmany;
		for (int i = 0; i < many.size; i++)
			for (int j = 0; j < size; j++)
				if (many[i] == x[j]) Nmany.insert(many[i]);

		Nmany.deleteDuplicate();
		return Nmany;
	}

	Many operator+(Many& many) {
		Many Nmany;

		for (int i = 0; i < many.size; i++)
			Nmany.insert(many[i]);

		for (int j = 0; j < size; j++)
			Nmany.insert(x[j]);

		Nmany.deleteDuplicate();
		return Nmany;
	}

	friend ostream& operator<<(ostream& out, const Many& many) {
		if (many.size == 0) {
			out << "This array empty.\n" << endl;
			return out;
		}
		else {
			for (int i = 0; i < many.size; i++) {
				out << i + 1 << ": " << many.x[i] << endl;
			}

			return out;
		}
	}

	friend istream& operator>>(istream& is, Many& many) {
		T value;
		is >> value;
		many.insert(value);
		return is;
	}

	T& operator[](int index) {
		if (size <= index || index < 0) {
			cout << "Error, there is no variable with this index\n";
			exit(0);
		}
		else return x[index];
	}

	bool equal(T Val) {
		return false;
	}

	~Many() {}
};

template <>
bool Many<int>::equal(int Val) {
	return ((Val % 2) == 0);
}

int main() 
{
	int z[] = { 1,2,3,4,5 };
	Many<int> ma1(5, z), ma2;

	for (int i = 0; i < 5; i++) {
		cin >> ma2;
	}

	cout << "Many1:\n" << ma1 << "Many2:\n" << ma2 << endl;

	cout << "intersections:\n" << ma1 * ma2 << endl;

	cout << "union:\n" << ma1 + ma2 << endl;

	cout << "Find: " << ma2.find(5) << endl;

	ma2.deleteIndex(2);

	cout << "Delete index:\n" << ma2 << endl;
};