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
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> clock{0, double(board->size)};

        double last_cost = board->cost();
        double new_cost;
        // double T = board->size * 111;
        // double min_t = 0.4; 
        //1 - board->size / 10;
        //int i = 0;

        while(last_cost != 0)
        {
            // int nb_swap = round(1 + std::abs(clock(gen)));
            auto move = board->random_swap();

            new_cost = board->cost();
            // double alpha = new_cost / last_cost;


            // i++;
            // if (i%10000 == 0)
            //     std::cout << i << ": " << last_cost << "\n";

            //if (u <= alpha)
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
