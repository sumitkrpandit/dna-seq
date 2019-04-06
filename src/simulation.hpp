#ifndef SIMULATION_HPP
#define SIMULATION_HPP


#include <set>
#include <string>
#include "config.hpp"


std::set<std::string> buildCompleteSpectrum(const Config& config)
{
    std::set<std::string> spectrum;
    for (int pos=0; pos<config.n - config.k + 1; ++pos) {
        spectrum.insert(config.dna.substr(pos, config.k));
    }
    return spectrum;
}


void injectPositiveError(std::set<std::string>& spectrum)
{
}


void injectNegativeError(std::set<std::string>& spectrum)
{
}


#endif // SIMULATION_HPP
