#pragma once
#include "sorter.h"
#include "sortvector.h"

template <typename T>
class Mergesort: public Sorter<T>{
    public:
        void operator()(Sortvector<T> &) const;      
};


template <typename T>
void merge(Sortvector<T> &vect, int left, int mid, int right){
    const int left_count = mid - left +1;
    const int right_count = right - mid;

    int* left_els = new int[left_count];
    int* right_els = new int[right_count];


    for(int i =0; i< left_count; i++){
        left_els[i] = std::move(vect[left + i]);
    }

    for(int i =0; i< right_count; i++){
        right_els[i] = std::move(vect[mid +1 + i]);
    }

    int index_left =0;
    int index_right =0;
    int index_sorting_vec = left;

    while(index_left < left_count && index_right < right_count){
        if(left_els[index_left] <= right_els[index_right]){
            vect[index_sorting_vec] = std::move(left_els[index_left]);
            index_left++;
        } else{
            vect[index_sorting_vec] = std::move(right_els[index_right]);
            index_right++;
        }
        index_sorting_vec++;
    }

    while (index_left < left_count)
    {
        vect[index_sorting_vec] = std::move(left_els[index_left]);
        index_left++;
        index_sorting_vec++;
    }

    while (index_right < right_count)
    {
        vect[index_sorting_vec] = std::move(right_els[index_right]);
        index_right++;
        index_sorting_vec++;
    }
    
    delete[] left_els;
    delete[] right_els;
    

}

template <typename T>
void merge_sort(Sortvector<T> &vect, int left, int right){
    if(left < right){
        int mid = (left + (right - left) /2);
        merge_sort(vect, left, mid);
        merge_sort(vect, mid+1, right);
        merge(vect, left, mid, right);
    }
}


template <typename T>
void Mergesort<T>::operator()(Sortvector<T> &vect) const{
    merge_sort(vect, 0, vect.size());
}