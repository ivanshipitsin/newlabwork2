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
        LinkedListSequence<int> massdl;
        for(int i = 0; i < N; i++){
            massdl.Append(N - i);
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
    std::cout <<"MERGESORTERAND is start" << std::endl;
    timetestra("MergeSortRandL.txt", msort, 10,10000, 10);
    std::cout <<"QUICKSORTERAND is start" << std::endl;
    timetestra("QuickSortRandL.txt", qsort, 10,10000, 10);
    std::cout <<"COCKTAILSORTERAND is start" << std::endl;
    timetestra("CocktailSortRandL.txt", csort, 10,10000, 10);
    std::cout <<"INSERTSORTEREVERSE is start" << std::endl;
    timetestra("InsertSortReversL.txt", isort, 10,10000, 10);

    

    return 0;
}