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

    ints.insert(ints.begin(), 8);
    ints.insert(ints.begin(), 9);
    ints.insert(ints.begin(), 10);
    printMe();
    ints.erase(ints.begin());
    printMe();

}