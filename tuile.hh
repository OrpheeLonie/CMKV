#pragma once

#include <array>
#include <iostream>

namespace tetravex
{
    class Tuile
    {
    public:
        bool is_fixed;

        Tuile(std::string piece);
        friend std::ostream &operator<<(std::ostream &ostr, Tuile t);

        int get_top();
        int get_bottom();
        int get_left();
        int get_right();

    private:
        std::array<int, 4> numbers;
    };
}
