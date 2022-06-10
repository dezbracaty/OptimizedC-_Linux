//
// Created by allen on 22-5-27.
//

#ifndef OPTIMIZEDC__LINUX_TESTMOVEEXAMPLE_H
#define OPTIMIZEDC__LINUX_TESTMOVEEXAMPLE_H
#include <iostream>
std::string MoveExample(std::string&& s) {
    printf("Address of S :\t , %d\n",&s);
    std::string tmp(std::move(s)); //  注意！现在s是空的
    std::cout<<"tmp :\t"<<tmp<<std::endl;
    printf("Address of tmp :\t , %d\n",&tmp);
    printf("Address of S :\t , %d\n",&s);
    return tmp;
    }
#endif //OPTIMIZEDC__LINUX_TESTMOVEEXAMPLE_H
