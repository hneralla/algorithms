/** 
*  @file    main.cpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of min-heap.
*/

#include <iostream>
#include <cstring>

#include "main.hpp"
#include "heap.hpp"
#include "util.hpp"

/**
*   @brief  Main method. 
*/
int main()
{
    char userInput;
    Heap heap = Heap(0);
    int n; // Input heap size
    int key; // Heap element data
    int index;
    int value;
    bool initialized = false; // Boolean value to track whether heap has been initialized
    
    std::cout << "\n\tWelcome!" << std::endl;
    printMenu();
    
    while (strcmp(&userInput, "S") != 0)
    {
        std::cin >> userInput; 
        
        switch (userInput)
        {
            // Stop program
            case 'S':
            {
                stop(); 
            }
            
            // Initialize heap
            case 'C': 
            {
            	std::cout << "Enter a number: " << std::endl;
                std::cin >> n;
                heap = heap.Initialize(n);
                initialized = true;
                std::cout << "Heap created. Enter 'P' to view Menu\n" << std::endl;
                break;
            }
                
            // Read input data
            case 'R':
            {
            	if(initialized)
                {
                    heap = read(heap, "HEAPinput.txt");
                }
                else
                {
                    std::cout << "Heap not created. Please create heap before entering other commands. \nEnter 'P' to view Menu\n" << std::endl;
                }
                break;
            } 
                
            // Print heap contents     
            case 'W': 
            {
            	if(initialized)
                {
                    heap.printHeap(heap);
                    std::cout << "\nEnter 'P' to view Menu" << std::endl;
                }
                else
                {
                    std::cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << std::endl;
                }
                break;
            }
                            
            // Insert key
            case 'I': 
            {
            	if(initialized)
                {
                    std::cout << "Enter a number: " << std::endl;
                    std::cin >> key; 

                    if(heap.getSize() < heap.getCapacity())
                    {
                        heap = heap.Insert(heap, key);
                        std::cout << "Element inserted. Enter 'P' to view Menu\n" << std::endl;
                    }
                    else
                    {
                        std::cout << "Could not Insert Key. Heap is full\n" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << std::endl;
                }
                break;
            }
                
            // Delete minimum element (returns key of deleted element)  
            case 'D': 
            {
            	if(initialized)
                {
                    // Check if heap is empty
                    if(heap.getSize() < 1)
                    {
                        std::cout << "Heap underflow\nEnter 'P' to view Menu\n" << std::endl;
                    }
                    else
                    {
                        std::cout << heap.DeleteMin(heap) << " was deleted. Enter 'P' to view Menu\n" << std::endl;

                        // Decrement heap size 
                        heap.setSize(heap.getSize()-1); 
                    }
                }
                else
                {
                    std::cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << std::endl;
                }
                break;
            }   
                
            // Decrease key    
            case 'K':
            {
            	if(initialized)
                {
                    std::cout << "Enter a two numbers: " << std::endl;
                    std::cin >> index;
                    std::cin >> value;

                    if(index > 0) 
		            {
                        heap.DecreaseKey(heap, index - 1, value); 
                    }
                    else
                    {
                        std::cout << "Invalid index. Enter 'P' to view Menu\n" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << std::endl;
                }
                break;
            } 
                
            case 'P':
            {
            	printMenu();
                break;
            }
        }
    }
   
    return 0;
}

/**
*   @brief  Print menu contents. 
*/
void printMenu()
{
    std::cout << "\nEnter any of the following commands: \n" << std::endl;
    std::cout << "'C' : Followed by a number 'n', to create a heap with capacity 'n'" << std::endl;
    std::cout << "'R' : Read from file 'HEAPinput.txt'" << std::endl;
    std::cout << "'W' : Print heap contents" << std::endl;
    std::cout << "'I' : Followed by a number 'k', to insert element with key value 'k'" << std::endl;
    std::cout << "'D' : Deletes minimum element in heap" << std::endl;
    std::cout << "'K' : Followed by numbers 'i' and 'v', to decrease the key at index 'i' to value 'v'" << std::endl;
    std::cout << "'S' : Stop program.\n" << std::endl;
}