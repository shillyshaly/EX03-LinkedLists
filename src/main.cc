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

    ints.insert(ints.begin(), 7);
    ints.insert(ints.begin(), 9);
//    ints.insert(++ints.begin(),8);//inserts interior
    ints.insert(ints.end(), 13);
//    ints.insert(++(++ints.begin()), 5);
    ints.insert(ints.end(), 15);
    ints.erase(++ints.begin());
    printMe();
    ints.erase(ints.begin(), ints.end());
    printMe();
    ints.pop_front();
    printMe();
    ints.pop_back();
    printMe();
    ints.pop_back();
    printMe();
    ints.clear();
    printMe();

}