#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>



int findMax(std::vector<int> v) {
    int max = v[0], id=0;
    for (int i=1; i<v.size(); ++i) {
        if (v[i] > max) {
            max = v[i];
            id = i;
        }
    }
    return id;
}


int overlap(std::string a, std::string b)
{
    for (int i=a.size()-1; i>0; --i) {
        if (a.substr(a.size() - i, i) == b.substr(0, i)) {
            return i;
        }
    }
    return 0;
}


#endif // UTILS_HPP
