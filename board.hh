#pragma once

#include <array>
#include <vector>

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

    class Board
    {
    public:
        Board(std::string filename);

    private:
        int size; // size * size matrix and number of tuiles
        std::vector<Tuile> tuiles; // all tuiles in the board
    };
}
