#include <iostream>
#include "ArraySequence.hpp"
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
    ArraySequence<int> massdl(1000);
    for(int i = 0; i < 1000; i++){
        massdl.Set(i, rand() % 10000);
    }
    ArraySequence<int> mass(massdl);

    //ReverseComp<int> comp;
    DefaultComp<int> compp;
    MergeSort<int> psort;
    InsertSort<int> ppsort;
    ppsort.sort(mass, 0, 999, compp);
    psort.sort(massdl, 0, 999, compp);

    for(int i = 0; i < 1000; i++){
        if(mass.Get(i) != massdl.Get(i)){
            std::cerr << "AAAAAA" << mass.Get(i) << "(" << i << ")" << massdl.Get(i) << std::endl;
        }
    }

    for(int i = 0; i < 1000; i++){
        std::cout << massdl.Get(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}