#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>


using namespace std;


char randomNucleotide()
{
    static const char _nucleotides[] = "CAGT";
    int x = rand() % 4;
    return _nucleotides[x];
}


int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Invalid number of arguments." << endl;
        return 0;
    }

    srand(time(nullptr));

    int n = atoi(argv[1]);
    string dna = "";

    for (int i=0; i<n; ++i) {
       dna += randomNucleotide();
    }

    cout << dna << endl;

    return 0;
}
