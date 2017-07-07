#ifndef heap_hpp
#define heap_hpp

class Element
{
private:
    int key;

public:
    // Accessor methods
    int getKey(){ return key; }
    void setKey(int k){ key = k; }
};

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
    Heap Insert(Heap heap, int k);
    int DeleteMin(Heap heap);
    void DecreaseKey(Heap heap, int index, int value);
    void printHeap(Heap heap);
};

#endif /* heap_hpp */