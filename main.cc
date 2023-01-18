#include <iostream>
#include <iostream>

#include "board.hh"

int main()
{
    tetravex::Board *board = new tetravex::Board("data/input/s2-02.txt");
    tetravex::Board *next = board->next_board(1);

    std::cout << "Board:\n" << *board << "Next board:\n" << *next;

    std::cout << "\nBoard: " << board->cost() << "\nNext board: " << next->cost() << "\n";
    delete board;
    delete next;

    return 0;
}
