//#define DEBUG
#include <iostream>
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "sort.hpp"

template<typename T>
class ReverseComp : public iComp<T> {
public:
    bool cmp(const T & a, const T & b){
        return a < b;
    }
};

int main(int argc, char**argv){
    srand(time(nullptr));
    // object sorting
    DefaultComp<int> compp;
    MergeSort<int> psort;
    InsertSort<int> ppsort;
    QuickSort<int> prsort;

    /*if(argc > 1){
    bool typestruct;
        std::cout << "Hello in my lab1 in 2))\n";
        std::cout << "Select type of structer:\n";

    }*/
    LinkedListSequence<int> massdl;
    for(int i = 0; i < 1000; i++){
        massdl.Append(rand() % 10000);
    }
    LinkedListSequence<int> mass(massdl);

    //ReverseComp<int> comp;
    
    ppsort.sort(mass, 0, 999, compp);
    //psort.sort(massdl, 0, 999, compp);
    prsort.sort(massdl, 0, 999, compp);

    for(int i = 0; i < 1000; i++){
        if(mass.Get(i) != massdl.Get(i)){
            std::cerr << "AAAAAA" << mass.Get(i) << "(" << i << ")" << massdl.Get(i) << std::endl;
        }
    }

    for(int i = 0; i < 1000; i++){
        std::cout << massdl.Get(i) << "\t";
    }
    std::cout << std::endl;
    return 0;
}