#include <iostream>
#include <vector>
#include <string>
#include <set>


using namespace std;


struct Config
{
    Config() :
        k(3), 
        dna("ACGTATAAAGGCTAGTTTATTACCCCGGGT"),
        n(dna.size())
    {
    }

    const string dna;
    const int k;
    const int n;
};


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


string reconstructDna(const set<string>& spectrum, const Config& config)
{
    string dna;
    return dna;
}


double compareDna(const string& dna1, string& dna2)
{
    if (dna1 == dna2) {
        return 1.0;
    }
    return 0.0;
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

    string dna = reconstructDna(spectrum, config);
    cout << "RECONSTRUCTED DNA:\n";
    cout << dna << endl << endl;

    double similarity = compareDna(config.dna, dna);
    cout << "SIMILARITY LEVEL: " << similarity << endl;
    return 0;
}
