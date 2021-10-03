#ifndef LINKEDLISTSEQUENCE
#define LINKEDLISTSEQUENCE

#include "sequence.hpp"

template <class T>
class LinkedListSequence : public Sequence<T>{
public:
    LinkedListSequence(T*,int);
    LinkedListSequence();
    LinkedListSequence(const LinkedListSequence<T> &);
    ~LinkedListSequence();
    T GetFirst() const;
    T GetLast() const;
    T Get(int) const;
    void Set(int,const T&);
    LinkedListSequence<T>* GetSubsequence(int,int);
    int GetLenght() const;
    void Append(const T&);
    void Prepend(const T&);
    void InsertAt(const T&, int);
    LinkedListSequence<T> * Concat(Sequence <T> *);
    //friend void clear();
private:
    LinkedList<T>*  mass;
};



template<class T>
LinkedListSequence<T>::LinkedListSequence(T* item,int count){
    mass = new LinkedList<T>(item, count);
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(){
    mass = new LinkedList<T>();
}

template<class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedListSequence <T> & list) {
    mass = new LinkedList<T>(*(list.mass));
}

template<class T>
LinkedListSequence<T>::~LinkedListSequence(){
    #ifdef DEBUG 
        std::cerr << "Destroy Object type LinkedListSequence<T>" << mass << std::endl;
    #endif
    
    delete mass;

}

template<class T>
T LinkedListSequence<T>::GetFirst() const{
    return mass->GetFirst();
}

template<class T>
T LinkedListSequence<T>::GetLast() const{
    return mass->GetLast();
}

template<class T>
T LinkedListSequence<T>::Get(int ind) const{
    return (mass->Get(ind));
}

template<class T>
void LinkedListSequence<T>::Set(int ind,const T& item){
    mass->Set(ind, item);
}

template<class T>
int LinkedListSequence<T>::GetLenght() const{
    return mass->GetLenght();
}

template<class T>
LinkedListSequence<T> * LinkedListSequence<T>::GetSubsequence(int start,int stop){
    LinkedListSequence<T> * newlist = new LinkedListSequence();
    newlist->mass = mass->GetSubList(start, stop);
    return newlist;
}

template<class T>
void LinkedListSequence<T>::Append(const T& item){
    mass->Append(item);
}

template<class T>
void LinkedListSequence<T>::Prepend(const T& item){
    mass->Prepend(item);
}

template<class T>
void LinkedListSequence<T>::InsertAt(const T& item, int ind){
    mass->InsertAt(item, ind);
}

template<class T>
LinkedListSequence<T> * LinkedListSequence<T>::Concat(Sequence <T> * list){
    for(int i = 0; i < list->GetLenght(); i++) {
        Append(list->Get(i));
    }

    return this;
}



#endif