#pragma once

#include <vector>
#include <iostream>
#include <tuple>

#include "tuile.hh"

namespace tetravex
{
    class Board
    {
    public:
        size_t size; // size * size matrix and number of tuiles

        Board();
        Board(size_t size, std::vector<Tuile *> tuiles);
        Board(std::string filename);
        ~Board();
        friend std::ostream &operator<<(std::ostream &ostr, Board *b);

        void pretty_print(std::ostream &ostr);

        // Swap the tiles at index i1 and i2
        void swap(size_t i1, size_t i2);
        std::tuple<size_t, size_t> random_swap();
        void rollback_swap(std::tuple<size_t, size_t> move);

        // Give the number of error
        int cost();

    private:
        std::vector<Tuile *> tuiles; // all tuiles in the board
    };
}
