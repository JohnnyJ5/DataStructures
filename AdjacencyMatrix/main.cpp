

#include "adjacency_matrix.h"
#include <iostream>


int main()
{
//    AdjacencyMatrix m(10);
    
//    for (int i = 0; i < 10; ++i)
//    {
//        for (int j = 0; j < 10; ++j)
//        {
//            if (i % 2 == 0 && j % 2 == 0)
//            {
//                m.AddEdge(i,j);
//            }
//            else if (i % 2 == 1 && j % 2 == 1)
//            {
//                m.AddEdge(i,j);
//            }
//        }
//    }
    
    AdjacencyMatrix m (3);
    m.AddEdge(0,0);
    m.AddEdge(0,1);
    m.AddEdge(0,2);
    m.AddEdge(1,0);
    m.AddEdge(1,1);
    m.AddEdge(1,2);
    m.AddEdge(2,0);
    m.AddEdge(2,1);
    m.AddEdge(2,2);
    
    std::cout << "Adjacency Matrix: " << std::endl;
    std::cout << m << std::endl;
    
    std::cout << "Is there an edge for 0,1? : " << m.IsEdge(0,1) << std::endl;
    std::cout << "Is there an edge for 0,0? : " << m.IsEdge(0,0) << std::endl;
    std::cout << "Number of Paths to (2,2): " << m.NumberOfPaths(2,2) << std::endl;
    
    return 0;
}