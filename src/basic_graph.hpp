#ifndef BASIC_GRAPH_HPP
#define BASIC_GRAPH_HPP

#include <vector>
#include <string>
#include <set>


class Config;


std::vector<std::vector<int>> buildGraph(const std::vector<std::string>& spectrum);
std::set<std::string> reconstructDna(const std::vector<std::string>& spectrum, const std::string& first, const Config& config);


#endif // BASIC_GRAPH_HPP

