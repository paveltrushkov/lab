#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int next_word_length(const char*& str);

int main()
{
	char string_1[256];
	char string_2[256];
	char string_3[256];
	const char ch = '\n';
	const int len = 41, strings = 3;
	char mass[strings][len];

	ifstream fs("strings.txt");//Чтение из файла

	if (!fs) return 1; //Если ошибка открытия файла, то завершаем программу

	for (int r = 0; r < 3; r++)
	{
		fs.getline(mass[r], len - 1, ch); //Считываем строки в массив
	}
	int word_count = 0;//считает сколько слов, нужной нам длины(1)
	strcpy_s(string_1, mass[0]);
	cout << string_1 << endl;
	const char* str1 = string_1;
	while (int len = next_word_length(str1)) {
		if (len == 1) {
			++word_count;
		}
	}
	strcpy_s(string_2, mass[1]);
	cout << string_2 << endl;
	const char* str2 = string_2;
	while (int len = next_word_length(str2)) {
		if (len == 1) {
			++word_count;
		}
	}
	strcpy_s(string_3, mass[2]);
	cout << string_3 << endl;
	const char* str3 = string_3;
	while (int len = next_word_length(str3)) {
		if (len == 1) {
			++word_count;
		}
	}
	std::cout << "Words with length = 1 : " << word_count << '\n';
	fs.close(); //Закрываем файл
	return 0;
}

int next_word_length(const char*& str) {
	// пропускаем пробелы и пунктуацию
	while (*str != '\0' && !std::isalpha(*str)) ++str;

	// проверяем что строка не закончилась
	if (*str == '\0') return 0;

	int len = 0; // вычисляем длину слова
	while (std::isalpha(*str)) {
		++len;
		++str;
	}
	return len;
}