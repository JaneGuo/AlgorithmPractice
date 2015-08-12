//
//  main.cpp
//  factorsOfNumber
//
//  Created by Jiancong Guo on 8/10/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//
/*
 Problem statement
 Given a number, find all its factors.
 
 Input
 First line of input will contain T = No. of test cases. Next T lines will each contain a number n such that 1<=n<=10^9.
 
 Output
 For each test case, print on a single line, a space separated list of all the factors of n in increasing order. There should be no space after last factor on each line.
 
 Sample Input
 4
 36
 48
 15
 19
 Sample Output
 1 2 3 4 6 9 12 18 36
 1 2 3 4 6 8 12 16 24 48
 1 3 5 15
 1 19
 
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void factorsOfaNumber(int n){
    vector<int> smallFactors;
    vector<int> largeFactors;
    
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            if(i == n/i)
                smallFactors.push_back(i);
            
            else{
                smallFactors.push_back(i);
                largeFactors.push_back(n/i);
            }
        }
        
    }
    while(!largeFactors.empty()){
        smallFactors.push_back(largeFactors.back());
        largeFactors.pop_back();
    }
    
    //cout<<smallFactors.front();
    vector<int>::iterator it = smallFactors.begin();
    cout<<*it;
    
    for(++it; it!= smallFactors.end(); it++){
        cout<<" "<<*it;
    }
    cout<<"\n";
}


int main(int argc, const char * argv[])
{
    // insert code here...
    int testCases;
    //cout<<"number of test cases";
    cin>>testCases;
    
    while(testCases-- >0){
        int number;
        cin>>number;
        
        factorsOfaNumber(number);
    }
    return 0;
}


//solution 2
#ifdef sol2
#include<iostream>
#include<cstdio>
#include<cmath>
#include <vector>

using namespace std;
int main()
{
    int test_case;
    cin >> test_case; //Number of test cases
    int num;
    vector<int> factors;
    while(test_case--){
        //Clear the current contents of the vector
        factors.clear();
        //Input the number
        cin >> num;
        //Run a loop until the square root of the number
        for(int i = 1; i <= sqrt(num); i++){
            //If the number is a perfect square, then we
            //count only 1 factor
            if(i*i == num){
                factors.push_back(i);
                break;
            }
            //If the current i is a factor of the number,
            //then we add both i and 'num/i' to the list of
            //factors.
            if(num%i == 0){
                factors.push_back(i);
                factors.push_back(num/i);
            }
        }
        //we sort the list of factors.
        sort(factors.begin(), factors.end());
        //In order to avoid printing space after the last number
        //we simply use a check condition.
        
        for(int i = 0; i< factors.size(); i++){
            if(i == factors.size() -1)
                cout << factors[i];
            else
                cout <<  factors[i] << " ";
        }
        //Then we print a newline at the end of each test case.
        cout << endl;
    }
}

#endif
