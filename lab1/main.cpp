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
    ReverseComp<int> comp;
    BubbleSort<int> psort;
    psort.sort(massdl, 0, 999, comp);

    for(int i = 0; i < 1000; i++){
        std::cout << massdl.Get(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}