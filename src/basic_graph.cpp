#include "basic_graph.hpp"
#include "config.hpp"
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

