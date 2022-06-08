#pragma once
#include "sorter.h"
#include "sortvector.h"


template <typename T>
class Shellsort: public Sorter<T>{
    public:
        void operator()(Sortvector<T> &) const;      
};


template <typename T>
void Shellsort<T>::operator()(Sortvector<T> &vect) const{
    for(int gap_size = vect.size()/2; gap_size >0; gap_size/=2){
        
        for(int i =gap_size; i<vect.size(); i++){

            int tmp = std::move(vect[i]);
            
            int j =0;
            for(j = i; j >= gap_size && vect[j-gap_size] >tmp; j-=gap_size){
               vect[j] = std::move(vect[j-gap_size]);
            }

            vect[j] = std::move(tmp);
        
        }   
    }
   
}