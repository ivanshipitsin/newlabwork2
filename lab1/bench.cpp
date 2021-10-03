#include <iostream>
#include <time.h>
#include "sequence.hpp"
#include "sort.hpp"
#include <fstream>


int main(int argc, char**argv){
    srand(time(nullptr));
    
    std::ofstream file("MassMerg2.txt");
    for(int N = 2048; N < 10000000; N += 1000){
        int * mass = new int[N];
        for(int i = 0; i < N; i++){
            mass[i] = rand() % 1000000;
        }

        clock_t p = clock();
        cocktailsort(N, mass);
        p = clock() - p;
        double timep = (double) p / CLOCKS_PER_SEC;
        std::cout << N << " " << timep << "\n";
        file << N << " " << timep << std::endl;
        delete[] mass;
        
    }
    ArraySequence<int> massdl(1000);
    for(int i = 0; i < 1000; i++){
        massdl.Set(i, rand() % 10000);
    }

    insertsort(massdl);
    std::cout << "INSERT" << std::endl;
    for(int i = 0; i < 1000; i++){
        std::cout << massdl.Get(i) << ' ';
    }
    std::cout << '\n';
    
    return 0;
}