#include "adjacency_list.h"
#include <algorithm>
#include <stack>

AdjacencyList::AdjacencyList()
    : d_graph()
{
    
}

bool AdjacencyList::FindEdge(std::list<AdjacencyList::Vertex>::iterator & vertex, std::list<int>::iterator & edge, const int v, const int e)
{
    vertex = d_graph.begin();
    for(; vertex != d_graph.end(); ++vertex)
    {
        if (vertex->v == v)
        {
            edge = vertex->edges.begin();
            for (; edge != vertex->edges.end(); ++edge)
            {   
                if (*edge == e)
                {
                    return true;
                }
            }
        }
    }
    return false;
     
}

void AdjacencyList::AddEdge(const int v, const int e)
{
    //Find the vertex in the adjacency list.
    std::list<Vertex>::iterator vertex;
    for(vertex = d_graph.begin(); vertex != d_graph.end(); ++vertex)
    {
        if (vertex->v == v)
        {
            break;
        }
    }
    
    if (vertex != d_graph.end())
    {
        //Vertex exists Look for duplicate edges
        std::list<int>::iterator edge = vertex->edges.begin();
        for (; edge != vertex->edges.end(); ++edge)
        {
            if (*edge == e)
            {
                break;
            }
        }
        
        //Edge doesn't exist so add it.
        if (edge == vertex->edges.end())
        {
            vertex->edges.push_back(e);
        }
    }
    else
    {
        //No node given so create one with the edge.
        Vertex node(v);
        node.edges.push_back(e);
        d_graph.push_back(node);
    }
    
}

int AdjacencyList::IsEdge(const int v, const int e)
{
    std::list<Vertex>::iterator vertex = d_graph.begin();
    for(; vertex != d_graph.end(); ++vertex)
    {
        if (vertex->v == v)
        {
            std::list<int>::iterator edge = vertex->edges.begin();
            for(; edge != vertex->edges.end(); ++edge)
            {
                if (*edge == e)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}


//Depth first search
int AdjacencyList::NumberOfPaths(const int v, const int e)
{
    Point p (0,0);
    return 1;
}

std::ostream & operator<<(std::ostream & os, const AdjacencyList & m)
{
    std::list<AdjacencyList::Vertex>::const_iterator vertex = m.d_graph.begin();
    for(; vertex != m.d_graph.end(); ++ vertex)
    {
        std::cout << "Vertex: " << vertex->v << " --- ";
        std::list<int>::const_iterator edge = vertex->edges.begin();
        for(; edge != vertex->edges.end(); ++edge)
        {
            std::cout << *edge << " ";
        }
        std::cout << std::endl;
    }
    return os;
}