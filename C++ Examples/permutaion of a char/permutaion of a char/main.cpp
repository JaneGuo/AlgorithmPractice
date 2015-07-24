//
//  main.cpp
//  permutaion of a char
//
//  Created by Jiancong Guo on 7/23/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>

void swap(char &x, char &y){
    char temp;
    temp = x;
    x = y;
    y = temp;
}

/* 
 function to print permutaions of a char array
 This function takes 2 parameters
 1. the char array
 2. size of the char array
 */
void permute(char a[], int size){
    if(size <= 0){
        std::cout<<"no permutation. \n";
        return;
    }
    //print the original char array
    std::cout<<"permutation: "<<a<<std::endl;
    for(int i = 0; i < size; i++)
        for(int j = i+1; j < size; j++){
            swap(a[i],a[j]);
            std::cout<<"permutation: "<<a<<std::endl;
            swap(a[j],a[i]); //swap back
        }
}

int main(int argc, const char * argv[])
{

    char a[] = "ABCD";
    
    permute(a, 4);
    
    return 0;
}

