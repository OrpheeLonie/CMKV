#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <chrono>

#include "board.hh"
#include "solver.hh"

int main()
{
    std::srand(std::time(nullptr));

    // tetravex::Board *board = new tetravex::Board("data/input/s2-02.txt");
    // board->random_swap();

    // std::cout << "Board:\n";
    // board->pretty_print(std::cout);

    // std::cout << "\nBoard: " << board->cost() << "\n";
    // delete board;

    // tetravex::Solver *solver = new tetravex::Solver("data/input/s4-02.txt");
    // std::cout << "Solver's board:\n" << solver->board << "\n";
    // // solver->board->pretty_print(std::cout);

    // solver->no_probleme();
    // // solver->board->pretty_print(std::cout);

    // delete solver;
    
    // best for 4x4: 375, 0.995, 0.45
    // best for 5x5: 475, 0.99, 0.4 pas vraiment tester mais osef
    // best for 6x6: 575, 0.9875, 0.375 => <30s atteint avec pur board sans case fixe

    double temperatures[] = {1};
    double degradation_rates[] = {.99};
    double min_temperatures[] = {.375};

    // make a vector of string containing the addresses of the files
    std::vector<std::string> paths;
    for (int i = 1; i < 10; i++){
        std::ostringstream ss;
        ss << i;
        paths.push_back("data/input/s6-0" + ss.str() + ".txt");
    }

    

    std::chrono::duration<double> best_time = std::chrono::duration<double>::max();
    double best_temperature;
    double best_degradation_rate;
    double best_min_temperature;
    int len_temperatures = sizeof(temperatures)/sizeof(temperatures[0]);
    int len_degradation_rates = sizeof(degradation_rates)/sizeof(degradation_rates[0]);
    int len_min_temperatures = sizeof(min_temperatures)/sizeof(min_temperatures[0]);

    for (int j = 0; j < len_temperatures; j++) {
        for (int k = 0; k < len_degradation_rates; k++) {
            for (int l = 0; l < len_min_temperatures; l++) {
                double t = temperatures[j];
                double d = degradation_rates[k];
                double m = min_temperatures[l];

                for (auto h = 0; h < 20 && best_time.count() > 30; h++){
                    auto start = std::chrono::system_clock::now();
                    for (int i = 0; i < 10; i++) {
                        tetravex::Solver *solver = new tetravex::Solver(paths[1]);
                        // std::cout << "Solver's board "<< i << " started!\n";
                        // solver->board->pretty_print(std::cout);

                        solver->no_probleme(t, d, m);
                        // solver->board->pretty_print(std::cout);

                        delete solver;
                    }
                    auto end =  std::chrono::system_clock::now();
                    std::chrono::duration<double> elapsed_seconds = end-start;

                    if (elapsed_seconds < best_time) {
                        best_time = elapsed_seconds;
                        best_temperature = t;
                        best_degradation_rate = d;
                        best_min_temperature = m;
                    }
                    std::cout << "Time for temperature " << t << ", degradation rate " << d << ", and minimum temperature " << m << ": " << elapsed_seconds.count() << "\n";

                }
            }
        }
    } 

    std::cout << "Best time: " << best_time.count() << "\n";
    std::cout << "Best temperature: " << best_temperature << "\n";
    std::cout << "Best degradation rate: " << best_degradation_rate << "\n";
    std::cout << "Best minimum temperature: " << best_min_temperature << "\n";

    // for (int i = 0; i < 10; i++) {
    //     tetravex::Solver *solver = new tetravex::Solver("data/input/s4-02.txt");
    //     std::cout << "Solver's board "<< i << " done!\n";
    //     // solver->board->pretty_print(std::cout);

    //     solver->no_probleme(600, 0.9, 0.5);
    //     // solver->board->pretty_print(std::cout);

    //     delete solver;
    // }

    return 0;
}
