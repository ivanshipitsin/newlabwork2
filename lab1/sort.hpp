#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include "sequence.hpp"

template<typename T>
class iSort{
public:
    virtual void sort(Sequence<T> &,int start, int end,iComp<T> &);
};

template<typename T>
class iComp{
public:
    virtual bool cmp(const T &, const T&);
};

template<typename T>
class DefaultComp : iComp<T>{
public:
    bool cmp(const T & a, const T& b){
        return a > b;
    }
};

template<typename T>
class InsertSort : public iSort<T>{
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp){
        for(int i = start + 1; i < end; i++){
            T key = data.Get(i);
            int j = i - 1;
            for(; j >= 0 && comp.cmp(data.Get(j), key); j--){
                    //mass[j+1] = mass[j];
                    data.Set(j+1 ,data.Get(j));
            }
            if(j < 0){
                j = 0;
        }
        //mass[j] = key;
        data.Set(j, key);
    }
    }
};

template<typename T>
class InsertSort : public iSort<T>{
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp){
        int right = end - 1;
        int left = start;
        int contr = end - 1;
        do{
        for(int i = right; i > left ; i --){
            if(comp.cmp(data.Get(i-1), data.Get(i))){
                
                contr = i;
            }
        }
        left = contr;
        for(int j = left; j < right; j++){
            if(comp.cmp(data.Get(j), data.Get(j + 1))){
                T tmp = data.Get(j);
                data.Set(j, data.Get(j + 1));
                data.Set(j + 1, tmp);
                contr = j;
            }
        }
        right = contr;
        }while(left < right);
    }
};


void mergesort(int * mass, int left, int right){
    if(right - left == 0){
        return;
    }
    int middle = (right + left)/ 2 ;
    mergesort(mass, left, middle);
    mergesort(mass, middle + 1, right);
    int i = left;
    int j = middle + 1;
    int * tmp = new int[right - left + 1];
    int k = 0;
    while(i <= middle || j <= right){
        if(j <= right && i<= middle && mass[i] > mass[j]){
            tmp[k] = mass[j];
            k++;
            j++;
        }
        else if(i <= middle && j <= right && mass[i] <= mass[j]){
            tmp[k] = mass[i];
            i++;
            k++;
        } else if( i > middle){
            tmp[k] = mass[j];
            k++;
            j++;
        } else if(j > right){
            tmp[k] = mass[i];
            k++;
            i++;
        }
    }

    for(k--; k >=0; k--){
        mass[left + k] = tmp[k];
    }
    delete[] tmp;

}

template<typename T>
void bubblesortSequence(Sequence<T> & elem){
    for(int i = 0; i < elem.GetLenght(); i++){
        for(int j = elem.GetLenght() -1; j > i; j--){
            if(elem.Get(j) > elem.Get(j-1)){
                T tmp = elem.Get(j);
                elem.Set(j, elem.Get(j-1));
                elem.Set(j-1, tmp);
            }
        }
    }
}

#endif