#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>


//template<typename T>
//int findMax(std::vector<T> v);
template<typename T>
int findMax(std::vector<T> v) {
    T max = v[0], id=0;
    for (int i=1; i<v.size(); ++i) {
        if (v[i] > max) {
            max = v[i];
            id = i;
        }
    }
    return id;
}


int overlap(std::string a, std::string b);
std::vector<double> normalize(const std::vector<double>& v);


#endif // UTILS_HPP
