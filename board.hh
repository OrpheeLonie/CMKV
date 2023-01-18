#pragma once

#include <vector>

#include "tuile.hh"

namespace tetravex
{
    class Board
    {
    public:
        Board(std::string filename);

    private:
        int size; // size * size matrix and number of tuiles
        std::vector<Tuile> tuiles; // all tuiles in the board
    };
}
