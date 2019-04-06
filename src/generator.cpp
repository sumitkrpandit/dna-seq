#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>


using namespace std;


char randomNucleotide()
{
    static random_device r;
    static default_random_engine engine(r());
    static uniform_int_distribution<int> uniform_dist(0, 3);
    static const char _nucleotides[] = "CAGT";

    int x = uniform_dist(engine);
    return _nucleotides[x];
}


int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Invalid number of arguments." << endl;
        return 0;
    }

    srand(time(nullptr));

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    
    string dna = "";

    for (int i=0; i<n; ++i) {
       dna += randomNucleotide();
    }

    cout << k << endl;
    cout << dna << endl;

    return 0;
}
