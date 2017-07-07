#include <math.h>
#include <iostream>
#include "heap.hpp"
using namespace std;

void Heapify(Element *A, int index, int size);

// Constructor
Heap::Heap(int c)
{
    capacity = c;
    H = new Element[c];
}

// Return the index of the parent of the given index
int Heap::getParent(int index)
{
    return floor((index-1)/2);
}

// Initialize the heap to the capacity n
Heap Heap::Initialize(int n)
{
    // Create a heap of capacity n
    Heap heap = Heap(n); 
    heap.setSize(0);
    return heap;
}

// Implementation of the BuildHeap algorithm
void Heap::BuildHeap(Heap heap, Element *A)
{    
    // Copies elements in A to heap.H
    for(int index = 0; index < heap.getSize(); index++)
        heap.H[index] = A[index]; 
    
    // Loop call of Heapify. Heapify is defined at the bottom of this file
    for(int index = floor(heap.getSize()/2); index >= 0; index--)
        Heapify(heap.H, index, heap.getSize());
}

// Implementation of the InsertKey algorithm
Heap Heap::Insert(Heap heap, int k)
{
    heap.setSize(heap.getSize() + 1); 
    int index = heap.getSize() - 1; 

    // Find where to insert the key
    while (index > 0 && heap.H[getParent(index)].getKey() > k)
    {
        // Swap element at index with its parent element
        heap.H[index] = heap.H[getParent(index)]; 
        index = getParent(index);
    }

    // Key is set to the element at index
    heap.H[index].setKey(k); 
    
    return heap;
}

// Delete the minimum element in the heap
int Heap::DeleteMin(Heap heap)
{
    // Variable to store minimum key
    int min; 
    
    min = heap.H[0].getKey(); // Set 'min' to the key of the first element in heap
    heap.H[0] = heap.H[heap.getSize()-1]; // Set the first element of heap to the last element in heap
    
    heap.setSize(heap.getSize()-1); 

    // Calls Heapify() on the modified heap
    Heapify(heap.H, 0, heap.getSize()); 
    
    return min;
}

// Implementation of IncreaseKey algorithm
void Heap::DecreaseKey(Heap heap, int index, int value)
{
    // Variable for swapping
    Element temp; 
    
    if(index > heap.getSize())
    {
        cout << "Index out of bounds. \nEnter 'P' to view Menu\n" << endl;
    }else
    {
        if(value > heap.H[index].getKey()) 
        {
            cout << "Error: new key is larger than current key" << endl;
        }
        else
        {
            heap.H[index].setKey(value); 
            
            // Maintain heap properties
            while(index > 0 && heap.H[getParent(index)].getKey() > heap.H[index].getKey())
            {
                // Swap element at index with its parent element
                temp = heap.H[getParent(index)];
                heap.H[getParent(index)] = heap.H[index];
                heap.H[index] = temp ;
                index = getParent(index);
            }
        }

	   cout << "Key decreased. Enter 'P' to view Menu\n" << endl;
    }
}

void Heap::printHeap(Heap heap)
{
    cout << "Heap Capacity: " << heap.capacity << endl;
    cout << "Heap Size: " << heap.size << endl;
    
    for (int index = 0; index < heap.getSize(); index++)
        cout << heap.H[index].getKey() << " "; 
    
    cout << endl;
}

// Implementation of the Heapify algorithm
void Heapify(Element *A, int index, int size)
{
    // Indices of left and right children
    int left = (2 * index) + 1; 
    int right = left + 1;  
    int smallest; 
    Element temp; // Variable for swapping
    
    // Check if left child is less than its parent
    if (left < size && A[left].getKey() < A[index].getKey()) 
        smallest = left;
    else
        smallest = index;
    
    // Check if right child is smaller than the element at 'smallest'
    if (right < size && A[right].getKey() < A[smallest].getKey()) 
        smallest = right;
    
    if (smallest != index)
    {
        // Swap element at 'index' and element at 'smallest'
        temp = A[smallest];
        A[smallest] = A[index];
        A[index] = temp;

        // Call Heapify() on modified heap
        Heapify(A, smallest, size); 
    }
}


