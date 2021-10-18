#include <iostream>
#include <time.h>
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "sort.hpp"
#include <fstream>


int main(int argc, char**argv){
    srand(time(nullptr));
    
    DefaultComp<int> comp;
    MergeSort<int> psort;
    InsertSort<int> ppsort;

    std::ofstream file("MassMergeright.txt");
    for(int N = 100; N < 100000; N += 10){
        ArraySequence<int> massdl(N);
        for(int i = 0; i < N; i++){
            massdl.Set(i, i);
        }

        clock_t p = clock();
            psort.sort(massdl, 0, N - 1, comp);
        p = clock() - p;

        double timep = (double) p / CLOCKS_PER_SEC;
       // std::cout << N << " " << timep << "\n";
        file << N << " " << timep << std::endl;
        
    }

    return 0;
}