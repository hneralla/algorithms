/** 
*  @file    heap.cpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of min-heap.
*/

#include <math.h>
#include <iostream>

#include "heap.hpp"

/**
*   @brief  Default  constructor for Heap.  
*  
*   @param  c is an int that represent the
*           capacity.
*   @return nothing 
*/  
Heap::Heap(int c)
{
    capacity = c;
    H = new Element[c];
}

/**
*   @brief  Computes parent index. 
*  
*   @param  index: int
*   @return index of the parent
*/  
int Heap::getParent(int index)
{
    return floor((index-1)/2);
}

/**
*   @brief  Create a heap of capacity n.
*  
*   @param  int n is the capacity 
*   @return updated Heap object
*/  
Heap Heap::Initialize(int n)
{
    Heap heap = Heap(n); 
    heap.setSize(0);
    return heap;
}

/**
*   @brief  Implementation of the BuildHeap algorithm
*  
*   @param  Heap object and array of Element objects
*   @return nothing
*/  
void Heap::BuildHeap(Heap heap, Element *A)
{    
    // Copies elements in A to heap.H
    for(int index = 0; index < heap.getSize(); index++)
        heap.H[index] = A[index]; 
    
    // Loop call of Heapify. Heapify is defined at the bottom of this file
    for(int index = floor(heap.getSize()/2); index >= 0; index--)
        Heapify(heap.H, index, heap.getSize());
}

/**
*   @brief  Implementation of the InsertKey algorithm
*  
*   @param  Heap object and key to insert
*   @return updated Heap object
*/  
Heap Heap::Insert(Heap heap, int key)
{
    heap.setSize(heap.getSize() + 1); 
    int index = heap.getSize() - 1; 

    // Find where to insert the key
    while (index > 0 && heap.H[getParent(index)].getKey() > key)
    {
        // Swap element at index with its parent element
        heap.H[index] = heap.H[getParent(index)]; 
        index = getParent(index);
    }

    // Key is set to the element at index
    heap.H[index].setKey(key); 
    
    return heap;
}

/**
*   @brief  Delete the minimum element in the heap
*  
*   @param  Heap object
*   @return Key of minimum heap element
*/  
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

/**
*   @brief  Implementation of the DecreaseKey algorithm
*  
*   @param  Heap object, key to insert, index at where to insert
*   @return nothing
*/  
void Heap::DecreaseKey(Heap heap, int index, int value)
{
    // Variable for swapping
    Element temp; 
    
    if(index > heap.getSize())
    {
        std::cout << "Index out of bounds. \nEnter 'P' to view Menu\n" << std::endl;
    }
    else
    {
        if(value > heap.H[index].getKey()) 
        {
            std::cout << "Error: new key is larger than current key" << std::endl;
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

	   std::cout << "Key decreased. Enter 'P' to view Menu\n" << std::endl;
    }
}

/**
*   @brief  Print heap contents. 
*/
void Heap::printHeap(Heap heap)
{
    std::cout << "Heap Capacity: " << heap.capacity << std::endl;
    std::cout << "Heap Size: " << heap.size << std::endl;
    
    for (int index = 0; index < heap.getSize(); index++)
    {
        std::cout << heap.H[index].getKey() << " "; 
    }
    
    std::cout << std::endl;
}

/**
*   @brief  Implementation of Heapify algorithm
*  
*   @param  Element object array, index from where
*           to start algorithm, and size (no. of elements)
*           in the heap.
*   @return nothing
*/  
void Heapify(Element *A, int index, int size)
{
    // Indices of left and right children
    int left = (2 * index) + 1; 
    int right = left + 1;  
    int smallest; 
    Element temp; // Variable for swapping
    
    // Check if left child is less than its parent
    if (left < size && A[left].getKey() < A[index].getKey()) 
    {
        smallest = left;
    }
    else
    {
        smallest = index;
    }
    
    // Check if right child is smaller than the element at 'smallest'
    if (right < size && A[right].getKey() < A[smallest].getKey()) 
    {
        smallest = right;
    }
    
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