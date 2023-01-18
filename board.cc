#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

class Tuile
{
    public:
    Tuile(std::string piece)
    {
        for (size_t i = 0; i < 4; i++)
            this->numbers[i] = piece[i] - '0';
        this->is_fixed = piece.length() > 4;
    }

private:
    bool is_fixed;
    std::array<int, 4> numbers;
    int get_top()
    {
        return numbers[0];
    }
    int get_bottom()
    {
        return numbers[3];
    }
    int get_left()
    {
        return numbers[1];
    }
    int get_right()
    {
        return numbers[2];
    }
};

class Board
{
    Board(std::string filename)
    {
        std::string line;
        std::ifstream file(filename);
        if (file.is_open())
        {
            this->size = 0;
            while (getline(file, line))
            {
                Tuile tuile(line);
                this->tuiles.push_back(tuile);
                size++;
            }
            this->size = std::sqrt(size);
        }
    }
    int size; // size * size matrix and number of tuiles
    std::vector<Tuile> tuiles; // all tuiles in the board
};