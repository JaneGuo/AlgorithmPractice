//
//  main.cpp
//  binary_search
//
//  Created by Jiancong Guo on 7/24/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
#include <vector>

/*
 In binary search, we look for element x in a sorted array.
 return index if the number is found;
 return -1 if the number is not found.
*/


int binarySearch(int a[], int length, int x){
   
    int start = 0;
    int end = length -1;
    int mid;
    
    while(start <= end){
        
        mid = start + (end -start)/2;
        if(a[mid] == x){
            std::cout<< "found the number in index "<<mid<<std::endl;
            return mid;
        }
        else if(x < a[mid])
            end = mid -1;
        else
            start = mid +1;
    }
    std::cout<<"Did not find the number. \n";
    return -1;
}

//binary search using recursion
int binarySearch2(int a[], int low, int high, int x){
    if(low > high){
        std::cout<<"binary search2: Did not find the number. \n";
        return -1;
    }
    int mid = low + (high - low)/2;
    if(x == a[mid]){
        std::cout<< "binary search2: found the number in index "<<mid<<std::endl;
        return mid;
    }
    else if(x < a[mid])
        return binarySearch2(a, low, mid -1, x);
    else
        return binarySearch2(a, mid + 1, high, x);
}

// find the first/ last occurrence of a number
// return -1 if the number is not found
// otherwise, return the index of first/ last occurrence of a number
// argument first is true to find first occurrence of a number, otherwise find last occurrence of a number
#ifdef macro
int binarySearch_first_last_occur(int a[], int length, int x, bool first){
    // to be finish
}
#endif


int main(int argc, const char * argv[])
{
    int myarray[] = {0,1,2,3,4,5,6,16,20,34,54,89};

    binarySearch(myarray, sizeof(myarray)/sizeof(int), -1);
    binarySearch2(myarray, 0, sizeof(myarray)/sizeof(int), 34);
    
    
    return 0;
}

