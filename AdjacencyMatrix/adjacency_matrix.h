#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <vector>
#include <iostream>

class AdjacencyMatrix
{
public:
    AdjacencyMatrix();
    AdjacencyMatrix(const int v);
    
    int NumberOfPaths(const int e, const int v);
    
    void AddEdge(const int v, const int e);
    int IsEdge(const int v, const int e);
    friend std::ostream & operator<< (std::ostream & os, const AdjacencyMatrix & m);
private:
    class Point
    {
    public:
        Point(const int x, const int y)
            : v(x)
            , e(y)
        { }
            
        int v;
        int e;
    };
    
    AdjacencyMatrix(const AdjacencyMatrix & m);
    AdjacencyMatrix & operator=(const AdjacencyMatrix & m);
    
    std::vector<std::vector<int> > d_graph;
};


#endif