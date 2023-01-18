#include "board.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

namespace tetravex
{
    Board::Board()
        : size{0}
        , tuiles{}
    {}

    Board::Board(size_t size, std::vector<Tuile> tuiles)
        : size{size}
        , tuiles{tuiles}
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
        return new Board(this->size, this->tuiles);
    }

    Board *Board::next_board(size_t nb_swap)
    {
        Board *next_b = this->copy();
        size_t len = this->size * this->size;

        for (size_t i = 0; i < nb_swap; i++)
        {
            int i1 = 0, i2 = 0;
            do
            {
                i1 = rand() % len;
                i2 = rand() % len;
            } while(i1 == i2);

            next_b->swap(i1, i2);
        }
        return next_b;
    }

    void Board::swap(size_t i1, size_t i2)
    {
        Tuile tmp = this->tuiles[i1];
        tuiles[i1] = tuiles[i2];
        tuiles[i2] = tmp;
    }

    int Board::cost()
    {
        return 0;
    }
}
