#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>


using namespace std;


struct Config
{
    Config() :
        k(3), 
        dna("ACGTATAGGG"),
        n(dna.size())
    {
    }

    const string dna;
    const int k;
    const int n;
};


#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)


int compute(string a, string b)
{
    vector<vector<int>> d(a.size() + 1, vector<int>(b.size()+1));
    
    for (int i=0; i<=a.size(); ++i) { d[i][0] = i; }
    for (int i=0; i<=b.size(); ++i) { d[0][i] = i; }

    for (int i=1; i<=a.size(); ++i) {
        for (int j=1; j<=b.size(); ++j) {
            if (a[i-1] == b[j-1]) {
                d[i][j] = d[i-1][j-1];
            }
            else {
                d[i][j] = min(
                    d[i-1][j] + 1,
                    min(d[i][j-1] + 1, d[i-1][j-1] + 1)
                );
            }
        }
    }

    return d[a.size()][b.size()];
}


set<string> buildCompleteSpectrum(const Config& config)
{
    set<string> spectrum;
    for (int pos=0; pos<config.n - config.k; ++pos) {
        spectrum.insert(config.dna.substr(pos, config.k));
    }
    return spectrum;
}


void injectPositiveError(set<string>& spectrum)
{
}


void injectNegativeError(set<string>& spectrum)
{
}


int _distance(string a, string b)
{
    int dist = 0;
    for (int i=1; i<a.size(); ++i) {
        if (a[i] == b[i-1]) { dist++; }
    }
    return dist;
}


int indexOfMax(vector<int> v) {
    int max = v[0], id=0;
    for (int i=1; i<v.size(); ++i) {
        if (v[i] > max) {
            max = v[i];
            id = i;
        }
    }
    return id;
}


string reconstructDna(const set<string>& spectrum, const string& startOligo, const Config& config)
{
    vector<string> nodes;
    copy(spectrum.begin(), spectrum.end(), back_inserter(nodes));

    auto _start = find(nodes.begin(), nodes.end(), startOligo);
    int id = distance(nodes.begin(), _start);

    // compute distances
    vector<vector<int>> distances(nodes.size(), vector<int>(nodes.size(), 0));
    for (int i=0; i<nodes.size(); ++i) {
        distances[i][i] = -1; // magic dist smaller than any possible dist.
        for (int j=0; j<nodes.size(); ++j) {
            if (i == j) continue;
            distances[i][j] = _distance(nodes[i], nodes[j]);
            distances[j][i] = _distance(nodes[j], nodes[i]); 
        }
    }

    // print distances debug
    /*for (int i=0; i<distances.size(); ++i) {
        for (int j=0; j<distances[i].size(); ++j) {
            cout << distances[i][j] << " ";
        }
        cout << endl;
    }*/

    // reconstruction
    string dna = nodes[id];
    while (dna.size() < config.n) {

        // debug print
        //cout << "node: " << nodes[id] << endl;
        //int x; cin >> x;


        int bestId = indexOfMax(distances[id]);
        dna += nodes[bestId][config.k-1];
        id = bestId;
    }
 
    return dna;
}


int compareDna(const string& dna1, const string& dna2)
{
    return compute(dna1, dna2);
}


int main(int argc, char* argv[])
{
    Config config;

    auto spectrum = buildCompleteSpectrum(config);
    cout << "SPECTRUM -> { ";
    for (const auto& oligo: spectrum) {
        cout << oligo << " ";
    }
    cout << "}\n\n";

    string dna = reconstructDna(spectrum, config.dna.substr(0, config.k), config);
    cout << "RECONSTRUCTED DNA:\n";
    cout << dna << endl << endl;

    int similarity = compareDna(config.dna, dna);
    cout << "SIMILARITY LEVEL: " << similarity << endl;
    return 0;
}
