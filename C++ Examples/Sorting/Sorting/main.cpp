//
//  main.cpp
//  Sorting
//
//  Created by Jiancong Guo on 7/26/15.
//  Copyright (c) 2015 Jiancong Guo. All rights reserved.
//

#include <iostream>
/*
 Selection Sort, bubble sort, and insertion sort are not import, as big O of n^2. Memory O(1)
 Merge Sort, and Quick Sort are more important. 
 Merge Sort have a average and worst case O(n log(n)), Memory: Depends
 Quick Sort have a average of nlog(n), MAX n^2, Memory: O( log(n) )  Unstable sort
 */


//Selection Sort
// n is the length of array A
// big O of n^2
template <class T>
void SelectionSort(T A[], int n){
    for(int i=0; i<= n-2; i++){
        int iMin = i;
        for(int j=i; j<= n-1; j++){
            if(A[j] < A[iMin])
                iMin = j;
        }
        T temp = A[i];
        A[i] = A[iMin];
        A[iMin]= temp;
        
    }
}


//Bubble Sort
// Big O of n^2, stable sorting
template <class T>
void BubbleSort(T A[], int n){
    for(int j=1; j<= n-1; j++){
        int flag = 0;
        for(int i=0; i<= n-j-1;i++){
            if(A[i]> A[i+1]){
                flag = 1;
                T temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
            }
        }
        if(flag == 0)
            break;
    }
}


// Insertion Sort

void InsertionSort(int A[], int n){
    for(int i = 1; i<= n-1; i++){
        int value = A[i];
        int hole = i;
        while( hole > 0 && A[hole -1]>value){
            A[hole] = A[hole -1];
            hole--;
        }
        A[hole] = value;
    }
}



template <class T>
void print(T A[], int n){
    for(int i = 0; i<= n -1; i++){
        std::cout<< A[i]<<'\t';
    }
    std::cout<<std::endl;
    
}

//Merge sort
void merge(int a[], int size1, int size2){
    int temp[size1+size2];
    int index1 = 0, index2 = 0;
    while((index1 < size1 && index2 <= size2)){
        if(a[index1]<=a[size1+index2]||index2 == size2){
            temp[index1 + index2] = a[index1];
            //std::cout<<"first coping "<<ptr1 << " element to temp. the value is "<<a[ptr1]<<std::endl;
            index1++;
        }
        else if(a[index1]>a[size1+index2]){
            temp[index1 + index2] = a[size1 + index2];
            //std::cout<<"second coping "<<size1 + ptr2<< " element to temp . the value is "<<a[size1 + ptr2]<<std::endl;
            index2++;
        }
    }
    for(int i = 0; i<size1 + index2; i++){
        a[i] = temp[i];
    }
}
void mergeSort(int a[], int size){
    if(size <= 1)
        return;
    int size1 = size/2;
    int size2 = size - size/2;
    mergeSort(a, size1);
    mergeSort(a+size1,size2);
    merge(a, size1, size2);
}

//Quick Sort
int partition(int a[], int start, int end);
void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void quickSort(int a[], int start, int end){
    if(start >= end)
        return;
    int partitionIndex = partition(a, start, end);
    quickSort(a, start, partitionIndex -1);
    quickSort(a, partitionIndex + 1, end);
}

int partition(int a[], int start, int end){
    int pivot = a[end];
    int partitionIndex = start;
    for(int i = start; i<end; i++){
        if(a[i] < pivot){
            //swap a[i] and a[partitionIndex]
            swap(a, i, partitionIndex);
            partitionIndex++;
        }
    }
    swap(a, end, partitionIndex);
    return partitionIndex;
}


int main(int argc, const char * argv[])
{
    int myarray[] = {3,8,7,2,6,5,4,2,4};
    mergeSort(myarray, sizeof(myarray)/sizeof(int));
    std::cout<<"merge sort result: ";
    print(myarray, sizeof(myarray)/sizeof(int));
    
    quickSort(myarray, 0, sizeof(myarray)/sizeof(int)-1);
    std::cout<<"quick sort result: ";
    print(myarray, sizeof(myarray)/sizeof(int));
    
    return 0;
}

