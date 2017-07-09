/** 
*  @file    util.cpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of directed graphs.
*/

#include <fstream>
#include <iostream>

#include "graph.hpp"
#include "util.hpp"

/**
*   @brief  Stop the program.
*/  
void stop()
{
    // Exit program
    exit(0); 
}

/**
*   @brief  Reads graph contents from input file. 
*  
*   @param  fileName: string
*   @return newly updated graph 
*/ 
Graph read(std::string fileName)
{
    int numOfVertices;
    int numOfEdges;
    int source;
    int destination;
    int weight; 
    std::ifstream inFile;
    Graph graph = Graph(0,0);
    
    inFile.open(fileName.c_str()); 
    
    if (inFile.is_open())  
    {
        inFile >> numOfVertices ;   
        inFile >> numOfEdges;       
        
        graph = Graph(numOfVertices, numOfEdges);
        
        // Store data in adjacency list
        for (int index = 0; index < graph.getNumOfEdges(); index++)
        {
            inFile >> source;
            inFile >> destination;
            inFile >> weight;
            graph.A[source - 1].adjacencyList.push_back(std::make_pair(destination - 1, weight)); 
        }
        
        inFile.close();
        std::cout << "\nGraph has been read.\n" << std::endl;

    }else
    {
        std::cout << "ERROR: GRAPHinput.txt does not exist." << std::endl;
    }
    
    return graph;
}