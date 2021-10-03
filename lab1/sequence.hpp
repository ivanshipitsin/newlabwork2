#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP 1
#include "list.hpp"
#include "dynamic.hpp"


template<class T>
class Sequence {
public:
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int) const = 0;
    virtual Sequence<T>* GetSubsequence(int,int) = 0;
    virtual int GetLenght() const = 0;
    virtual void Append(const T&) = 0;
    virtual void Prepend(const T&) = 0;
    virtual void Set(int,const T&) = 0;
    virtual void InsertAt(const T&, int) = 0;
    virtual Sequence<T> * Concat(Sequence <T> *) = 0;
};

#endif