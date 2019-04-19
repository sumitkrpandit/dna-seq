#include "utils.hpp"
#include <iostream>




int overlap(std::string a, std::string b)
{
    for (int i=a.size()-1; i>0; --i) {
        if (a.substr(a.size() - i, i) == b.substr(0, i)) {
            return i;
        }
    }
    return 0;
}


std::vector<double> normalize(const std::vector<double>& v)
{
    std::cout << "normalize() operation not implemented.\n";
    return v;
}

