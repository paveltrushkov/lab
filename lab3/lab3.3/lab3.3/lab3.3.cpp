#include <iostream>
#include <fstream> 
using namespace std;

int main()
{
    char string_1[256];
    const char ch = '\n';
    const int len = 41, strings = 3;
    char mass[strings][len];

    ifstream fs("strings.txt");

    if (!fs) return 1; //Если ошибка открытия файла, то завершаем программу

    for (int r = 0; r < 3; r++)
    {
        fs.getline(mass[r], len - 1, ch); //Считываем строки в массив
    }
    strcpy_s(string_1, mass[0]);//копируем отедельно нужную строку
    cout << "Before sorting: " << string_1 << endl;
    char* str = new char[300];
    str = string_1;
    int words[150];
    int num, i, j, temp, flag;
    for (num = 0, flag = 1, i = 0; str[i]; i++)//считаем слова
    {
        if (str[i] == ' ')
        {
            str[i] = 0;
            flag = 1;
        }
        else if (flag)
        {
            words[num++] = i;
            flag = 0;
        }
    }
    for (j = num - 1; j > 0; j--)//"сортировка"
        for (i = 0; i < j; i++)
            if (strcmp(&str[words[i]], &str[words[i + 1]]) > 0)
            {
                temp = words[i];
                words[i] = words[i + 1];
                words[i + 1] = temp;
            }
    cout << endl << "After sorting:\n";
    for (i = num - 1; i >= 0; i--)
    {
        cout << &str[words[i]] << " ";
    }
    fs.close(); //Закрываем файл
    return 0;
}