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
        double T = board->size * board->size * 2;
        //int i = 0;

        while(last_cost != 0)
        {
            // int nb_swap = round(1 + std::abs(clock(gen)));
            int nb_swap = 1;

            auto next = board->next_board(nb_swap);

            new_cost = next->cost();
            // double alpha = new_cost / last_cost;


            /*
            i++;
            std::cout << i << ": " << last_cost << "\n";
            */

            //if (u <= alpha)
            if (new_cost < last_cost ||
                    std::exp((last_cost - new_cost)/T) > (double(std::rand()) / RAND_MAX))
            {
                T *= 0.999;

                delete board;
                board = next;
                last_cost = new_cost;
            }
            else
            {
                delete next;
                T /= 0.999;
            }
        }

        return board;
    }
}
