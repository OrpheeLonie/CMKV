#include "solver.hh"

#include <cstdlib>
#include <random>

namespace tetravex
{
    Solver::Solver(Board *b)
        : board{b}
    {}

    Solver::Solver(std::string filename)
        : board{new Board(filename)}
    {}

    Solver::~Solver()
    {
        delete board;
    }

    Board *Solver::no_probleme()
    {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> clock{0, double(board->size)};

        double last_cost = board->cost();
        double new_cost;
        while(last_cost != 0)
        {
            int nb_swap = round(1 + std::abs(clock(gen)));

            auto next = board->next_board(nb_swap);

            new_cost = next->cost();
            double alpha = new_cost / last_cost;

            double u = std::rand() / RAND_MAX;

            if (u <= alpha)
            {
                delete board;
                board = next;
                last_cost = new_cost;
            }
        }

        return board;
    }
}
