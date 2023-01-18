#include "board.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

namespace tetravex
{
    Tuile::Tuile(std::string piece)
    {
        for (size_t i = 0; i < 4; i++)
            this->numbers[i] = piece[i] - '0';
        this->is_fixed = piece.length() > 4;
    }

    int Tuile::get_top()
    {
        return numbers[0];
    }
    int Tuile::get_bottom()
    {
        return numbers[3];
    }
    int Tuile::get_left()
    {
        return numbers[1];
    }
    int Tuile::get_right()
    {
        return numbers[2];
    }


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
}
