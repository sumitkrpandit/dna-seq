1. Build project:

    make all

2. Run project:

    ./bin/seq
    ./bin/gen 10 3

3. Algorithm description:

idea 1:
    - begin at P randomly selected oligonucleotides.
    - run algorithm locally until you generate some set of
        oligonucleotides of 2k.
    - repeat until you get oligonucleotides of length C.
    - use on of length C as a new spectrum S2.
    - run the basic algorithm based on S2 spectrum.


problem with genetic algorithm:
    - how to evaluate generated dna without comparing to the reference sequence?
        + by distribution of nucleotides
        + by errors distribution
        + by biological heuristics (only for biological sequencing problem,
                not applicable for random strings)
        

- powtórzenia
- błędy negatywne w spektrum: brak fragmentu występującego w dna
- błędy pozytywne w spektrum: występują fragmenty których brak w dna

Czy gdyby do hybrydyzacji używać macierzy która w każdej komórce zawiera
te same oligonukleotydy i wykorzystać 4^k macierzy dla każdej sekwencji
to wyniki na każdej macierzy byłyby proporcjonalne do ilości wystąpień
poszczególnych podciągów w dna?

Wykorzystanie wielokrotnej hybrydyzacji do określenia częstlotliwości
występowania danych oligonukleotydów oraz minimalizowania wpływu błędów
na wyniki.


capital letters are used for translated protein seq.
small letters used for nucleotide seq.

Sequence in lower case is used for sequence identified
by RepeatMasker as low-complexity or repetitive elements.



4. Testing description:

...

5. Results:

...

6. Conclusion:

...


