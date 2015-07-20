//
//  main.cpp
//  array_stack
//
//  Created by Jiancong Guo on 7/19/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x){
    //overflow
    if(top == MAX_SIZE -1){
        printf("Error: stack overflow. \n");
        return;
    }
    A[++top]=x;
}

void Pop(){
    if(top == -1){
        printf("Error: no element to pop. \n");
        return;
    }
    top--;
}

int Top(){
    if(top == -1){
        printf("Error: stack is empty. \n");
        return -1;
    }
    return A[top];
}

bool IsEmpty(){
    if(top == -1) return true;
    return false;
}

void Print(){
    for(int i = 0; i<= top; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[])
{

    // insert code here...
    Push(2); Print();
    Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(12);Print();
    printf("%d\n",Top());
    printf("%s\n", IsEmpty()?"true":"false");
    
    return 0;
}

