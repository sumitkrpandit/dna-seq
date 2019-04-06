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


Config readConfigFromUser(bool ignoreCase=true)
{
    int k;
    std::string seq;
    std::cin >> k >> seq;
    for (int i=0; i<seq.size(); ++i) {
        char c = seq[i];
        if ('a' <= c && c <= 'z') {
            seq[i] = c + 'A' - 'a';
        }
    }
    return Config(k, seq);
}


#endif // CONFIG_HPP
