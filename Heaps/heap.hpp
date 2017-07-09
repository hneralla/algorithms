/** 
*  @file    heap.hpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of min-heap.
*/

#ifndef heap_hpp
#define heap_hpp

/**
*  @brief Class that represents an element in the heap.
*/  
class Element
{
private:
    int key;

public:
    // Accessor methods
    int getKey(){ return key; }
    void setKey(int k){ key = k; }
};

/**
*  @brief Class that defines a heap structure.
*/  
class Heap
{
private:
    int capacity;
    int size;
    Element *H;
    
public:
    // Constructor
    Heap(int capacity); 
    
    // Accessor methods
    int getCapacity(){ return capacity; }
    int getSize(){ return size; }
    void setSize(int s){ size = s; }
    int getParent(int index);
    
    // Heap functions
    Heap Initialize(int n);
    void BuildHeap(Heap heap, Element *A);
    Heap Insert(Heap heap, int key);
    int DeleteMin(Heap heap);
    void DecreaseKey(Heap heap, int index, int value);
    void printHeap(Heap heap);
};

/**
*   @brief  Implementation of Heapify algorithm
*  
*   @param  Element object array, index from where
*           to start algorithm, and size (no. of elements)
*           in the heap.
*   @return nothing
*/  
void Heapify(Element *A, int index, int size);

#endif /* heap_hpp */