#ifndef ROUNDTABLE_H
#define ROUNDTABLE_H

#include "table.h"

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

class RoundTable : public Table {
public:
    RoundTable()
        : Table()
    {
        
        m_radius = 1.0;
    }

    RoundTable(int t_size, char* t_color, double t_radius)
        : Table(t_size, t_color)
    {
        
        if (t_radius > 0.0) {
            m_radius = t_radius;
        }
        else {
            std::cerr
                << "Радиус круглого стола должен быть больше нуля, введено: "
                << t_radius
                << std::endl;

            std::exit(1);
        }
    }

    int calc_volume_rt()
    {
        return calc_volume() + 3.14 * std::pow(m_radius, 2);
    }

    virtual int calc_volume() override
    {
        return Table::calc_volume() + 3.14 * std::pow(m_radius, 2);
    }

    virtual void show() override
    {
        std::cout
            << "Круглый стол:"
            << "\n\tрадиус: " << m_radius
            << std::endl;
    }

private:
    double m_radius;
};

#endif