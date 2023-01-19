#include <iostream>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "board.hh"
#include "solver.hh"
#include <chrono>

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

    // try different temperatures and degradation rates and see what is the quickest
    // the different temperatures and degradation rates are in two lists below
    // make a list of double for the temperatures and a list of double for the degradation rates
    
    double temperatures[] = {325, 350, 375};
    double degradation_rates[] = {0.99, 0.995, 0.985};
    double min_temperatures[] = {0.425, 0.45, 0.475};

    // run the solver 10 times for each temperature and degradation rate

    // make a best time variable and a best temperature and degradation rate variable and update them if the time is better
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


                auto start = std::chrono::system_clock::now();
                for (int i = 0; i < 70; i++) {
                    tetravex::Solver *solver = new tetravex::Solver("data/input/s4-09.txt");
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
