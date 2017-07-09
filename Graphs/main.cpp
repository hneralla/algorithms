/** 
*  @file    main.cpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of directed graphs.
*/

#include <cstring>
#include <iostream>

#include "graph.hpp"
#include "util.hpp"
#include "main.hpp"

/**
*   @brief  Main method. 
*/
int main()
{
    char userInput; 
    Graph graph = Graph(0,0); 
    
    bool notEmpty = false;
    
    std::cout << "\n\tWelcome!" << std::endl;

    printMenu();
    
    while (strcmp(&userInput, "S") != 0)
    {
        std::cin >> userInput; 
        
        switch(userInput)
        {
            case 'R':
            {
                graph = read("GRAPHinput.txt"); 
                std::cout << "Enter next command or 'M' for Menu." << std::endl;
                notEmpty = true;
                break; 
            }
                
            case 'W':
            {
                if (notEmpty)
                {
                    graph.writeGraph(graph); 
                }
                else
                {
                    std::cout << "Please read in graph data before entering other commands.\n" << std::endl;
                }
                
                std::cout << "Enter next command or 'M' for Menu." << std::endl;
                break;
            }
                
            case 'M': 
            {
                printMenu();
                break;
            }
                
            case 'S':
            {
                stop();
                break; 
            }   
                
            default: 
            {
                std::cout << "Invalid command. Make sure input is an uppercase character." << std::endl;
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
    std::cout << "\nEnter any of the following commands: \n"<< std::endl;
    std::cout << "'R' : Read from file 'GRAPHinput.txt'"    << std::endl;
    std::cout << "'W' : Print graph contents"               << std::endl;
    std::cout << "'S' : Stop program.\n"                    << std::endl;
}

