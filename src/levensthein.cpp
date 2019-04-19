#include <vector>
#include "levensthein.hpp"


#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)


int compute(std::string a, std::string b)
{
    std::vector<std::vector<int>> d(a.size() + 1, std::vector<int>(b.size()+1));
    
    for (int i=0; i<=a.size(); ++i) { d[i][0] = i; }
    for (int i=0; i<=b.size(); ++i) { d[0][i] = i; }
    for (int i=1; i<=a.size(); ++i) {
        for (int j=1; j<=b.size(); ++j) {
            if (a[i-1] == b[j-1]) {
                d[i][j] = d[i-1][j-1];
            }
            else {
                d[i][j] = min(
                    d[i-1][j] + 1,
                    min(d[i][j-1] + 1, d[i-1][j-1] + 1)
                );
            }
        }
    }

    return d[a.size()][b.size()];
}


double compareDna(const std::string& dna1, const std::string& dna2)
{
    double measure = 1.0 - double(compute(dna1, dna2)) / double(dna1.size());
    return measure * 100.0;
}

