#include <iostream>
using namespace std;

int stepen(int);

int main()
{
    int m;
    cout << "Stepen: "; cin >> m;
    cout << "Answer : " << stepen(m);

    return 0;
}


int stepen(int n)
{
    if (n >= 1)
    {
        return 2 * stepen(n - 1);
    }
    else
        if (n == 0)
            return 1;
        else
        {
            cout << "Error\n";
            return 0;
        }
}
