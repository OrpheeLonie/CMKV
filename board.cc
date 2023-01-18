#include "board.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

namespace tetravex
{
    Board::Board()
        : size{0}
        , tuiles{}
    {}

    Board::Board(std::string filename)
    {
        std::string line;
        std::ifstream file(filename);
        if (file.is_open())
        {
            this->size = 0;
            while (getline(file, line))
            {
                Tuile tuile(line);
                this->tuiles.push_back(tuile);
                size++;
            }
            this->size = std::sqrt(size);
        }
    }

    std::ostream &operator<<(std::ostream &ostr, Board b)
    {
        for (Tuile t : b.tuiles)
        {
            ostr << t << '\n';
        }
        return ostr;
    }

    Board *Board::copy()
    {
        return new Board();
    }

    Board *Board::next_board(size_t nb_swap)
    {
        nb_swap = nb_swap;
        return new Board();
    }

    void Board::swap(size_t i1, size_t i2)
    {
        i1 = i1;
        i2 = i2;
    }

    int Board::cost()
    {
        return 0;
    }
}
