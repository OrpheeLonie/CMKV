#include "board.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

namespace tetravex
{
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
}
