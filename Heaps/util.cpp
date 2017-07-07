#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "heap.hpp"
using namespace std;

void stop()
{
    // Exit program
    exit(0); 
}

Heap read(Heap heap, string fileName)
{
    ifstream inFile;
    int n;
    int key;
    
    // Open file
    inFile.open(fileName.c_str()); //opens file
        
    if (inFile.is_open()) 
    {
        inFile >> n ;   

        // Check if input array size is larger than capacity
        if (n > heap.getCapacity()) 
            heap = heap.Initialize(n);

        heap.setSize(n);
        
        Element *A = new Element[n];
        
        // Read input file
        for (int index = 0; index < n; index++) 
        {
            inFile >> key;
            A[index].setKey(key); 
        }
    
        inFile.close(); 
        
        heap.BuildHeap(heap, A);
        
        cout << "Data read. Enter 'P' to view Menu" << endl;
        return heap;
        
    }else
    {
        cout << "NOT READ";
        cout << "\nEnter 'P' to view Menu" << endl;
        return Heap(0);
    }
}













