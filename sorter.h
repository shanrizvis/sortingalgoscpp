#pragma once

#include <chrono>
#include "sortvector.h"


template <typename T>
class Sorter{
    private:
        void measure(const std::string& , Sortvector<T>&);

    public:
        Sorter() = default;
        Sorter(std::vector<int>&);
        
        Sorter(const Sorter&) = delete;
        Sorter(Sorter&&) = delete;

        Sorter& operator=(const Sorter&) = default;
        Sorter& operator=(Sorter&&) = default;

        virtual ~Sorter() = default;

        virtual void operator()(Sortvector<int> &) const =0;

        void evaluate(int);


};

template <typename T>
void Sorter<T>::evaluate(int arr_size){
    Sortvector<int> test = Sortvector<int>(arr_size);
    
    test.add_numbers_ordend();
    this->measure("Ordered numbers ", test);
    test.add_numbers_reverse();
    this->measure("Reverse numbers ", test);
    test.add_numbers_random(50);
    this->measure("random numbers ", test);

}

template <typename T>
void Sorter<T>::measure(const std::string& name, Sortvector<T>& to_sort){
    std::cout<<"-----------------"<<name<<"-----------------"<<std::endl;
    auto start = std::chrono::steady_clock::now();
    (*this)(to_sort);
    std::chrono::duration<double, std::milli> diff(std::chrono::steady_clock::now() - start);
    std::cout<<"Done in "<< diff.count()<<" ms "<< "Is the array sorted? "<<(to_sort.is_sorted() ? "yes" : "no") <<std::endl;
    
}





