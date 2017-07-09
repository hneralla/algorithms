/** 
*  @file    graph.hpp
*  @author  Harith Neralla
*  @date    7/8/2017  
*  @version 1.0 
*  
*  @brief Implementation of directed graphs.
*/

#include <vector>

#ifndef graph_hpp
#define graph_hpp

/**
*  @brief Class that represents a node in the graph.
*/  
class Node
{
public:
    
    std::vector< std::pair<int, int> > adjacencyList;
    
    unsigned int getDest(int index){ return adjacencyList[index].first; };
    unsigned int getWght(int index){ return adjacencyList[index].second; };
};

/**
*  @brief Class that defines a graph structure.
*/  
class Graph
{
private:
    int numOfVertices;
    int numOfEdges;

public:
    Node *A;
    
    // Accessor methods
    int getNumOfVertices() { return numOfVertices; }
    int getNumOfEdges() { return numOfEdges; }

    // Write graph to console
    void writeGraph(Graph graph);
    
    Graph(int V, int E);
};

#endif /* graph_hpp */