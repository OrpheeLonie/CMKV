#pragma once

#include <array>

namespace tetravex
{
    class Tuile
    {
    public:
        Tuile(std::string piece);

    private:
        bool is_fixed;
        std::array<int, 4> numbers;

        int get_top();
        int get_bottom();
        int get_left();
        int get_right();
    };
}
