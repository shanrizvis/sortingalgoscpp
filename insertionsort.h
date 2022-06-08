#pragma once
#include "sorter.h"
#include "sortvector.h"

class Insertionsort: public Sorter<T>{
    public:
        void operator()(Sortvector<int> &) const;      
};

void Insertionsort::operator()(Sortvector<int> &vect) const{

    for(int i =1; i< vect.size()-1; i++){
        int tmp = std::move(vect[i]);
        int compare_index = i-1;
        while(compare_index >=0 && vect[compare_index] < tmp){
            vect[compare_index] = std::move(vect[compare_index+1]);
            compare_index--;
        }

        vect[compare_index+1] = std::move(tmp);
    }
   
}