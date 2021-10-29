#include <iostream>
#include <time.h>
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "sort.hpp"
#include <fstream>

void timetestra(std::string filename, iSort<int> & psort, int start, int end, int step){
    DefaultComp<int> comp;
    std::ofstream file(filename);
    int k = 0;
    for(int N = start; N < end; N += step){
        ArraySequence<int> massdl(N);
        for(int i = 0; i < N; i++){
            massdl.Set(i, N - i);
        }

        clock_t p = clock();
            psort.sort(massdl, 0, N - 1, comp);
        p = clock() - p;

        double timep = (double) p / CLOCKS_PER_SEC;
       // std::cout << N << " " << timep << "\n";
        file << N << " " << timep << std::endl;


        double percent = (double)(N-start) / (double)(end - start);
        //std::cout << percent << std::endl;
        if( percent > k*0.05){
            std::cout << 5*k << "%" << std::endl;
            k++;
        }
        
    }
}

int main(int argc, char**argv){
    srand(time(nullptr));
    
    
    CocktailSort<int> csort;
    MergeSort<int> msort;
    InsertSort<int> isort;
    QuickSort<int> qsort;
    std::cout <<"MERGESORTEREVERS is start" << std::endl;
    timetestra("MergeSortRevers.txt", msort, 10,10000, 10);
    std::cout <<"QUICKSORTEREVERS is start" << std::endl;
    timetestra("QuickSortRevers.txt", qsort, 10,10000, 10);
    std::cout <<"COCKTAILSORTEREVERS is start" << std::endl;
    timetestra("CocktailSortRevers.txt", csort, 10,10000, 10);
    std::cout <<"INSERTSORTEREVERS is start" << std::endl;
    timetestra("InsertSortRevers.txt", isort, 10,10000, 10);

    

    return 0;
}