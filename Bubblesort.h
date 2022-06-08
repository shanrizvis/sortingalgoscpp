#pragma once
#include "sorter.h"
#include "sortvector.h"

template <typename T>
class Bubblesort: public Sorter<T>{
    public:
        void operator()(Sortvector<T> &) const;      
};


template <typename T>
void Bubblesort<T>::operator()(Sortvector<T> &vect) const{
    for(int i =0; i< vect.size(); i++){
        for(int j =0; j< (vect.size()- 1) - i; j++){
            if(vect[j] > vect[j+1]){
                int tmp = std::move(vect[j]);
                vect[j] = std::move(vect[j+1]);
                vect[j+1] = std::move(tmp); 
            }  
        }
    }
}