//
// Created by Jamie on 10/11/2019.
//
#include <iostream>
#include "../include/list.h"

using edu::vcccd::vc::csv15::list;

int main(){
    list<int> ints;

    ints.push_front(7);
//    ints.insert(ints.begin(), 7);
//    ints.insert(ints.begin(), 9);
//
//    ints.insert(++ints.begin(),8);//inserts interior
//    ints.insert(ints.end(), 13);
//    ints.insert(++(++ints.begin()), 5);
//    ints.insert(ints.end(), 15);
    for(int i: ints){
        std::cout << i << std::endl;
    }

}