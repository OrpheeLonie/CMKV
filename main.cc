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
    tetravex::Board *next = board->next_board(1);

    std::cout << "Board:\n";
    board->pretty_print(std::cout);
    std::cout << "Next board:\n";
    next->pretty_print(std::cout);

    std::cout << "\nBoard: " << board->cost() << "\nNext board: " << next->cost() << "\n";
    delete board;
    delete next;

    tetravex::Solver *solver = new tetravex::Solver("data/input/s2-02.txt");

    solver->no_probleme()->pretty_print(std::cout);

    delete solver;

    return 0;
}
