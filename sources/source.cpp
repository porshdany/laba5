//Copyright 2019 <LinkIvan333>

#include <stack1.hpp>
#include <stack2.hpp>
int main(){
    stack1<int> t;
    stack2<int> y;
    stack1<int> z(std::move(t));
    for (int i = 0; i < 10; i++){
        t.push(i);
    }
    for (int i = 0; i < 10; i++){
        std::cout << t.head() << "\t";
        t.pop();
    }
    y.push_emplace(0, 1, 2);
    for (int i = 0; i < 3; i++){
        std::cout << y.head() << "\t";
       y.pop();
    }

    return 0;
}
