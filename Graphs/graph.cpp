/** 
*  @file    graph.cpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of directed graphs.
*/

#include <stdio.h>
#include <iostream>

#include "graph.hpp"

/**
*   @brief  Default  constructor for Graph.  
*  
*   @param  V is an int: number of vertices. 
*           E is an int; number of edges.
*
*   @return nothing 
*/  
Graph::Graph(int V, int E)
{
    numOfVertices = V;
    numOfEdges = E;
    A = new Node[V];
}

/**
*   @brief  Prints graph contents to console. 
*  
*   @param  graph
*   @return nothing 
*/  
void Graph::writeGraph(Graph graph)
{
    std::cout << std::endl << graph.getNumOfVertices() << " " << graph.getNumOfEdges() << std::endl;
    
    // Iterate through every vertex
    for (int i = 0; i < graph.getNumOfVertices(); i++) 
    {
        std::cout << i + 1 << " :";
        
        // Iterate through adjacency list
        for (long index = graph.A[i].adjacencyList.size()-1; index >= 0; index--) 
        {
            std::cout << " (" << graph.A[i].adjacencyList[index].first + 1     // Adding 1 because index starts from 1 on console
                 << " " << graph.A[i].adjacencyList[index].second << ")";
        }
        
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}