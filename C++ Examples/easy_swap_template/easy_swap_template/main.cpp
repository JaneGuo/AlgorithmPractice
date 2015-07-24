//
//  main.cpp
//  easy_swap_template
//
//  Created by Jiancong Guo on 7/23/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>

template <class T>

void swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(int argc, const char * argv[])
{

    int a = 5;
    int b = 6;
    
    swap(a, b);
    std::cout<<"a is "<<a << " b is " << b <<std::endl;
    
    float m = 5.5;
    float n = 6.5;
    
    swap(m, n);
    std::cout<<"m is "<<m << " n is " << n <<std::endl;
    
    
    return 0;
}

