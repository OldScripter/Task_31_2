#include <iostream>
#include "include/ListGraph.h"
#include "include/MatrixGraph.h"

int main() {

    //1. List graph test:
    std::cout << "\t - List graph creation:\n";
    ListGraph lGraph;

    //1.1 Setting the edges:
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

    //1.2 Check the List Graph functions:
    std::cout << "\t - Edges: \n";
    lGraph.printEdges();
    std::cout << "\t - Vertices count: " << lGraph.VerticesCount() << "\n";
    std::cout << "\t - From vertex 4 you can reach following vertices: ";
    std::vector <int> nextVertsFrom4{};
    lGraph.GetNextVertices(4, nextVertsFrom4);
    for (int i : nextVertsFrom4) std::cout << i << ' ';
    std::cout << "\n\t - Vertex 4 can be reached from following vertices: ";
    std::vector <int> prevVertsTo4{};
    lGraph.GetPrevVertices(4, prevVertsTo4);
    for (int i : prevVertsTo4) std::cout << i << ' ';
    std::cout << "\n";

    //1.3 Copying the List Graph to List Graph:
    std::cout << "\t - Making List Graph as a copy of List Graph:\n";
    ListGraph lGraphCopy (&lGraph);

    //1.4 Copying the IGraph to List Graph:
    std::cout << "\t - Making List Graph as a copy of IGraph:\n";
    IGraph* iGraph;
    iGraph = &lGraphCopy;
    ListGraph lGraphCopy2 = ListGraph(iGraph);

    //2. Matrix graph test:
    std::cout << "\t - Creation Matrix Graph as a copy of List graph:\n";
    MatrixGraph mGraph (iGraph);
    //2.1 Check the Matrix Graph functions:
    std::cout << "\t - The adjacency matrix of copied graph:\n";
    mGraph.getAdjacencyMatrix()->printMatrix();
    std::cout << "\t - Clearing the adjacency matrix:\n";
    mGraph.getAdjacencyMatrix()->clearMatrix();
    std::cout << "\t - Cleared adjacency matrix:\n";
    mGraph.getAdjacencyMatrix()->printMatrix();
    std::cout << "\t - Create edges in adjacency matrix:\n";
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
    std::cout << "\t - Updated adjacency matrix:\n";
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
    std::cout << "\t - Vertex 4 can be reached from following vertices: ";
    prevVertsTo4.clear();
    mGraph.GetPrevVertices(4, prevVertsTo4);
    for (int i : prevVertsTo4)
    {
        std::cout << i << ' ';
    }

    return 0;
}