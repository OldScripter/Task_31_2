#include "../include/MatrixGraph.h"

MatrixGraph::MatrixGraph(IGraph *Other) : IGraph(Other)
{
    auto otherMatrixGraph = dynamic_cast<MatrixGraph*>(Other);
    if (otherMatrixGraph)
    {
        std::cout << "Matrix Graph is copied.\n";
        this->adjacencyMatrix = otherMatrixGraph->getAdjacencyMatrix();
    }
    else
    {
        std::cout << "List Graph is copied (and converted to Matrix Graph).\n";
        getMatrixFromList(Other);
    }
}

MatrixGraph &MatrixGraph::operator=(IGraph &other)
{
    auto otherMatrixGraph = dynamic_cast<MatrixGraph*>(&other);
    if (otherMatrixGraph)
    {
        delete adjacencyMatrix;
        adjacencyMatrix = otherMatrixGraph->getAdjacencyMatrix();
    }
    else
    {
        delete adjacencyMatrix;
        getMatrixFromList(&other);
    }
    return *this;
}

void MatrixGraph::AddEdge(int from, int to)
{
    int verticesCount = std::max(from, to);
    if (adjacencyMatrix == nullptr) adjacencyMatrix = new AdjacencyMatrix();
    if (adjacencyMatrix->getVerticesCount() < verticesCount)
    {
        adjacencyMatrix->setVerticesCount(verticesCount);
    }

    adjacencyMatrix->setEdge(from, to, true);
}

int MatrixGraph::VerticesCount() const
{
    if (adjacencyMatrix == nullptr) return 0;
    return adjacencyMatrix->getVerticesCount();
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    if (adjacencyMatrix == nullptr) return;
    std::set<int> buffer {vertex};
    buffer.insert(vertex);
    bool newVertexDetected;
    do
    {
        newVertexDetected = false;
        for (auto from : buffer)
        {
            for (int to = 1; to < adjacencyMatrix->getVerticesCount() + 1; ++to)
            {
                if (adjacencyMatrix->getEdge(from, to) and to != vertex)
                {
                   if (buffer.insert(to).second)
                   {
                       newVertexDetected = true;
                   }
                }
            }
        }
    } while (newVertexDetected);

    buffer.erase(vertex);
    for (int i : buffer)
    {
        vertices.push_back(i);
    }
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    if (adjacencyMatrix == nullptr) return;
    std::set<int> buffer {vertex};
    buffer.insert(vertex);
    bool newVertexDetected;
    do
    {
        newVertexDetected = false;
        for (auto to : buffer)
        {
            for (int from = 1; from < adjacencyMatrix->getVerticesCount() + 1; ++from)
            {
                if (adjacencyMatrix->getEdge(from, to) and from != vertex)
                {
                    if (buffer.insert(from).second)
                    {
                        newVertexDetected = true;
                    }
                }
            }
        }
    } while (newVertexDetected);

    buffer.erase(vertex);
    for (int i : buffer)
    {
        vertices.push_back(i);
    }
}

AdjacencyMatrix *MatrixGraph::getAdjacencyMatrix()
{
    return adjacencyMatrix;
}

void MatrixGraph::getMatrixFromList(IGraph *listGraph) {
    if (adjacencyMatrix == nullptr)
    {
        adjacencyMatrix = new AdjacencyMatrix();
    }
    adjacencyMatrix->clearMatrix();
    for (auto pair : *(listGraph->getEdges()))
    {
        AddEdge(pair.first, pair.second);
    }
}

std::vector<std::pair<int, int>>* MatrixGraph::getEdges() {
    auto edgesVector = new std::vector<std::pair<int, int>>();
    if (adjacencyMatrix == nullptr) return nullptr;
    for (int i = 1; i < adjacencyMatrix->getVerticesCount() + 1; ++i)
    {
        for (int j = 1; j < adjacencyMatrix->getVerticesCount()+1; ++j)
        {
            if (adjacencyMatrix->getEdge(i, j))
            {
                edgesVector->push_back(std::make_pair(i, j));
            }
        }
    }
    return edgesVector;
}

MatrixGraph::MatrixGraph()
{
    std::cout << "AdjacencyMatrix Graph is created.\n";
    adjacencyMatrix = new AdjacencyMatrix();
}

void MatrixGraph::printEdges() {
    for (auto pair : *(getEdges()))
    {
        std::cout << "\t\t - " << pair.first << " : " << pair.second << "\n";
    }

}

MatrixGraph::~MatrixGraph()
{
    delete adjacencyMatrix;
}

MatrixGraph::MatrixGraph(MatrixGraph *other)
{
    if (adjacencyMatrix == nullptr)
    {
        adjacencyMatrix = new AdjacencyMatrix();
    }
    *(this->adjacencyMatrix) = *(other->adjacencyMatrix);
}
