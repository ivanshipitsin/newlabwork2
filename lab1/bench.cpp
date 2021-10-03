#include <iostream>
#include <time.h>
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "sort.hpp"
#include <fstream>


int main(int argc, char**argv){
    srand(time(nullptr));
    
    std::ofstream file("MassMerg.txt");
    for(int N = 2048; N < 10000000; N += 1000){
        ArraySequence<int> massdl(N);
        for(int i = 0; i < N; i++){
            massdl.Set(i, rand() % 1000000);
        }
        DefaultComp<int> comp;
        CocktailSort<int> psort;

        clock_t p = clock();
            psort.sort(massdl, 0, N - 1, comp);
        p = clock() - p;

        double timep = (double) p / CLOCKS_PER_SEC;
        std::cout << N << " " << timep << "\n";
        file << N << " " << timep << std::endl;
        
    }

    {
        ArraySequence<int> massdl(1000);
        for(int i = 0; i < 1000; i++){
            massdl.Set(i, rand() % 10000);
        }

        DefaultComp<int> comp;
        InsertSort<int> psort;
        psort.sort(massdl, 0, massdl.GetLenght() - 1, comp);
        std::cout << "INSERT" << std::endl;
        for(int i = 0; i < 1000; i++){
            std::cout << massdl.Get(i) << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}