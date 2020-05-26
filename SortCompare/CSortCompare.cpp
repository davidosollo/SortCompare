//
//  CSortCompare.cpp
//  SortCompare
//
//  Created by David Osollo on 3/24/19.
//  Copyright © 2019 David Osollo. All rights reserved.
//

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string.h>
#include <vector> 

#include "CSortCompare.hpp"

////////////////////////////////////////////////////////
// Constructor: Fill Array with random integers
CSortCompare::CSortCompare()
{
    int i=0;
    srand((int)time(NULL));

    for(i=0; i<ARRAY_SIZE_NUM; i++)
    {
        iArrayToSortGeneric[i] = rand() % ARRAY_SIZE_NUM;
    }
}

////////////////////////////////////////////////////////
// Swap: Swap Numbers
void CSortCompare::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

////////////////////////////////////////////////////////
// BubbleSort: BubbleSort Algorithm
void CSortCompare::BubbleSort()
{
    int i, j;
    bool swapped;
    
    memcpy ( iArrayToSort, iArrayToSortGeneric, sizeof(int) * ARRAY_SIZE_NUM);
    for (i = 0; i < ARRAY_SIZE_NUM-1; i++)
    {
        swapped = false;
        for (j = 0; j < ARRAY_SIZE_NUM-i-1; j++)
        {
            if (iArrayToSort[j] > iArrayToSort[j+1])
            {
                swap(&iArrayToSort[j], &iArrayToSort[j+1]);
                swapped = true;
            }
        }
        
        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
    
}

////////////////////////////////////////////////////////
// InsertionSort: Insertion Sort Algorithm
void CSortCompare::InsertionSort()
{
    
    int i, key, j;
    memcpy ( iArrayToSort, iArrayToSortGeneric, sizeof(int) * ARRAY_SIZE_NUM);
    for (i = 1; i < ARRAY_SIZE_NUM; i++) {
        key = iArrayToSort[i];
        j = i - 1;
        
        /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
        while (j >= 0 && iArrayToSort[j] > key) {
            iArrayToSort[j + 1] = iArrayToSort[j];
            j = j - 1;
        }
        iArrayToSort[j + 1] = key;
    }
    
}

////////////////////////////////////////////////////////
// quickSortCall: Call Quick Sort Algorithm
void CSortCompare::quickSortCall()
{
    memcpy ( iArrayToSort, iArrayToSortGeneric, sizeof(int) * ARRAY_SIZE_NUM);
    quickSort(iArrayToSort, 0, ARRAY_SIZE_NUM-1);
}

////////////////////////////////////////////////////////
// partition: Call Quick Sort Algorithm This function
// takes last element as pivot, places
// the pivot element at its correct position in sorted
// array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right
// of pivot
int CSortCompare::partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

////////////////////////////////////////////////////////
// partition: The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low  --> Starting index,
// high  --> Ending index */
void CSortCompare::quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arr, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

////////////////////////////////////////////////////////
// heapify: heapify Part of the Heap Algorithm
void CSortCompare::heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
    
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

////////////////////////////////////////////////////////
// heapSort: heapSort Use Heap Sort Algoritghm
void CSortCompare::heapSort()
{
    memcpy ( iArrayToSort, iArrayToSortGeneric, sizeof(int) * ARRAY_SIZE_NUM);

    // Build heap (rearrange array)
    for (int i = ARRAY_SIZE_NUM / 2 - 1; i >= 0; i--)
        heapify(iArrayToSort, ARRAY_SIZE_NUM, i);
    
    // One by one extract an element from heap
    for (int i=ARRAY_SIZE_NUM-1; i>=0; i--)
    {
        // Move current root to end
        swap(&iArrayToSort[0], &iArrayToSort[i]);
        
        // call max heapify on the reduced heap
        heapify(iArrayToSort, i, 0);
    }
}

////////////////////////////////////////////////////////
// merge: Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void CSortCompare::merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

////////////////////////////////////////////////////////
// mergeSort: heapSort Use Heap Sort Algoritghm
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void CSortCompare::mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}

////////////////////////////////////////////////////////
// mergeSortCall: Call a merge Sort Algorithm
void CSortCompare::mergeSortCall()
{
    memcpy ( iArrayToSort, iArrayToSortGeneric, sizeof(int) * ARRAY_SIZE_NUM);
    mergeSort(iArrayToSort, 0, ARRAY_SIZE_NUM-1);
}

////////////////////////////////////////////////////////
// bucketSort: Bucket sort algorithm
void CSortCompare::bucketSort()
{
    
    int i, j;
    int count[ARRAY_SIZE_NUM];
    
    memcpy ( iArrayToSort, iArrayToSortGeneric, sizeof(int) * ARRAY_SIZE_NUM);
    
    for (i = 0; i < ARRAY_SIZE_NUM; i++)
        count[i] = 0;
    
    for (i = 0; i < ARRAY_SIZE_NUM; i++)
        count[iArrayToSort[i]]++;
    
    for (i = 0, j = 0; i < ARRAY_SIZE_NUM; i++)
        for(; count[i] > 0; (count[i])--)
            iArrayToSort[j++] = i;
    
}

////////////////////////////////////////////////////////
// DisplayNumbers: Display the algorithms
void CSortCompare::DisplayNumbers(int iSort)
{
    int i,j;
    j=1;
    int *pArray;
    
    if(iSort == 0)
    {
        pArray=iArrayToSortGeneric;
    }
    else
    {
        pArray=iArrayToSort;
    }
    
    for(i=0; i<ARRAY_SIZE_NUM; i++)
    {
        printf("%d ",pArray[i]);
        if(j==10)
        {
            printf("\n");
            j=1;
        }
        j++;
    }
    printf("\n");
    printf("\n");
   
}

