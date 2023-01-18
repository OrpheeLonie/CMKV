#include "solver.hh"

#include <cstdlib>
#include <random>
#include <cmath>

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
            // int nb_swap = round(1 + std::abs(clock(gen)));
            int nb_swap = 1;

            auto next = board->next_board(nb_swap);

            new_cost = next->cost();
            // double alpha = new_cost / last_cost;


            if (new_cost < last_cost)
            {
                delete board;
                board = next;
                last_cost = new_cost;

                continue;
            }

            double u = double(std::rand()) / RAND_MAX;
            double ratio = std::exp(last_cost - new_cost);

            //if (u <= alpha)
            if (ratio > u)
            {
                delete board;
                board = next;
                last_cost = new_cost;
            }
        }

        return board;
    }
}
