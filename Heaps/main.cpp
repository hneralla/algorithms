#include <iostream>
#include <cstring>
#include "main.hpp"
#include "heap.hpp"
#include "util.hpp"
using namespace std;

int main()
{
    char h;
    Heap heap = Heap(0); // Create an empty heap with capacity 0
    int n;
    int key;
    int index;
    int value;
    bool initialized = false; // Boolean value to track whether heap has been initialized
    
    cout << "\n\tWelcome to Project 02: Implementing Heap Data Structure" << endl;
    printMenu();
    
    while (strcmp(&h, "S") != 0)
    {
        // Read user input
        cin >> h; 
        
        switch (h)
        {
            // Stop program
            case 'S':
                stop(); 
            
            // Initialize heap
            case 'C': 
                cout << "Enter a number: " << endl;
                cin >> n;
                heap = heap.Initialize(n);
                initialized = true;
                cout << "Heap created. Enter 'P' to view Menu\n" << endl;
                break;
            
            // Read input data
            case 'R': 
                if(initialized)
                {
                    heap = read(heap, "HEAPinput.txt");
                }else
                {
                    cout << "Heap not created. Please create heap before entering other commands. \nEnter 'P' to view Menu\n" << endl;
                }
                break;
                
            // Print heap contents     
            case 'W': 
                if(initialized)
                {
                    heap.printHeap(heap);
                    cout << "\nEnter 'P' to view Menu" << endl;
                }else
                {
                    cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << endl;
                }
                break;
                
            // Insert key
            case 'I': 
                if(initialized)
                {
                    cout << "Enter a number: " << endl;
                    cin >> key; 
                    if(heap.getSize() < heap.getCapacity())
                    {
                        heap = heap.Insert(heap, key);
                        cout << "Element inserted. Enter 'P' to view Menu\n" << endl;
                    }else{
                        cout << "Could not Insert Key. Heap is full\n" << endl;
                    }
                }else
                {
                    cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << endl;
                }
                break;
                
            // Delete minimum element (returns key of deleted element)  
            case 'D': 
                if(initialized)
                {
                    // Check if heap is empty
                    if(heap.getSize() < 1)
                    {
                        cout << "Heap underflow\nEnter 'P' to view Menu\n" << endl;
                    }else
                    {
                        cout << heap.DeleteMin(heap) << " was deleted. Enter 'P' to view Menu\n" << endl;

                        // Decrement heap size 
                        if(heap.getSize() > 0)
                            heap.setSize(heap.getSize()-1); 
                    }
                }else
                {
                    cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << endl;
                }
                break;
                
            // Decrease key    
            case 'K': 
                if(initialized)
                {
                    cout << "Enter a two numbers: " << endl;
                    cin >> index;
                    cin >> value;

                    if(index > 0) 
		            {
                        heap.DecreaseKey(heap, index-1, value); 
                    }else
                        cout << "Invalid index. Enter 'P' to view Menu\n" << endl;
                }else
                {
                    cout << "Heap not created. Please create heap before entering other commands.\nEnter 'P' to view Menu\n" << endl;
                }
                break;
            
            case 'P':
                printMenu();
                break;
        }
    }
   
    return 0;
}

void printMenu()
{
    cout << "\nEnter any of the following commands: \n" << endl;
    cout << "'C' : Followed by a number 'n', to create a heap with capacity 'n'" << endl;
    cout << "'R' : Read from file 'HEAPinput.txt'" << endl;
    cout << "'W' : Print heap contents" << endl;
    cout << "'I' : Followed by a number 'k', to insert element with key value 'k'" << endl;
    cout << "'D' : Deletes minimum element in heap" << endl;
    cout << "'K' : Followed by numbers 'i' and 'v', to decrease the key at index 'i' to value 'v'" << endl;
    cout << "'S' : Stop program.\n" << endl;
}









