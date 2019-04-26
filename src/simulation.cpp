#include "simulation.hpp"
#include "config.hpp"


std::vector<std::string> buildCompleteSpectrum(const Config& config)
{
    return buildCompleteSpectrum(config.dna, config.k);
}


std::vector<std::string> buildCompleteSpectrum(const std::string& dna, int k)
{
    std::vector<std::string> spectrum;
    for (int pos=0; pos<dna.size() - k + 1; ++pos) {
        spectrum.push_back(dna.substr(pos, k));
    }
    return spectrum;
}


void injectPositiveError(std::vector<std::string>& spectrum)
{
}


void injectNegativeError(std::vector<std::string>& spectrum)
{
}

