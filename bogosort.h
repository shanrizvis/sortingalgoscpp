#pragma once
#include "sorter.h"
#include "sortvector.h"

template <typename T>
class Bogosort: public Sorter<T>{
    public:
        void operator()(Sortvector<T> &) const;      
};

template <typename T>
void Bogosort<T>::operator()(Sortvector<T> &vect) const{
    while(!vect.is_sorted()){
        vect.shuffle();
    }
   
}