#ifndef SIMULATION_HPP
#define SIMULATION_HPP


#include <vector>
#include <string>


class Config;


std::vector<std::string> buildCompleteSpectrum(const Config& config);
std::vector<std::string> buildCompleteSpectrum(const std::string& dna, int k);
void injectPositiveError(std::vector<std::string>& spectrum);
void injectNegativeError(std::vector<std::string>& spectrum);


#endif // SIMULATION_HPP
