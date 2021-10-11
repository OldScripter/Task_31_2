#include "../include/ListGraph.h"

ListGraph::ListGraph(IGraph *other) : IGraph(other)
{
    auto otherListGraph = dynamic_cast<ListGraph*>(other);
    if (otherListGraph)
    {
        this->adjacencyList = *(otherListGraph->getAdjacencyList());
    }

    auto otherMatrixGraph = dynamic_cast<MatrixGraph*>(other);
    if (otherMatrixGraph)
    {
        getListFromMatrix(otherMatrixGraph);
    }



}

void ListGraph::AddEdge(int from, int to)
{
    auto it = adjacencyList.find(from);
    if (it == adjacencyList.end())
    {
        std::vector<int> to_vector {to};
        adjacencyList.insert(std::make_pair(from, to_vector));
        std::cout << "\t - Vertex " << from << " is created.\n";
        std::cout << "\t - Edge from " << from << " to " << to << " is created.\n";
    }
    else
    {
        for (int i : it->second)
        {
            if (i == to)
            {
                std::cout << "\t - Edge already exists!\n";
                return;
            }
        }
        it->second.push_back(to);
        std::cout << "\t - Edge from " << from << " to " << to << " is created.\n";
    }
}

std::map<int, std::vector<int>> *ListGraph::getAdjacencyList()
{
    return &adjacencyList;
}

int ListGraph::VerticesCount() const {
    return 0;
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    auto it = adjacencyList.find(vertex);
    if (it == adjacencyList.end())
        vertices.clear();
    else
    {
        for (int i : it->second)
        {
            vertices.push_back(i);
        }
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {

}

void ListGraph::getListFromMatrix(MatrixGraph *matrixGraph)
{

}
