#pragma once

#include <vector>
#include <iostream>

#include "tuile.hh"

namespace tetravex
{
    class Board
    {
    public:
        Board();
        Board(std::string filename);
        friend std::ostream &operator<<(std::ostream &ostr, Board b);

        // Give a copy of the board
        Board *copy();
        // Create the next board, given a number of swap
        Board *next_board(size_t nb_swap);
        // Swap the tiles at index i1 and i2
        void swap(size_t i1, size_t i2);

        // Give the number of error
        int cost();

    private:
        int size; // size * size matrix and number of tuiles
        std::vector<Tuile> tuiles; // all tuiles in the board
    };
}
