#pragma once
#include "sorter.h"
#include "sortvector.h"

template <typename T>
class Quicksort: public Sorter<T>{
    public:
        void operator()(Sortvector<T> &) const;      
};



template <typename T>
int split(Sortvector<T> &vect, int index_start, int index_end){
    
    
    int pivot = index_end;
    int low_point = index_start;

    for(int i = index_start; i<index_end; i++){
        if(vect[i] <= vect[pivot]){
            std::swap(vect[low_point], vect[i]);
            low_point++;
        }

    }
    std::swap(vect[low_point], vect[pivot]);
    return low_point;
}


template <typename T>
void quick_sort(Sortvector<T> &vect, int index_start, int index_end){
    if(index_start < index_end){
        int pivot_point = split(vect, index_start, index_end);
    
        quick_sort(vect, index_start, pivot_point-1);
        quick_sort(vect, pivot_point+1, index_end);
    }
    
}


template <typename T>
void Quicksort<T>::operator()(Sortvector<T> &vect) const{
    quick_sort(vect,0, vect.size()-1);
}
