#include <iostream>
#include <fstream>

using namespace std;

int scheme_count = 0;

//Создаем чистое поле
bool** CreateField() {
    bool** field = new bool* [8];
    for (int i = 0; i < 8; i++) {
        field[i] = new bool[8];
        for (int j = 0; j < 8; j++)
            field[i][j] = false;
    }

    return field;
}

//Печать в файл
void Print(bool** field) {
    ofstream file;
    file.open("Chess.txt", ios::app);
    file << "Scheme " << scheme_count << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            file << field[i][j] << " ";
        file << endl;
    }
    file.close();
}

//Копируем поле
bool** Copy(bool** source) {
    bool** copy = CreateField();
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            copy[i][j] = source[i][j];
    return copy;
}

//Проверка возможности поставить фигуру
bool IsPossible(bool** field, int row, int col) {
    if (field[row][col])
        return false;

    //проверяем вертикаль
    for (int i = 0; i < row; i++)
        if (field[i][col])
            return false;
    //проверяем горизонталь
    for (int j = 0; j < col; j++)
        if (field[row][j])
            return false;
    //проверяем главную диагональ
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (field[i][j])
            return false;
    }
    //проверяем второстепенную диагональ
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
        if (field[i][j])
            return false;
    }
    return true;
}

//Чистим память
void Erase(bool** field) {
    for (int i = 0; i < 8; i++)
        delete[] field[i];
    delete[] field;
}

void Chess(int n, int row = 0, int col = 0, bool** field = nullptr) {
    if (field == nullptr) {
        field = CreateField();
    }
    if (n <= 0) {
        scheme_count++;
        Print(field);
        Erase(field);
        return;
    }
    for (int i = row; i < 8; i++) {
        for (int j = col; j < 8; j++) {
            bool result = IsPossible(field, i, j);
            if (result) {
                bool** copy = Copy(field);
                copy[i][j] = true;
                if (n == 5)
                    n = 5;
                Chess(n - 1, i, j, copy);
            }
        }
        col = 0;
    }
    Erase(field);
}

int main()
{
    ofstream file;
    file.open("Chess.txt", ios::trunc);
    file.close();
    Chess(8);
    cout << "Scheme number: " << scheme_count << endl;

    system("pause");
    return 0;
}