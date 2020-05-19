#include <iostream>
using namespace std;

float srednee(int* mas, float s, int k, int n, int a, int i)
{

    if (mas[i] > n)
    {
        s += mas[i];
        k++;
    }
    i++;
    if (i == a)
    {
        return s / k;
    }
    else
        return srednee(mas, s, k, n, a, i);

}

int main()
{

    int i; float sred, s, n;
    cout << "n = "; cin >> n;
    cout << "Vvedite razmer massiva: ";
    cin >> s;
    int* mas = new int[s];
    for (i = 0; i < s; i++)
    {
        cout << "Vvedite mas[" << i + 1 << "]: ";
        cin >> mas[i];
    }
    cout << endl;

    sred = srednee(mas, 0, 0, n, s, 0);
    cout << "Srednee : " << sred << endl;

    return 0;
}
