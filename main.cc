#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <chrono>

#include "board.hh"
#include "solver.hh"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Wrong number of arguments, usage:\n" << argv[0] << " input_file output_file\n";
        exit(0);
    }

    std::string input_file = argv[1];
    std::string output_file = argv[2];

    std::srand(std::time(nullptr));

    tetravex::Solver *solver = new tetravex::Solver(input_file);
    double t, d, m;
    if (solver->board->size < 6)
    {
        t = 375;
        d = 0.995;
        m = 0.45;
    }
    else
    {
        t = 575;
        d = 0.9875;
        m = 0.375;
    }
    solver->no_probleme(t, d, m);
    solver->board->save_board(output_file);

    delete solver;

    return 0;
}
