#include "solver.hh"

#include <cstdlib>
#include <random>
#include <cmath>
#include <algorithm>

//#define DEBUG

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
        std::normal_distribution<> clock{0, 2};

        double last_cost = board->cost();
        double new_cost;
        double T = 350; // board->size * 111;
        const double min_t = 0.45; //1 - board->size / 10;
        const double coef_t = 0.99;

#ifdef DEBUG
        int i = 0;
#endif

        while(last_cost != 0)
        {
            // int nb_swap = round(1 + std::abs(clock(gen)));
            int nb_swap = 1;
            auto move = board->nb_random_swap(nb_swap);
            // auto move = board->random_swap();

            new_cost = board->cost();
            // double alpha = new_cost / last_cost;


#ifdef DEBUG
            i++;
            if (i%10000 == 0)
                std::cout << i << ": " << last_cost << "\n";
#endif

            //if (u <= alpha)
            if (new_cost < last_cost ||
                    std::exp((last_cost - new_cost)/T) > (double(std::rand()) / RAND_MAX))
            {
                T *= coef_t;
                T = std::max(T, min_t);

                last_cost = new_cost;
            }
            else
            {
                board->rollback_nb_swap(move);
                //board->rollback_swap(move);
            }
        }

        return board;
    }
}
