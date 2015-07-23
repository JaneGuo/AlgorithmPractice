//
//  main.cpp
//  Easy_Sum number Temple
//
//  Created by Jiancong Guo on 7/23/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>

template <class T>
T sum(const T c_array[], int size, T sum =0){
    for(int i = 0; i<size; i++){
        sum += c_array[i];
    }
    return sum;
    
}
int main(int argc, const char * argv[])
{

    int a[] = {1,2,3,4,5};
    std::cout<< "sum of array elements is "<<sum(a,5)<<std::endl;
    
    float b[] = {1.1, 2.1, 3.1, 4.1, 5.1};
    std::cout<< "sum of array elements is "<< sum(b, 5)<<std::endl;
    
    return 0;
}

