#include<iostream>

using namespace std;

struct complex
{
        double p, q;
};

void сplus(complex a, complex b)
{
    cout << "Сумма :" << a.p + b.p << " " << a.q + b.q << endl;
}

void cmultiplication(complex a, complex b)
{
    cout << "Произведение :" << a.p * b.p << " " << a.q * b.q;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    complex a, b;
    cout << "Complex a: ";
    cin >> a.p >> a.q;
    cout << "Complex b: ";
    cin >> b.p >> b.q;
    сplus(a, b);
    cmultiplication(a, b);
    return 0;

}