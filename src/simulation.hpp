#ifndef SIMULATION_HPP
#define SIMULATION_HPP


#include <vector>
#include <string>
#include "config.hpp"


std::vector<std::string> buildCompleteSpectrum(const Config& config)
{
    std::vector<std::string> spectrum;
    for (int pos=0; pos<config.n - config.k + 1; ++pos) {
        spectrum.push_back(config.dna.substr(pos, config.k));
    }
    return spectrum;
}


void injectPositiveError(std::vector<std::string>& spectrum)
{
}


void injectNegativeError(std::vector<std::string>& spectrum)
{
}


#endif // SIMULATION_HPP
