//
//  main.cpp
//  SortCompare
//
//  Created by David Osollo on 3/24/19.
//  Copyright © 2019 David Osollo. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "CSortCompare.hpp"

int main(int argc, const char * argv[]) {
    
    CSortCompare CompareAlg;
    double time_taken;
    clock_t t;
    
    //CompareAlg.DisplayNumbers(0);
    
    printf("\nOrdenacion de %d Elementos\n ",ARRAY_SIZE_NUM);
    t = clock();
    CompareAlg.BubbleSort();
    //CompareAlg.DisplayNumbers(1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
    printf("\nBubbleSort() \t\tTiempo %f segundos\n", time_taken);

    
    t = clock();
    CompareAlg.InsertionSort();
    //CompareAlg.DisplayNumbers(1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    
    printf("InsertionSort() \tTiempo %f segundos\n", time_taken);
    
    t = clock();
    
    CompareAlg.quickSortCall();
    //CompareAlg.DisplayNumbers(1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("QuickSort() \t\tTiempo %f segundos\n", time_taken);
    
    t = clock();
    
    CompareAlg.heapSort();
    //CompareAlg.DisplayNumbers(1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("HeapSort() \t\tTiempo %f segundos\n", time_taken);
    
    t = clock();
    
    CompareAlg.mergeSortCall();
    //CompareAlg.DisplayNumbers(1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("MergeSort() \t\tTiempo %f segundos\n", time_taken);
    
    t = clock();
    
    CompareAlg.bucketSort();
    //CompareAlg.DisplayNumbers(1);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("BucketSort() \t\tTiempo %f segundos\n", time_taken);
    
    printf("\n");
    //CompareAlg.DisplayNumbers(1);
    
    return 0;
}
