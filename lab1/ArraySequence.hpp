#ifndef ARRAY_SEQUENCE
#define ARRAY_SEQUENCE

#include "sequence.hpp"

template <class T>
class ArraySequence : public Sequence<T>{
public:
    ArraySequence(T*,int);
    ArraySequence();
    ArraySequence(const ArraySequence<T> &);
    ArraySequence(const DynamicArray<T> &);
    ArraySequence(int);
    T GetFirst() const;
    T GetLast() const;
    T Get(int) const;
    void Set(int,const T&);
    ArraySequence<T>* GetSubsequence(int,int);
    int GetLenght() const;
    void Append(const T&);
    void Prepend(const T&);
    void InsertAt(const T&, int);
    ArraySequence<T> * Concat(Sequence <T> *);
    //friend void clear();

private:
    DynamicArray<T> mass;
};

/// ArraySequence
template<class T>
ArraySequence<T>::ArraySequence(T* item,int count) : mass(item, count){
    #ifdef DEBUG 
        std::cerr << "Generate Object type ArraySequence<T> with construct (size)" << " " << count << std::endl;
        std::cerr << "Type of T" << typeid(mass.Get(0)).name() <<std::endl;
    #endif
}

template<typename T>
ArraySequence<T>::ArraySequence(const DynamicArray<T> & data): mass(data){}

template<class T>
ArraySequence<T>::ArraySequence(int count) : mass(count){
    #ifdef DEBUG 
        std::cerr << "Generate Object type ArraySequence<T> with construct (size)" << " " << count << std::endl;
        std::cerr << "Type of T" << typeid(mass.Get(0)).name() <<std::endl;
    #endif
}

template<class T>
ArraySequence<T>::ArraySequence(): mass(){
    #ifdef DEBUG 
        std::cerr << "Generate Object type ArraySequence<T> with construct ()" <<  std::endl;
        std::cerr << "Type of T" << typeid(mass.Get(0)).name() <<std::endl;
    #endif
}

template<class T>
ArraySequence<T>::ArraySequence(const ArraySequence <T> & list) : mass(list.mass) {}

template<class T>
T ArraySequence<T>::GetFirst() const {
    return mass.Get(0);
}

template<class T>
T ArraySequence<T>::GetLast() const {
    return mass.Get(mass.GetSize() - 1);
}

template<class T>
T ArraySequence<T>::Get(int ind) const{
    #ifdef DEBUG
        if(ind < 0 && ind >= GetLenght()){
            std::cerr << "ERROR ARRAYSEQUENCE GET INDEX " << ind << std::endl;
            throw "EXECPTION GET";
        }
    #endif
    return mass.Get(ind);
}

template<class T>
void ArraySequence<T>::Set(int ind,const T& item){
    mass.Set(ind, item);
}

template<class T>
int ArraySequence<T>::GetLenght() const{
    return mass.GetSize();
}

template<class T>
ArraySequence<T> * ArraySequence<T>::GetSubsequence(int start,int stop) {
    DynamicArray<T> *newdata = mass.Getsubarray(start, stop);
    ArraySequence<T> * newlist = new ArraySequence<T>(*newdata);
    delete newdata;
    return newlist;
}

template<class T>
void ArraySequence<T>::Append(const T& item){
    mass.Resize(mass.GetSize() + 1);
    mass.Set(mass.GetSize() - 1, item);
}

template<class T>
void ArraySequence<T>::Prepend(const T& item){
    mass.Prepend(item);
}

template<class T>
void ArraySequence<T>::InsertAt(const T& item, int ind){
    mass.InsertAt(ind, item);
}

template<class T>
ArraySequence<T> * ArraySequence<T>::Concat(Sequence <T> * list){
    for(int i = 0; i < list->GetLenght(); i++) {
        Append(list->Get(i));
    }

    return this;
}

#endif