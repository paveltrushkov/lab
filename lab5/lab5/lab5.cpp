#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct smth {
	float s=0;
	string imya=" ";
	string fam = " ";
	string otch = " ";
	string raion= " ";
	int stoimost = 0;
};

bool cmpByFam(const smth& r1, const smth& r2)
{
	return r1.fam < r2.fam;
}

int main()
{
	setlocale(LC_ALL, "rus");
	string x;
	smth s;
	ifstream file;

	file.open("file.txt");
	int len(0);
	

	if (file.is_open()) {
		while (!file.eof()) {
			string s;
			getline(file, s);
			len++;
		}
	}

	smth* arr = new smth[len];
	file.seekg(0, ios_base::beg);

	for (size_t i = 0; i < len; i++)
	{
		getline(file, x);
		istringstream iss(x);
		iss >> s.s >> s.imya>>s.fam>>s.otch >> s.raion >> s.stoimost;
		arr[i] = s;
	}

	cout << "Информация о всех квартирах: \n" << endl;
	for (size_t n = 0; n < len; n++)
	{
		cout <<"Площадь : " << arr[n].s << " "
			<< "Имя : "<< arr[n].imya << " "
			<< "Фамилия : " << arr[n].fam << " "
			<< "Отчество : " << arr[n].otch << " "
			<< "Район : " << arr[n].raion << " "
			<< "Стоимость : " << arr[n].stoimost << endl;
	}
	cout << "\nИнформация о квартирах, не находящихся в Заводском районе :\n" << endl;
	for (size_t n = 0; n < len; n++)
	{
		if (arr[n].raion != "zavodskiy")
		{
			cout << "Площадь : " << arr[n].s << " "
				<< "Имя : " << arr[n].imya << " "
				<< "Фамилия : " << arr[n].fam << " "
				<< "Отчество : " << arr[n].otch << " "
				<< "Район : " << arr[n].raion << " "
				<< "Стоимость : " << arr[n].stoimost << endl;
		}
	}
	cout << "\nИнформация о квартирах, стоимость менее 1500к, отсортированная по алфавиту:\n" << endl;
	sort(arr, arr + len, cmpByFam);
	for (size_t n = 0; n < len; n++)
	{
		if (arr[n].stoimost < 1500)
		{
			cout << "Площадь : " << arr[n].s << " "
				<< "Имя : " << arr[n].imya << " "
				<< "Фамилия : " << arr[n].fam << " "
				<< "Отчество : " << arr[n].otch << " "
				<< "Район : " << arr[n].raion << " "
				<< "Стоимость : " << arr[n].stoimost << endl;
		}
	}

	file.close();
}