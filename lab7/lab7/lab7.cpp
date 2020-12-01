#include "table.h"
#include "comptable.h"
#include "roundtable.h"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

const double get_table_cost(Table* table)
{
    return table->calc_volume() * 15;
    //15 - стоимость единицы объёма
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "ЧАСТЬ 1\n\n";

    char brown[] = "коричневый";
    Table* table = new Table(10, brown);
    table->show();
    table->calc_volume();

    delete table;
    table = nullptr;

    std::cout << std::endl;

    char white[] = "белый";
    char DSP[] = "ДСП";
    CompTable* ctable = new CompTable(10, white, 2, DSP);
    ctable->show();
    ctable->calc_volume_ct();

    delete ctable;
    ctable = nullptr;

    std::cout << std::endl;

    char black[] = "коричневый";
    RoundTable* rtable = new RoundTable(12, black, 10);
    rtable->show();
    rtable->calc_volume_rt();

    delete rtable;
    rtable = nullptr;

    std::cout << std::endl << "ЧАСТЬ 2\n\n";

    Table* random_table;

    std::cout
        << "Выберите стол:"
        << "\n1. Обычный стол"
        << "\n2. Компьютерный стол"
        << "\n3. Круглый стол"
        << "\nВыбор: ";

    int choice = 0;
    std::cin >> choice;

    char wood[] = "дерево";
    if (choice == 1) {
        std::cout << '\n';
        random_table = new Table(10, brown);
    }
    else if (choice == 2) {
        std::cout << '\n';
        random_table = new CompTable(10, white, 10, wood);
    }
    else if (choice == 3) {
        std::cout << '\n';
        random_table = new RoundTable(10, black, 15.5);
    }
    else {
        return 0;
    }

    random_table->show();

    std::cout << "\nЦена стола: " << get_table_cost(random_table) << std::endl;

    delete random_table;
    random_table = nullptr;

    return 0;
}

