#include <iostream>
#include <algorithm>

#include "levensthein.hpp"
#include "simulation.hpp"
#include "utils.hpp"
#include "config.hpp"
#include "basic_graph.hpp"


using namespace std;


int main(int argc, char* argv[])
{
    auto config = readConfigFromUser();
    auto spectrum = buildCompleteSpectrum(config);
   
    cout << "SPECTRUM -> { ";
    for (const auto& oligo: spectrum) {
        cout << oligo << " ";
    }
    cout << "}\n\n";

    string dna = reconstructDna(spectrum, config.dna.substr(0, config.k), config);
    cout << "RECONSTRUCTED DNA\n";
    cout << dna << "\n\n";

    cout << "ORIGINAL DNA [" << config.n << "]\n";
    cout << config.dna << "\n\n";

    auto similarity = compareDna(config.dna, dna);
    cout << "SIMILARITY LEVEL: " << similarity << "%\n";

    return 0;
}

