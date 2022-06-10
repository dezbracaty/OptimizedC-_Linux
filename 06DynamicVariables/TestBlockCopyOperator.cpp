//
// Created by allen on 22-5-13.
//
#include <iostream>
#include "blockCopyOperator.h"
#include "testMoveExample.h"
int main(){
    {
        BigClass bigdata;          //It's Okay
        MoveConstruct test;
        std::cout << "  - - - " << std::endl;
        MoveConstruct test1 = test;
        std::cout << "  - - - " << std::endl;
        MoveConstruct test5 = MoveConstruct();
        std::cout << "  - - - " << std::endl;
        MoveConstruct test2(test1);
        auto get = []() {
//        return std::move(MoveConstruct());
            return MoveConstruct();
        };
        std::cout << "  - - - " << std::endl;
        MoveConstruct test3(get());
        std::cout << "  - - - " << std::endl;
        test3.a = 20;
        MoveConstruct test4 = std::move(test);
        std::cout << " Num :" << test3.a << "\t" << test4.a << std::endl;
    }
    std::string str1 = "Hello";
    std::string str2 (MoveExample(std::move(str1)));
}