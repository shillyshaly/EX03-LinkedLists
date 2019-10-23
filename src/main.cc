//
// Created by Jamie on 10/11/2019.
//
#include <iostream>
#include "../include/list.h"

using edu::vcccd::vc::csv15::list;
using namespace std;

list<int> ints;
void printMe(){
    for(int i: ints){
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
};

int main(){
    list<int> ints;
    for (int i = 0; i < 10; i++) {
        ints.push_back(i);
    }

    auto i = ++ints.begin();
    ints.erase(++ints.begin(), ++(++(++(++(++(++(++(++(i)))))))));

    cout << ints.size() << endl;
    cout << ints.front() << endl;
    cout << ints.back() << endl;
}