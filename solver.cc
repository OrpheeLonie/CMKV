#include "solver.hh"

#include <cstdlib>
#include <random>
#include <cmath>
#include <algorithm>

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

    Board *Solver::no_probleme(double T, double degradation, double minT)
    {

        double last_cost = board->cost();
        double new_cost;

        while(last_cost != 0)
        {
            auto move = board->random_swap();

            new_cost = board->cost();
            if (new_cost < last_cost ||
                    std::exp((last_cost - new_cost)/T) > (double(std::rand()) / RAND_MAX))
            {
                T *= degradation;
                T = std::max(T, minT);

                last_cost = new_cost;
            }
            else
            {
                board->rollback_swap(move);
            }
        }

        return board;
    }
}
