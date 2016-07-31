#include "adjacency_matrix.h"
#include <algorithm>
#include <stack>

AdjacencyMatrix::AdjacencyMatrix()
    : d_graph()
{
    
}

AdjacencyMatrix::AdjacencyMatrix(const int v)
    : d_graph()
{
    d_graph.resize(v);
    std::vector<int> p(v, 0);
    for (int i = 0; i < v; ++i)
    {
        d_graph[i] = p;
    }
}

void AdjacencyMatrix::AddEdge(const int v, const int e)
{
    if (v < d_graph.size() && e < d_graph.size())
    {
        d_graph[v][e] = 1;
    }
}

int AdjacencyMatrix::IsEdge(const int v, const int e)
{
    if (v < d_graph.size() && e < d_graph.size())
    {
        return d_graph[v][e];
    }
    return 0;
}


//Depth first search
int AdjacencyMatrix::NumberOfPaths(const int v, const int e)
{
    Point p (0,0);
    std::stack<Point> s;
    s.push(p);
    int paths = 0;
    while (!s.empty())
    {
        Point p = s.top();
        s.pop();
        
        if (p.v == v && p.e == e)
        {
            ++paths;
        }
        
        //Add more paths.
        if (p.v+1 < d_graph.size() && d_graph[p.v+1][p.e] == 1)
        {
            s.push(Point(p.v+1,p.e));
        }
        if (p.e+1 < d_graph.size() && d_graph[p.v][p.e + 1] == 1)
        {
            s.push(Point(p.v, p.e+1));
        }
    }
    return paths;
}

std::ostream & operator<<(std::ostream & os, const AdjacencyMatrix & m)
{
    for (unsigned int i = 0; i < m.d_graph.size(); ++i)
    {
        for (unsigned int j = 0; j < m.d_graph[i].size(); ++j)
        {
            os << m.d_graph[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}