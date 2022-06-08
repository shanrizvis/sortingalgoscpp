#include <iostream>
#include <array>
#include <memory>
#include "bogosort.h"
#include "sorter.h"
#include "Bubblesort.h"
#include "Selectionsort.h"
#include "shellsort.h"
#include "sortvector.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"

template <typename T>
void compare();


int main(){
    compare<int>();
    std::cout<<"Done"<<std::endl;
    return 0;
}



template <typename T>
void compare(){
    std::array<std::pair<std::string, std::unique_ptr<Sorter<T>>>, 6> sorters = {
        std::make_pair("Bubble Sort", std::make_unique<Bubblesort<T>>()),
        std::make_pair("Selection Sort", std::make_unique<Selectionsort<T>>()),
        std::make_pair("Shell Sort", std::make_unique<Shellsort<T>>()),
        std::make_pair("Heap Sort", std::make_unique<Heapsort<T>>()),
        std::make_pair("Merge Sort", std::make_unique<Mergesort<T>>()),
        std::make_pair("Quick Sort", std::make_unique<Quicksort<T>>())
    };

    for(const auto& el : sorters){
        std::cout<<"//////////////////////////////////////"<<std::endl;
        std::cout<<"Evaluating: "<<el.first<<std::endl;
        el.second->evaluate(5000);
    }

}