#pragma once
#include "sorter.h"
#include "sortvector.h"

template <typename T>
class Selectionsort: public Sorter<T>{
    public:
        void operator()(Sortvector<T> &) const;      
};


template <typename T>
void Selectionsort<T>::operator()(Sortvector<T> &vect) const{
    for(int i=0; i<vect.size();i++){
        int lowest_index = i; 
        for(int j =i+1; j<vect.size(); j++){
            if(vect[j] < vect[lowest_index]){
                lowest_index = j;
            }
        }
        int tmp = std::move(vect[i]);
        vect[i] = std::move(vect[lowest_index]);
        vect[lowest_index] = std::move(tmp);
    }
}