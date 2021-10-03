#ifndef SORT_HPP
#define SORT_HPP

#include <iostream>
#include "sequence.hpp"


template<typename T>
class iComp{
public:
    virtual bool cmp(const T &, const T&) = 0;
};


template<typename T>
class DefaultComp : public iComp<T>{
public:
    bool cmp(const T & a, const T& b){
        return a > b;
    }
};


template<typename T>
class iSort{
public:
    virtual void sort(Sequence<T> &, int, int, iComp<T> &) = 0;
};



template<typename T>
class InsertSort : public iSort<T>{
public:
    void sort(Sequence<T> & data, int start, int end, iComp<T> & comp){
        for(int i = start + 1; i < end + 1; i++){
            T key = data.Get(i);
            int j = i - 1;
            for(; j >= start && comp.cmp(data.Get(j), key); j--){
                    //mass[j+1] = mass[j];
                    data.Set(j + 1 ,data.Get(j));
            }
            if(j < start){
                data.Set(start, key);
            }
            //mass[j] = key;
            if(j == i - 1)
                continue;    
            data.Set(j + 1, key);
        }
    }
};

template<typename T>
class CocktailSort : public iSort<T>{
public:
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp){
        int right = end;
        int left = start;
        int contr = end;
        do{
            for(int i = right; i > left; i--){
                if(comp.cmp(data.Get(i - 1), data.Get(i))){
                    T tmp = data.Get(i);
                    data.Set(i, data.Get(i - 1));
                    data.Set(i - 1, tmp);
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

template<typename T>
class MergeSort : public iSort<T>{
public:
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp){
        T * temp = new T[data.GetLenght()];
        mergesortGeneral(data, start, end , comp, temp);
        delete[] temp;
    }
    void mergesortGeneral(Sequence<T> & data,int start, int end ,iComp<T> & comp, T * tmp){
        if(end - start == 0){
            return;
        }
        int middle = (end + start)/ 2 ;
        mergesortGeneral(data, start, middle, comp, tmp);
        mergesortGeneral(data, middle + 1, end, comp, tmp);
        int i = start;
        int j = middle + 1;
        int k = 0;
        while(i <= middle || j <= end){
            if(j <= end && i<= middle && comp.cmp(data.Get(i), data.Get(j))){
                tmp[k] = data.Get(j);
                k++;
                j++;
            }
            else if(i <= middle && j <= end && !comp.cmp(data.Get(i), data.Get(j))){
                tmp[k] = data.Get(i);
                i++;
                k++;
            } else if( i > middle){
                tmp[k] = data.Get(j);
                k++;
                j++;
            } else if(j > end){
                tmp[k] = data.Get(i);
                k++;
                i++;
            }
        }

        for(k--; k >=0; k--){
            data.Set(start + k, tmp[k]);
        }
    }
};

template<typename T>
class BubbleSort : public iSort<T>{
public:
    void sort(Sequence<T> & data,int start, int end ,iComp<T> & comp){
        for(int i = start; i < end + 1; i++){
        for(int j = end; j > i; j--){
            if(comp.cmp(data.Get(j), data.Get(j - 1) ) ){
                T tmp = data.Get(j);
                data.Set(j, data.Get(j - 1) );
                data.Set(j - 1, tmp);
            }
        }
    }
    }
};

#endif