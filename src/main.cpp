#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

#include "levensthein.hpp"
#include "config.hpp"
#include "simulation.hpp"
#include "utils.hpp"


using namespace std;


string reconstructDna(const set<string>& spectrum, const string& startOligo, const Config& config)
{
    vector<string> nodes;
    copy(spectrum.begin(), spectrum.end(), back_inserter(nodes));

    auto _start = find(nodes.begin(), nodes.end(), startOligo);
    int id = distance(nodes.begin(), _start);

    // compute distances
    vector<vector<int>> distances(nodes.size(), vector<int>(nodes.size(), 0));
    for (int i=0; i<nodes.size(); ++i) {
        distances[i][i] = -1;
        for (int j=0; j<nodes.size(); ++j) {
            if (i == j) continue;
            distances[i][j] = overlap(nodes[i], nodes[j]);
            distances[j][i] = overlap(nodes[j], nodes[i]); 
        }
    }

    // reconstruction
    string dna = nodes[id];
    while (dna.size() < config.n) {
        int bestId = findMax(distances[id]);
        dna += nodes[bestId][config.k-1];
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
    cout << "RECONSTRUCTED DNA [" << dna.size() << "]\n";
    cout << dna << endl << endl;

    cout << "ORIGINAL DNA [" << config.n << "]\n";
    cout << config.dna << endl << endl;

    auto similarity = compareDna(config.dna, dna);
    cout << "SIMILARITY LEVEL: " << similarity << "%\n";

    return 0;
}
