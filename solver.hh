#pragma once

#include "board.hh"

namespace tetravex
{
    class Solver
    {
    public:
        Board *board;

        Solver(Board *b);
        Solver(std::string filename);
        ~Solver();

        Board *no_probleme(double T, double degradation, double minT);

    private:
    };
}
