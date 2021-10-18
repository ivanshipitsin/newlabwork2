//#define DEBUG
#include <iostream>
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "sort.hpp"
#include <time.h>

template<typename T>
class ReverseComp : public iComp<T> {
public:
    bool cmp(const T & a, const T & b){
        return a < b;
    }
};

void randomGen(Sequence<int> &, int);

int main(int argc, char**argv){
    srand(time(nullptr));
    // object sorting
    DefaultComp<int> compp;
    ReverseComp<int> rcompp;

    MergeSort<int> msort;
    InsertSort<int> isort;
    CocktailSort<int> csort;
    BubbleSort<int> bsort;
    QuickSort<int> qsort;

    if(argc == 1){
        bool typestruct, generate;
        int count;
        std::cout << "Hello in my lab1 in 2))\n";
        std::cout << "Select type of structer:(Array - 0) or (Linkedlist - 1)\n";
        std::cin >> typestruct;
        ArraySequence<int> arr;
        LinkedListSequence<int> list;
        std::cout << "Manual input(0) or random(1) ?\n";
        std::cin >> generate;
        std::cout << "Enter count:\n";
        std::cin >> count;

        if(generate){
            if(typestruct)
                randomGen(list, count);
            else 
                randomGen(arr, count);
        } else {
            std::cout << "Enter data\n";
            int a;
            for(int i = 0; i < count; i++){
                std::cin >> a;
                if(typestruct){
                    list.Append(a);
                }else {
                    arr.Append(a);
                }
            }
        }
        //generate time
        {
            if(typestruct){
                LinkedListSequence<int> list1(list);
                LinkedListSequence<int> list2(list);
                LinkedListSequence<int> list3(list);
                LinkedListSequence<int> list4(list);
                LinkedListSequence<int> list5(list);
                double time1, time2, time3, time4, time5;

                clock_t tp = clock();
                msort.sort(list1, 0, count - 1, compp);
                tp = clock() - tp;
                time1 = (double)tp / CLOCKS_PER_SEC;

                tp = clock();
                isort.sort(list2, 0, count - 1, compp);
                tp = clock() - tp;
                time2 = (double)tp / CLOCKS_PER_SEC;

                tp = clock();
                csort.sort(list3, 0, count - 1, compp);
                tp = clock() - tp;
                time3 = (double) tp / CLOCKS_PER_SEC;

                tp = clock();
                bsort.sort(list4, 0, count - 1, rcompp);
                tp = clock() - tp;
                time4 = (double) tp / CLOCKS_PER_SEC;

                tp = clock();
                qsort.sort(list5, 0, count - 1, compp);
                tp = clock() - tp;
                time5 = (double) tp / CLOCKS_PER_SEC;


                std::cout << "MERGESORT TIME(in linked list):" << time1 << "\n";
                std::cout << "INSERTSORT TIME(in linked list):" << time2 << "\n";
                std::cout << "COCKTAILSORT TIME(in linked list):" << time3 << "\n";
                std::cout << "BUBBLESORT TIME(in linked list):" << time4 << "\n";
                std::cout << "QUICKSORT TIME(in linked list):" << time5 << "\n";

                if(!generate){
                    std::cout << "\t" << "Merg" << "\t" << "Insr" << "\t" << "Cock" << "\t" << "Bubb" << "\t" << "Quic" << "\n";
                    for(int i = 0; i < list1.GetLenght(); i++){
                        std:: cout  << "\t" << list1.Get(i) << "\t" << list2.Get(i) << "\t" << list3.Get(i) << "\t" << list4.Get(i) << "\t" << list5.Get(i) << "\n";
                    }
                }

            } else {
                ArraySequence<int> list1(arr);
                ArraySequence<int> list2(arr);
                ArraySequence<int> list3(arr);
                ArraySequence<int> list4(arr);
                ArraySequence<int> list5(arr);
                double time1, time2, time3, time4, time5;

                clock_t tp = clock();
                msort.sort(list1, 0, count - 1, compp);
                tp = clock() - tp;
                time1 = (double)tp / CLOCKS_PER_SEC;

                tp = clock();
                isort.sort(list2, 0, count - 1, compp);
                tp = clock() - tp;
                time2 = (double)tp / CLOCKS_PER_SEC;

                tp = clock();
                csort.sort(list3, 0, count - 1, compp);
                tp = clock() - tp;
                time3 = (double) tp / CLOCKS_PER_SEC;

                tp = clock();
                bsort.sort(list4, 0, count - 1, rcompp);
                tp = clock() - tp;
                time4 = (double) tp / CLOCKS_PER_SEC;

                tp = clock();
                qsort.sort(list5, 0, count - 1, compp);
                tp = clock() - tp;
                time5 = (double) tp / CLOCKS_PER_SEC;


                std::cout << "MERGESORT TIME(in Dynamic array):" << time1 << "\n";
                std::cout << "INSERTSORT TIME(in Dynamic array):" << time2 << "\n";
                std::cout << "COCKTAILSORT TIME(in Dynamic array):" << time3 << "\n";
                std::cout << "BUBBLESORT TIME(in Dynamic array):" << time4 << "\n";
                std::cout << "QUICKSORT TIME(in Dynamic array):" << time5 << "\n";
            

                if(!generate){
                    std::cout << "\t" << "Merg" << "\t" << "Insr" << "\t" << "Cock" << "\t" << "Bubb" << "\t" << "Quic" << "\n";
                    for(int i = 0; i < list1.GetLenght(); i++){
                        std:: cout  << "\t" << list1.Get(i) << "\t" << list2.Get(i) << "\t" << list3.Get(i) << "\t" << list4.Get(i) << "\t" << list5.Get(i) << "\n";
                    }
                }
            }
        }

    }
    return 0;
}



void randomGen(Sequence<int> & data, int amount){
    for(int i = 0; i < amount; i++){
        data.Append(rand()%(amount + 10000000));
    }
}