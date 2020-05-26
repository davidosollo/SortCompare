//
//  CSortCompare.hpp
//  SortCompare
//
//  Created by David Osollo on 3/24/19.
//  Copyright © 2019 David Osollo. All rights reserved.
//

#ifndef CSortCompare_hpp
#define CSortCompare_hpp

#include <stdio.h>
#include <vector> 
#define ARRAY_SIZE_NUM 50000

struct bucket
{
    int count;
    int* value;
};


class CSortCompare
{
    int iArrayToSortGeneric[ARRAY_SIZE_NUM];
    int iArrayToSort[ARRAY_SIZE_NUM];
    void swap(int *xp, int *yp);
    void quickSort(int arr[], int low, int high);
    int  partition (int arr[], int low, int high);
    void heapify(int arr[], int n, int i);
    void merge(int arr[], int l, int m, int r);
    void mergeSort(int arr[], int l, int r);
    

public:
    CSortCompare();   // Constructor
    void DisplayNumbers(int iSort);
    void BubbleSort();
    void InsertionSort();
    void quickSortCall();
    void heapSort();
    void mergeSortCall();
    void bucketSort();
    
};


#endif /* CSortCompare_hpp */
