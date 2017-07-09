/** 
*  @file    util.cpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of min-heap.
*/

#include <fstream>
#include <iostream>

#include "util.hpp"
#include "heap.hpp"

/**
*   @brief  Stop the program.
*/  
void stop()
{
    // Exit program
    exit(0); 
}

/**
*   @brief  Reads heap contents from input file. 
*  
*   @param  Heap object and input file name.
*   @return newly updated heap 
*/ 
Heap read(Heap heap, std::string fileName)
{
    int n; // Input heap size
    int key; // Heap element data
    std::ifstream inFile;
    
    // Open file
    inFile.open(fileName.c_str()); //opens file
        
    if (inFile.is_open()) 
    {
        inFile >> n;   

        // Check if input array size is larger than capacity
        if (n > heap.getCapacity()) 
        {
            heap = heap.Initialize(n);
        }

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
        
        std::cout << "Data read. Enter 'P' to view Menu" << std::endl;
        return heap;
        
    }
    else
    {
        std::cout << "NOT READ" << std::endl;
        std::cout << "\nEnter 'P' to view Menu" << std::endl;
        return Heap(0);
    }
}