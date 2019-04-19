#ifndef GENETIC_HPP
#define GENETIC_HPP

#include <set>
#include <string>
#include <vector>


class Config;


std::set<std::string> reconstructDna(
    const std::vector<std::string>& spectrum,
    const std::string& start,
    const Config& config);


#endif // GENETIC_HPP
