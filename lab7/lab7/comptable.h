#ifndef COMPTABLE_H
#define COMPTABLE_H

#include "table.h"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

class CompTable : public Table {
public:
    CompTable()
        : Table()
    {
        
        m_h = new int;
        m_material = new char[20];
    }

    CompTable(int t_size, char* t_color, int t_h, char* t_material)
        : Table(t_size, t_color)
    {
        
        if (t_h > 0) {
            m_h = new int;
            *m_h = t_h;
        }
        else {
            std::cerr
                << "� ����. ����� ������ ������ ����, �������: "
                << t_h
                << ". �����."
                << std::endl;

            std::exit(1);
        }

        m_material = new char[20];
        strcpy_s(m_material,strlen(t_material)+1, t_material);
    }

    ~CompTable()
    {
        
        delete m_h;
        delete[] m_material;
    }

    virtual int calc_volume() override
    {
        return Table::calc_volume() + std::pow(*m_h, 3);
    }

    int calc_volume_ct()
    {
        return Table::calc_volume() + std::pow(*m_h, 3);
    }

    virtual void show() override
    {
        std::cout
            << "������������ ����:"
            << "\n\t������: " << *m_h
            << "\n\t��������: " << m_material
            << std::endl;
    }

private:
    int* m_h;
    char* m_material;
};

#endif

