#include <iostream>
#include "include/ListGraph.h"
#include "include/MatrixGraph.h"
#include "include/AdjacencyMatrix.h"

int main() {
    ListGraph lGraph;
    lGraph.AddEdge(1,2);
    lGraph.AddEdge(1,3);
    lGraph.AddEdge(2,4);
    lGraph.AddEdge(3,4);
    lGraph.AddEdge(4,5);
    lGraph.AddEdge(4,8);
    lGraph.AddEdge(5,6);
    lGraph.AddEdge(5,7);
    lGraph.AddEdge(8,6);
    lGraph.AddEdge(8,2);
    lGraph.AddEdge(2,3);
    std::cout << "\t - Edges: \n";
    lGraph.printEdges();
    std::cout << "\t - Vertices count: " << lGraph.VerticesCount() << "\n";

    std::cout << "\t - From vertex 4 you can reach following vertices: ";
    std::vector <int> nextVertsFrom4{};
    lGraph.GetNextVertices(4, nextVertsFrom4);
    for (int i : nextVertsFrom4)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n";
    std::cout << "\t - Vertex 4 can be reached from following vertices: ";
    std::vector <int> prevVertsTo4{};
    lGraph.GetPrevVertices(4, prevVertsTo4);
    for (int i : prevVertsTo4)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n---------------\n";

    IGraph* iGraph;
    iGraph = &lGraph;

    ListGraph lGraph2 = ListGraph(iGraph);
    std::cout << "\n---------------\n";

    MatrixGraph mGraph;
    mGraph.AddEdge(1,2);
    mGraph.AddEdge(1,3);
    mGraph.AddEdge(2,4);
    mGraph.AddEdge(3,4);
    mGraph.AddEdge(4,5);
    mGraph.AddEdge(4,8);
    mGraph.AddEdge(5,6);
    mGraph.AddEdge(5,7);
    mGraph.AddEdge(8,6);
    mGraph.AddEdge(8,2);
    mGraph.AddEdge(2,3);

    mGraph.getAdjacencyMatrix()->printMatrix();
    std::cout << "\t - Edges: \n";
    mGraph.printEdges();
    std::cout << "\t - Vertices count: " << mGraph.VerticesCount() << "\n";
    std::cout << "\t - From vertex 4 you can reach following vertices: ";
    nextVertsFrom4.clear();
    mGraph.GetNextVertices(4, nextVertsFrom4);
    for (int i : nextVertsFrom4)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n";


    return 0;
}