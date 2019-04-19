#include <iostream>
#include <algorithm>

#include "levensthein.hpp"
#include "simulation.hpp"
#include "utils.hpp"
#include "config.hpp"
#include "genetic.hpp"


using namespace std;


int main(int argc, char* argv[])
{
    auto config = readConfigFromUser();
    auto spectrum = buildCompleteSpectrum(config);
  
    printf("REFERENCE: %s (%d)\n", config.dna.c_str(), config.n); 

    cout << "SPECTRUM { ";
    for (const auto& oligo: spectrum) {
        cout << oligo << " ";
    }
    cout << "}\n\n";

    auto solutions = reconstructDna(spectrum, config.dna.substr(0, config.k), config);

    cout << "SOLUTIONS\n";
    int counter = 0;
    for (const auto& dna: solutions) {
        double similarity = compareDna(config.dna, dna);
        printf("[ %d ][ %lf%% ] %s\n", counter++, similarity, dna.c_str());
    }
    cout << "\n\n";

    return 0;
}

