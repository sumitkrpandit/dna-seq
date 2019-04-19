#include "config.hpp"


Config readConfigFromUser(bool ignoreCase)
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

