#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Equal {
    int _this;
public:
    Equal(int th) : _this(th) {}
    bool operator()(int i) {
        return i == _this;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream fh("text.txt");
    int n; int b; int c = 0;
    vector<int> a;
    int s;
    while (fh >> s) {
        a.push_back(s);
    }
    for (int i = 0; i < a.size(); i++) {
        cout << "a[" << i + 1 << "]" << " = " << a[i] << endl;
    }
    cout << "Введите n = " << endl;
    cin >> n;
    cout << "Числа равные n " << endl;
    vector<int>::iterator it = find(a.begin(), a.end(), n);
    while (it != a.end())
    {
        int index = distance(a.begin(), it);
        cout << "a[" << index + 1 << "]" << " = " << a[index] << endl;
        ++it;
        it = find(it, a.end(), n);
    }
    size_t Equalu = count_if(a.begin(), a.end(),Equal(n));
    cout << "Количество чисел, равных n = " << Equalu << endl;
    size_t evenCount = count_if(a.begin(), a.end(), [](int i) {return i % 2 == 0; });
    cout << "Количество чётных чисел = " << evenCount << endl;
    it = find_if(a.begin(), a.end(), [](int i) {return i % 2 == 0; });
    cout << "Чётные элементы " << endl;
    while (it != a.end())
    {
        int index = distance(a.begin(), it);
        cout << "a[" << index + 1 << "]" << " = " << a[index] << endl;
        ++it;
        it = find_if(it, a.end(), [](int i) {return i % 2 == 0; });
    }
    size_t oddCount = count_if(a.begin(), a.end(), [](int i) {return i % 2 == 1; });
    cout << "Количество нечётных чисел = " << oddCount << endl;
    cout << "Нечётные элементы " << endl;
    it = find_if(a.begin(), a.end(), [](int i) {return i % 2 == 1; });
    while (it != a.end())
    {
        int index = distance(a.begin(), it);
        cout << "a[" << index + 1 << "]" << " = " << a[index] << endl;
        ++it;
        it = find_if(it, a.end(), [](int i) {return i % 2 == 1; });
    }
    int sum=0;
    if (evenCount > oddCount) {
        it = find_if(a.begin(), a.end(), [](int i) {return i % 2 == 0; });
        while (it != a.end())
        {
            int index = distance(a.begin(), it);
            sum+=a[index];
            ++it;
            it = find_if(it, a.end(), [](int i) {return i % 2 == 0; });
        }
        cout << "Сумма чётных чисел : " << sum;
    }
    else {
        for_each(a.begin(), a.end(), [&](int n) {
            sum += n;
            });
        cout << "Сумма всех чисел : " << sum << endl;
    }
    cout << "Исходный вид: " << endl;
    it = a.begin();
    int m = 0;
    while (it != a.end()) {
        m++;
        cout << "a[" << m << "]" << " = " << *it << endl;
        it++;
    }
    sort(a.begin(), a.end());
    cout << "Отсортированный вид: " << endl;
    it = a.begin();
    m = 0;
    while (it != a.end()) {
        m++;
        cout << "a[" << m << "]" << " = " << *it << endl;
        it++;
    }
    int size = a.size();
    swap(a[0], a[size-1]);
    cout << "Поменяли первое и последнее : " << endl;
    it = a.begin();
    m = 0;
    while (it != a.end()) {
        m++;
        cout << "a[" << m << "]" << " = " << *it << endl;
        it++;
    }
    return 0;
}
