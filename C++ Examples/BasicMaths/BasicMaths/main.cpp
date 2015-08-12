//
//  main.cpp
//  BasicMaths
//
//  Created by Jiancong Guo on 8/1/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

/*
 Problem statement
 Given the binary representation of a number, convert it to its decimal form.
 
 Input
 The first line will contain an integer T = number of test case. Next T lines will contain a string of size 1 to 30 characters representing the binary form of a number.
 
 Output
 For each string (binary form), print on a single line, the number in decimal number system.
 
 Sample Input
 4
 101
 100
 1011
 1111
 Sample Output
 5
 4
 11
 15
 */

#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
// Include headers as needed

using namespace std;

int main()
{
    // Write your code here
    int testCases;
    cout<<"type in number of test cases: ";
    cin>>testCases;
    
    while(testCases-- > 0){
        string binaryNumber; cin>>binaryNumber;
        //strings are read from left to right
        //however numbers are processed from right to left
        reverse(binaryNumber.begin(), binaryNumber.end());
        
        if(binaryNumber.size()>8){
            cout<<"out of range of int";
            return -1;
        }
        
        long decimalNumber = 0;
        int pow2 = 0;
        for(string::iterator it = binaryNumber.begin(); it!=binaryNumber.end(); it++){
            decimalNumber += pow(2, pow2)*(*it - '0');
            //cout<<"2^pow: " << pow<<"\t";
            pow2++;
        }
    }
    
    // Return 0 to indicate normal termination
    return 0;
}



