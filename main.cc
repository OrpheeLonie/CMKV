#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "board.hh"
#include "solver.hh"

int main()
{
    std::srand(std::time(nullptr));

    tetravex::Board *board = new tetravex::Board("data/input/s2-02.txt");
    board->random_swap();

    std::cout << "Board:\n";
    board->pretty_print(std::cout);

    std::cout << "\nBoard: " << board->cost() << "\n";
    delete board;

    tetravex::Solver *solver = new tetravex::Solver("data/input/s2-02.txt");
    std::cout << "Solver's board:\n" << *(solver->board) << "\n";
    solver->board->pretty_print(std::cout);

    solver->no_probleme();
    solver->board->pretty_print(std::cout);

    delete solver;

    return 0;
}
