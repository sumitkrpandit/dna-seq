#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <iostream>
#include <string>


struct Config
{
    Config(int k, std::string seq) : k(k), dna(seq), n(dna.size()) {};
    const std::string dna;
    const int k;
    const int n;
};


Config readConfigFromUser(bool ignoreCase=true);


#endif // CONFIG_HPP
