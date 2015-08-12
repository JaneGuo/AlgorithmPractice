//
//  main.cpp
//  decimalToBinary_codeSchedule_Math4
//
//  Created by Jiancong Guo on 8/2/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

/*
 Problem statement
 Given a number n, convert the number to its binary representation.
 
 Input
 First line of input will contain T = number of test case. Next T lines will each have a number n. n will be between 0 and 1000000000 (10^9)
 
 Output
 For each number print its binary form on a single line. There should be no leading zeroes in the result.
 
 Sample Input
 4
 5
 12
 25
 36
 Sample Output
 101
 1100
 11001
 100100
 */

#include <iostream>
#include <vector>
using namespace std;
//for this function we are only considering unsigned number.
//for signed number, if n<0 MSB binary digit is 1, otherwise is 1.
void decimalToBinary(unsigned long long decimal,vector<int>& a){
    
    if(decimal == 0)
        a.push_back(0);
    while(decimal > 0){
        a.push_back(decimal%2);
        decimal /= 2;
    }
    reverse(a.begin(), a.end()); //std::reverse
}

int main(int argc, const char * argv[])
{
    int testCases;
    //cout<<"number of test cases";
    cin>>testCases;
    
    while(testCases-- >0){
        long long number;
        cin>>number;
        if(number < 0){
            return -1;
        }
        vector<int> binary;
        decimalToBinary(number, binary);
        for(vector<int>::iterator it = binary.begin(); it!= binary.end(); it++)
            cout<<*it;
        cout<<endl;
    }
    
    return 0;
}

