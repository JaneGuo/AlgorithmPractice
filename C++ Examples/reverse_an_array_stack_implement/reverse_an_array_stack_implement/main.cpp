//
//  main.cpp
//  reverse_an_array_stack_implement
//
//  Created by Jiancong Guo on 7/29/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
#include <stack> // stack from standard template library (STL)


//Time complexity is O(n)
//space complexity is O(n) which is not efficient
//swap for reverse is O(1)

/*
 Stack implementation of a linked list is good.
 */

void reverse(char C[], unsigned long n){
    std::stack<char> S;
    for(int i = 0; i<n; i++)
        S.push(C[i]);
    for(int i=0; i<n; i++){
        C[i] = S.top();
        S.pop();
    }
}

int main(int argc, const char * argv[])
{
    char C[51];
    std::cout<<"Enter a string: ";
    std::cin>>C;
    reverse(C, strlen(C));
    std::cout<< "reversed string: "<<C<<std::endl;
    return 0;
}

