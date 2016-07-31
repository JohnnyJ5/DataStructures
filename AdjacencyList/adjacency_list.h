#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <list>
#include <iostream>

class AdjacencyList
{
public:
    AdjacencyList();
    AdjacencyList(const int v);
    
    int NumberOfPaths(const int e, const int v);
    
    void AddEdge(const int v, const int e);
    int IsEdge(const int v, const int e);
    friend std::ostream & operator<< (std::ostream & os, const AdjacencyList & m);
private:
    bool AdjacencyList::FindEdge(std::list<AdjacencyList::Vertex>::iterator & vertex, std::list<int>::iterator & edge, const int v, const int e);
    class Point
    {
    public:
        Point(int x, int y) : v(x), e(y) {}
        int v;
        int e;
    };
    class Vertex
    {
    public:
        Vertex(const int ver) : v(ver) {}
        int v;
        std::list<int> edges;
    };
    
    AdjacencyList(const AdjacencyList & m);
    AdjacencyList & operator=(const AdjacencyList & m);
    
    std::list<Vertex> d_graph;
};


#endif