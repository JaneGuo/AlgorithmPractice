//
//  main.cpp
//  primeNumber
//
//  Created by Jiancong Guo on 8/2/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

//simple way to find is a number is prime, complexity is log(n)
bool isPrime(unsigned int n){
    if(n < 2)
        return false;
    for(int i = 2; i<=sqrt(n) ; i++){
        if (n%i == 0)
            return false;
    }
    return true;
}

//Sieve of Eratosthenes
//find all prime number up to n
void PrimeNumbers(unsigned int n, unsigned int primes[]){
    
    //0 and 1 are not prime numbers
    primes[0]=0;
    primes[1]=0;
    
    for(int i = 2; i<=sqrt(n); i ++){
        if(primes[i]==1){
            for(int j = 2; i*j<=n; j++){
                primes[i*j]=0;
                //prime number as a factor
                //j is the multipler
            }
        }
        
    }
}

int main(int argc, const char * argv[])
{
#ifdef test1
    // insert code here...
    int testCases;
    cout<<"number of test cases";
    cin>>testCases;
    
    while(testCases-- >0){
        int number;
        cin>>number;
        
        if(isPrime(number) == false)
            cout<<"NOT PRIME\n";
        else
            cout<<"PRIME\n";
        
    }
#endif
     
    int n = 100;
    unsigned int primes[n+1];
    fill_n(primes, n+1, 1);
    PrimeNumbers(100, primes);
    
    cout<<"prime number are: ";
    for(int i =0; i<=n; i++){
        if(primes[i]==1)
            cout<<i<<" ";
    }
    cout<<endl;
    
    
    return 0;
}

