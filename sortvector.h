#pragma once

#include <vector>
#include <random>

template <typename T>
class Sortvector: public std::vector<T>{
    private:
        int capacity = 10;
    public:
        Sortvector() = default;
        Sortvector(int);
        Sortvector(std::initializer_list<T>);

        Sortvector(const Sortvector<T>& );
        Sortvector(Sortvector<T> &&) = default;
        Sortvector<T>& operator=(const Sortvector<T>&) = default;
        Sortvector<T>& operator=(Sortvector<T>&&) = default;

        void add_numbers_ordend();
        void add_numbers_reverse();
        void add_numbers_random(int);
        void shuffle();
        bool is_sorted() const;

        virtual ~Sortvector() = default;

        template <typename Y>
        friend std::ostream& operator<<(const std::ostream&, const Sortvector<Y>&);
};

template <typename Y>
std::ostream& operator<<(std::ostream& out, const Sortvector<Y>& v){
    for(Y el :v){
        out<<el<<" ";
    }
    return out;
}

template <typename T>
Sortvector<T>::Sortvector(int size):
    capacity(size)
{
};

template <typename T>        
Sortvector<T>::Sortvector(std::initializer_list<T>){

}

template <typename T>
Sortvector<T>::Sortvector(const Sortvector<T>& ){

}

template <typename T>
void Sortvector<T>::add_numbers_ordend(){
    this->clear();
    for(int i =0; i< this->capacity; i++){
        this->push_back(i); 
    }
}

template <typename T>
void Sortvector<T>::add_numbers_reverse(){
    this->clear();
    for(int i =this->capacity; i>0; i--){
        this->push_back(i); 
    }

}

template <typename T>
void Sortvector<T>::add_numbers_random(int cap){
    this->clear();
    for(int i =0; i< this->capacity; i++){
        this->push_back(std::rand() % cap);
    }

}

template <typename T>
void Sortvector<T>::shuffle(){
    std::random_device rd;
    std::mt19937 eng{rd()};

    std::shuffle(this->begin(), this->end(), eng);
}


 
template <typename T>
bool Sortvector<T>::is_sorted() const{
    return std::is_sorted(this->begin(), this->end());
}



