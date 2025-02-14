#include<iostream>
#include<cmath>
#include<chrono>
#include"Sort.h"
#define Size 1000

int main()
{
    std::vector<int> v(Size);
    
    // initialize with some random number
    for( int i = 0; i < v.size(); i++)
        v[i] = i;

    std::cout<< "isSorted  ---- " <<  (isSorted(v)?"Passed": "Failed") << std::endl;
    
   for( int i = 0; i < v.size(); i++)
        v[i] = rand()%Size;
    bubbleSort(v);
    std::cout << "bubbleSort ---- " << 
        (isSorted(v)?"Passed":"Failed") << std::endl;

    for( int i = 0; i < v.size(); i++)
        v[i] = rand()%Size;
    selectionSort(v);
    std::cout << "selectionSort  ---- " << 
        (isSorted(v)?"Passed":"Failed") << std::endl;

    for( int i = 0; i < v.size(); i++)
        v[i] = rand()%Size;

    hybridSort(v);
    std::cout << "hybridSort---- " << 
        (isSorted(v)?"Passed":"Failed") << std::endl;


    for (int len= 1000; len< 10e6; len *= 10 )
    {
        std::cout << "%%%%%%%%%%%%%% Array size = " << len << "%%%%%%%%%%%%% "<< 
            std::endl;
        std::vector<int> vec(len);

        for( int i = 0; i < vec.size(); i++)
            vec[i] = rand()%vec.size();

        { // heapSort
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            heapsort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "heapSort ~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }

        { //MergeSort 
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            mergeSort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "mergeSort~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }



        { // hybrid
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            hybridSort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "hybridSort ~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }
        { // quicksort
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            quicksort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "quicksort~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }
		{ // bubblesort
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            bubbleSort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "bubblesort~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }
		{ // selectionsort
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            selectionSort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "selectionSort~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }
		{ // shellsort
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            shellsort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "shellsort~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }
		{ // insertionSort
            std::vector<int> v = vec;
            auto start = std::chrono::steady_clock::now();
            insertionSort(v);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapse_seconds = end-start;
            std::cout << "insertionsort~~~~~~"  << 
                elapse_seconds.count() << std::endl;
        }



    }

}

