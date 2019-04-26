#include "genetic.hpp"
#include "config.hpp"
#include "utils.hpp"
#include "levensthein.hpp"

#include <random>
#include <algorithm>
#include <iostream>


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


string randomSequence(int n)
{
    string sequence = "";
    for (int i=0; i<n; ++i) {
        sequence += randomNucleotide();
    }
    return sequence;
}


// real value from 0 - 100
double fitness(const string& dna, const string& ref)
{
    return compareDna(dna, ref);
}


string cross(string a, string b)
{
    string c = "";
    int k = 7;
    for (int i=0; i<a.size(); i+=k) {
        c += rand()%2 ? a.substr(i, k) : b.substr(i, k);
    }
    return c;
}


void mutate(string& dna, int mutations)
{
    for (int i=0; i<mutations; ++i) {
        int id = rand() % dna.size();
        dna[id] = randomNucleotide();
    }
}


// TODO: select withoutrepetitions
vector<int> lottery_no_rep(const vector<double>& values, int k)
{
    vector<int> winners;
    int i = 0;
    while (winners.size() < k) {
        if (static_cast<double>(rand() % 100) <= values[i]) {
            winners.push_back(i);
            i = (i+1) % values.size();
        }
    }
    return winners;
}


vector<int> lottery(const vector<double>& values, int k)
{
    vector<int> pool;
    for (int i=0; i<values.size(); ++i) {
        int tickets = static_cast<int>(values[i]);
        for (int t=0; t<tickets; ++t) pool.push_back(i);
    }

    vector<pair<int, int>> randomized;
    for (int i=0; i<pool.size(); ++i) {
        randomized.push_back({rand() % pool.size(), pool[i]});
    }

    sort(randomized.begin(), randomized.end(), [](const pair<int,int>& x, const pair<int,int>& y) -> bool {
        return x.first < y.first;
    });

    vector<int> winners;
    for (int i=0; i<k; ++i) {
        winners.push_back(randomized[rand() % randomized.size()].second);
    }

    return winners;
}


vector<string> select(vector<string>& population, int k, const string& ref)
{
    vector<string> winners;
    vector<double> values;
    for (const auto& dna: population) {
        values.push_back(fitness(dna, ref));
    }

    int bestId = findMax(values);
    cout << "best value in population: " << values[bestId] << endl;
    winners.push_back(population[bestId]);

    auto selected_ids = lottery_no_rep(values, k-1);
    for (int id: selected_ids) {
        winners.push_back(population[id]);
    }
    return winners;
}


set<string> reconstructDna(
    const vector<string>& spectrum,
    const string& start,
    const Config& config)
{
    const int populationSize = 100;
    const int maxPopulations = 1000;
    const int mutationsNumber = 5;
    const int mutationsPerDNA = 3;
    const int crossoversNumber = 20;

    vector<string> population;

    // random initial population
    for (int i=0; i<populationSize; ++i) {
        population.push_back(randomSequence(config.n));
    }

    // evolution
    int popCount = 0;
    while (popCount++ <= maxPopulations)
    {
        if (popCount % 10 == 0) cout << "generation #" << popCount << endl;
        // mutations
        for (int i=0; i<mutationsNumber; ++i) {
            int poorBastard = rand() % populationSize;
            mutate(population[poorBastard], mutationsPerDNA);
        }

        // selection
        auto nextGeneration = select(population, populationSize - crossoversNumber, config.dna);

        // crossovers
        for (int i=0; i<crossoversNumber; ++i) {
            int one = rand() % populationSize;
            int two = rand() % populationSize;
            string newGuy = cross(population[one], population[2]);
            nextGeneration.push_back(newGuy);
        }

        // replacement
        population = nextGeneration;
    }
 
    // convert to output format
    set<string> solutions(population.begin(), population.end());
    return solutions;
}

