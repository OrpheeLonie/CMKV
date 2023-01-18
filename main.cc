#include <iostream>
#include <iostream>

#include "board.hh"

int main()
{
    tetravex::Board board("data/input/s2-02.txt");

    std::cout << "Board loaded:\n" << board;
    return 0;
}
