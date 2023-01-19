#include "tuile.hh"

namespace tetravex
{
    Tuile::Tuile(std::string piece)
    {
        for (size_t i = 0; i < 4; i++)
            this->numbers[i] = piece[i] - '0';

        this->is_fixed = false;
        for (size_t i = 4; i < piece.length(); i++)
            if (piece[i] == '@')
                this->is_fixed = true;
    }

    int Tuile::get_top()
    {
        return this->numbers[0];
    }
    int Tuile::get_bottom()
    {
        return this->numbers[3];
    }
    int Tuile::get_left()
    {
        return this->numbers[1];
    }
    int Tuile::get_right()
    {
        return this->numbers[2];
    }

    std::ostream &operator<<(std::ostream &ostr, Tuile t)
    {
        ostr << t.get_top() << t.get_left() << t.get_right() << t.get_bottom();

        return ostr;
    }
}
