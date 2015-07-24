//
//  main.cpp
//  Fibonacci
//
//  Created by Jiancong Guo on 7/24/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>

int fibonacci(int n){
    return n<=1 ? n:(fibonacci(n-1)+fibonacci(n-2));
}

int main(int argc, const char * argv[])
{

    // insert code here...

    for(int i = 0; i<10; i++)
        std::cout<< "the fibonaccci of n is "<<fibonacci(i)<<std::endl;
        
    return 0;
}

