#pragma once
#include "sorter.h"
#include "sortvector.h"

template <typename T>
class Heapsort: public Sorter<T>{
    public:
        void operator()(Sortvector<T> &) const;      
};



template <typename T>
void max_heap_trickle(Sortvector<T> &vect,int size, int start_point){
    int new_root = start_point;
    int left_child = (2*start_point) +1;
    int right_child = (2*start_point) +2;

    if(left_child < size && vect[new_root] < vect[left_child]){
        new_root = left_child; 
    }

    if(right_child < size && vect[new_root] < vect[right_child]){
        new_root = right_child; 
    }


    if(start_point != new_root){
        std::swap(vect[start_point], vect[new_root]); 
        max_heap_trickle(vect, size, new_root);
    }

    

}


template <typename T>
void Heapsort<T>::operator()(Sortvector<T> &vect) const{

    // in a given tree the last non leaf node is the one with index (n/2)-1
    // we then trickle up untill we reach our beginning root node
    // swichting the the elements which are larger with the smaller ones

    for(int i =vect.size() /2 -1; i>=0; i--){ 
        max_heap_trickle(vect, vect.size(), i);
    }
    
    // we then gradually reduce the heap size, as we constantly put the highest element in the back
    // we switch the root/highest index with the back index and rebuild the maxheap
    // we then repeat the process but on the smaller tree as the last node is already sorted
    for(int i = vect.size() -1 ; i > 0; i--){ 
        std::swap(vect[0], vect[i]);
        max_heap_trickle(vect, i, 0);
    }
}


