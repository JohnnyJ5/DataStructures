#include "adjacency_list.h"
#include <iostream>

int main()
{
    AdjacencyList l;
    l.AddEdge(0,0);
    l.AddEdge(0,1);
    for(int i = 0; i < 4; ++i)
    {
        l.AddEdge(2,i);
    }
    
    std::cout << "Adjacency List: " << std::endl;
    std::cout << l << std::endl;
    std::cout << "IsEdge(0,1): " << l.IsEdge(0,1) << std::endl;
    std::cout << "IsEdge(1,1): " << l.IsEdge(1,1) << std::endl;
    std::cout << "Number Of Paths to (2,3): " << l.NumberOfPaths(2,3) << std::endl;
    
    return 0;
}