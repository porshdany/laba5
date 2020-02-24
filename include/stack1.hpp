//Copyright 2019 <LinkIvan333>

#ifndef INCLUDE_STACK1_HPP_
#define INCLUDE_STACK1_HPP_
#include <memory>
#include <iostream>
#include <utility>
template <typename T>
class stack1
{
private:
    unsigned int *size = new unsigned int;
    std::unique_ptr<T[]> arr;
public:
    void push(T&& value);
    void push(const T& value);
    void pop();
    const T& head() const;
    stack1();
    ~stack1();
    stack1(stack1&& stack);
    stack1<T>& operator=(stack1<T>&& stack);
};

template <typename T>
stack1<T>::stack1(){
    *(size) = 0;
    arr.reset(new T[*(size)]);
}

template <typename T>
stack1<T>& stack1<T>::operator=(stack1<T>&& stack) {
    if (std::move(stack) != this) {
        std::swap(size, stack.size);
        std::swap(this->arr, stack.arr);
    }

    return *this;
}
template <typename T>
stack1<T>::stack1(stack1&& stack){
    std::swap(*size, *stack.size);
    std::swap(arr, stack.arr);
}

template <typename T>
stack1<T>::~stack1(){
    delete size;
    arr.reset();
}

template <typename T>
void stack1<T>::pop() {
    if (*(size) == 0) {
        std::cout << "Массив пуст";
        return;
    }
    (*(size))--;
    std::unique_ptr<T[]> new_arr(new T[*(size)]);
    for (unsigned int i = 0; i < *(size); ++i){
        new_arr.get()[i]  =  arr.get()[i];
    }
    arr.swap(new_arr);
    new_arr.reset();
}

template <typename T>
const T& stack1<T>::head() const{
        return arr.get()[*(size) - 1];
}

template <typename T>
void stack1<T>::push(const T& value) {
    (*(size))++;
std::unique_ptr<T[]> new_arr(new T[*(size)]);
 for (unsigned int i = 0; i < (*(size)-1); ++i){
     new_arr[i] = arr.get()[i];
 }
 new_arr.get()[*(size)-1] = value;
 arr.swap(new_arr);
    new_arr.reset();
}

template <typename T>
void stack1<T>::push(T&& value) {
    (*(size))++;
    std::unique_ptr<T[]> new_arr(new T[*(size)]);
    for (unsigned int i = 0; i < (*(size)-1); ++i){
        new_arr[i] = arr.get()[i];
    }
    new_arr.get()[*(size)-1] = std::move(value);
    arr.swap(new_arr);
    new_arr.reset();
}

#endif // INCLUDE_STACK1_HPP_
