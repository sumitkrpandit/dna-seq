#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "levensthein.hpp"
#include "config.hpp"
#include "simulation.hpp"
#include "utils.hpp"


using namespace std;


vector<vector<int>> buildGraph(const vector<string>& spectrum)
{
    vector<vector<int>> distances(spectrum.size(), vector<int>(spectrum.size(), 0));
    for (int i=0; i<spectrum.size(); ++i) {
        distances[i][i] = -1;
        for (int j=0; j<spectrum.size(); ++j) {
            if (i == j) continue;
            distances[i][j] = overlap(spectrum[i], spectrum[j]);
            distances[j][i] = overlap(spectrum[j], spectrum[i]); 
        }
    }
    return distances;
}


string reconstructDna(const vector<string>& spectrum, const string& first, const Config& config)
{
    auto distances = buildGraph(spectrum);

    int id = distance(
        spectrum.begin(), 
        find(spectrum.begin(), spectrum.end(), first)
    );

    string dna = spectrum[id];
    while (dna.size() < config.n) {
        int bestId = findMax(distances[id]);
        dna += spectrum[bestId][config.k-1];
        id = bestId;
    }

    return dna;
}


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
