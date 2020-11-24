#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Table {
public:
    Table()
    {
        int* size;
        char* color;
    }

    Table(int size1, char* color1)
    {
        if (size1 > 0) {
            size = new int;
            *size = size1;
        }
        else {
            std::cerr
                << "У стола размер больше нуля, введено: "
                << size1
                << ". Выход."
                << std::endl;
            std::exit(1);
        }

        color = new char[20];
        strcpy_s(color,20, color1);
    }

    Table(int size1)
    {
        if (size1 > 0) {
            size = new int;
            *size = size1;
        }
        else {
            std::cerr
                << "У стола размер больше нуля, введено: "
                << size1
                << ". Выход."
                << std::endl;
            std::exit(1);
        }

        color = new char[10];
    }

    ~Table()
    {
        delete size;
        delete[] color;
    }

    void show()
    {
        std::cout
            << "Table:"
            << "\n\t size: " << *size
            << "\n\t color: " << color
            << std::endl;
    }

    int calc_volume()
    {
        return std::pow(*size, 3);
    }

private:
    int* size;
    char* color;
};


class CompTable : public Table {
public:
    CompTable()
        : Table()
    {
        int* h;
        char* material;
    }

    CompTable(int size1, char* color1, int h1, char* material1)
        : Table(size1, color1)
    {
        if (h1 > 0) {
            h = new int;
            *h = h1;
        }
        else {
            std::cerr
                << "У комп. стола высота больше нуля, введена: " << h1
                << ". Выход."
                << std::endl;

            std::exit(1);
        }

        material = new char[20];
        strcpy_s(material,20, material1);
    }

    ~CompTable()
    {
        delete h;
        delete[] material;
    }

    int calc_volume_ct()
    {
        return calc_volume() + std::pow(*h, 3);
    }

    void show_ct()
    {
        std::cout
            << "CompTable:"
            << "\n\th = " << *h
            << "\n\tmaterial: " << material
            << std::endl;

        show();
    }

private:
    int* h;
    char* material;
}; // class CompTable

int main()
{
    char b[] = "brown";
    Table* t1 = new Table(4, b);
    t1->show();
    std::cout << "Volume of t1: " << t1->calc_volume() << std::endl;

    delete t1;
    t1 = nullptr;

    char w[] = "white"; char wo[] = "wood";
    CompTable* t2 = new CompTable(4, w, 1, wo);
    t2->show();
    std::cout << "\nVolume of t2: " << t2->calc_volume_ct() << std::endl;

    delete t2;
    t2 = nullptr;

    return 0;
}


