//
// Created by Jamie on 10/11/2019.
//
#include <iostream>
#include "../include/list.h"

using edu::vcccd::vc::csv15::list;

list<int> ints;
void printMe(){
    for(int i: ints){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
};

int main(){

    list<int> ints(3, 12);

    for(int i: ints){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;

    ints.erase(++ints.begin());
    for(int i: ints){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    std::cout << ints.size() << std::endl;
    std::cout << ints.front() << std::endl;
    std::cout << ints.back() << std::endl;


}