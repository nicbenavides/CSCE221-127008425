#ifndef MIN_HEAP_H
#define MIN_HEAP_H
#include<iostream>
#include<climits>
using namespace std;       

class MinHeap
{
  private:

    int *arr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of min heap 
    int heap_size; // Current number of elements in min heap

  public:

    // Constructor for the MinHeap
    MinHeap(int cap) {
        heap_size = 0; 
        capacity = cap; 
        arr = new int[cap]; 
    }

    // to ge the index of parent of node at index i
    inline int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    inline int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    inline int right(int i) { return (2*i + 2); } 

    // Returns the minimum key (key at root) from min heap 
    inline int getMin() {  return arr[0]; } 

    // Inserts a new key 'k' 
    void insertKey(int k) {
        // Remove below line after your implementation
		int index = 0;
        if(heap_size == capacity){
			cout << "OVERFLOW" << endl;
		}
		else{
			heap_size++;
			index = heap_size-1;
			arr[index] = k;
			
		}
		index = heap_size - 1;
		while(index !=0 && arr[parent(index)] > arr[index]){
			swap(&arr[index],&arr[parent(index)]);
			index = parent(index);
		}
    }
	void swap(int *a, int *b){
		int save = *a;
		*a = *b;
		*b = save;
	}
	void mheap(int i){
		int l = left(i);
		int r = right(i);
		int small = i;
		if(r < heap_size && arr[r] < arr[small]){
			small = r;
		}
		if(l < heap_size && arr[l] < arr[i]){
			small = l;
		}
		if (small != i){
			swap(&arr[i], &arr[small]);
			mheap(small);
		}
	}
    // Extract the root which is the minimum element 
    int extractMin(){
		if(heap_size == 1){
			heap_size--;
			return arr[0];
		}
        int rt = arr[0];
		arr[0] = arr[heap_size-1];
		heap_size--;
		mheap(0);
		return rt;
		
    }
	void print(){
		for(int i = 0; i < heap_size; i++){
			cout << arr[i] << endl;
		}
	}
  
    // Decreases key value of key at index i to newVal 
    void decreaseKey(int i, int newVal) {
        // Remove below line after your implementation
		arr[i] = newVal;
		while(i !=0 && arr[parent(i)] > arr[i]){
			swap(&arr[i], &arr[parent(i)]);
			i = parent(i);
		}
    }
  
    // Deletes a key stored at index i 
    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
		extractMin();
    }
};

#endif
