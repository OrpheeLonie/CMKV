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

    Board::Board(size_t size, std::vector<Tuile *> tuiles)
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
                Tuile *tuile = new Tuile(line);
                this->tuiles.push_back(tuile);
                size++;
            }
            this->size = std::sqrt(size);
        }
    }

    Board::~Board()
    {
        for (auto v : tuiles)
        {
            delete v;
        }
    }

    std::ostream &operator<<(std::ostream &ostr, Board *b)
    {
        for (Tuile *t : b->tuiles)
        {
            ostr << *t << '\n';
        }
        return ostr;
    }

    void Board::pretty_print(std::ostream &ostr)
    {
        std::string interline = "+";
        for (size_t i = 0; i < size; i++)
            interline += "-----+";
        interline += '\n';

        ostr << interline;

        for (size_t i = 0; i < size; i++)
        {
            ostr << "|";
            for (size_t j = 0; j < size; j++)
            {
                if (tuiles[i * size + j]->is_fixed)
                    ostr << "\033[42;30m";
                ostr << "  " << tuiles[i * size + j]->get_top() << "  \033[0m|";
            }
            ostr << "\n";

            ostr << "|";
            for (size_t j = 0; j < size; j++)
            {
                if (tuiles[i * size + j]->is_fixed)
                    ostr << "\033[42;30m";
                ostr << " " << tuiles[i * size + j]->get_left() << " "
                     << tuiles[i * size + j]->get_right() << " \033[0m|";
            }
            ostr << "\n";

            ostr << "|";
            for (size_t j = 0; j < size; j++)
            {
                if (tuiles[i * size + j]->is_fixed)
                    ostr << "\033[42;30m";
                ostr << "  " << tuiles[i * size + j]->get_bottom() << "  \033[0m|";
            }
            ostr << "\n";

            ostr << interline;
        }
    }

    void Board::swap(size_t i1, size_t i2)
    {
        Tuile *tmp = this->tuiles[i1];
        tuiles[i1] = tuiles[i2];
        tuiles[i2] = tmp;
    }

    std::tuple<size_t, size_t> Board::random_swap()
    {
        size_t len = this->size * this->size;

        int i1 = 0, i2 = 0;
        do
        {
            i1 = std::rand() % len;
            i2 = std::rand() % len;
        } while(i1 == i2 || tuiles[i1]->is_fixed || tuiles[i2]->is_fixed);

        swap(i1, i2);

        return std::tuple<size_t, size_t>{i1, i2};
    }

    void Board::rollback_swap(std::tuple<size_t, size_t> move)
    {
        swap(std::get<0>(move), std::get<1>(move));
    }

    std::vector<std::tuple<size_t, size_t>> Board::nb_random_swap(size_t nb_swap)
    {
        std::vector<std::tuple<size_t, size_t>> output;

        for (size_t i = 0; i < nb_swap; i++)
            output.push_back(random_swap());

        return output;
    }

    void Board::rollback_nb_swap(std::vector<std::tuple<size_t, size_t>> moves)
    {
        for (int i = moves.size() - 1; i >= 0; i--)
            rollback_swap(moves[i]);
    }

    int Board::cost()
    {
        int total_cost = 0;

        for (size_t i = 0; i < this->tuiles.size() - 1; i++)
        {
            if ((i+1) % size != 0 && tuiles[i]->get_right() != tuiles[i+1]->get_left())
                total_cost++;

            if (i + size < tuiles.size() && tuiles[i]->get_bottom() != tuiles[i + size]->get_top())
                total_cost++;
        }

        return total_cost;
    }

    void Board::save_board(std::string filename)
    {
        std::ofstream file;
        file.open(filename);
        file << this;
        file.close();
    }
}
