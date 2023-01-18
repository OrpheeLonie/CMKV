#pragma once

#include <vector>
#include <iostream>

#include "tuile.hh"

namespace tetravex
{
    class Board
    {
    public:
        Board(std::string filename);
        friend std::ostream &operator<<(std::ostream &ostr, Board b);

    private:
        int size; // size * size matrix and number of tuiles
        std::vector<Tuile> tuiles; // all tuiles in the board
    };
}
