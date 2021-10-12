#include "../include/ListGraph.h"

ListGraph::ListGraph(IGraph *other) : IGraph(other)
{
    auto otherListGraph = dynamic_cast<ListGraph*>(other);
    if (otherListGraph)
    {
        std::cout << "List Graph is copied.\n";
        this->adjacencyList = *(otherListGraph->getAdjacencyList());
    }
    else
    {
        //TODO AdjacencyMatrix based graph copy to ListGraph
        std::cout << "IGraph is copied to ListGraph.\n";
        /*auto vertices = other->getEdges();
        for (auto pair : *vertices)
        {
            auto it = adjacencyList.find(pair.first);
            if (it == adjacencyList.end())
            {
                std::vector<int> v {pair.second};
                adjacencyList.insert(std::make_pair(pair.first, v));
            }
            else
            {
                it->second.push_back(pair.second);
            }
        }*/
    }
}

ListGraph::ListGraph(ListGraph *other)
{
    std::cout << "List Graph is copied.\n";
    this->adjacencyList = *(other->getAdjacencyList());
}

ListGraph &ListGraph::operator=(const IGraph &other) {
    //TODO Operator= for ListGraph and Igraph
    return *this;
}

void ListGraph::AddEdge(int from, int to)
{
    auto it = adjacencyList.find(from);
    if (it == adjacencyList.end())
    {
        std::vector<int> vector_to{to};
        adjacencyList.insert(std::make_pair(from, vector_to));
    }
    else
    {
        it->second.push_back(to);
    }
}

std::map<int, std::vector<int>> *ListGraph::getAdjacencyList()
{
    return &adjacencyList;
}

int ListGraph::VerticesCount() const {
    std::set<int> vertices;
    for (const auto& it : adjacencyList)
    {
        vertices.insert(it.first);
        if (!it.second.empty())
        {
            for (int i : it.second)
            {
                vertices.insert(i);
            }
        }
    }
    return (int)vertices.size();
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const
{
    auto it = adjacencyList.find(vertex);
    if (it == adjacencyList.end()) return;

    std::set<int> buffer {vertex};
    bool newVertexDetected;
    do
    {
        newVertexDetected = false;
        for (auto v : buffer)
        {
            it = adjacencyList.find(v);
            if (it != adjacencyList.end())
            {
                for (int j : it->second)
                {
                    if (j != vertex && buffer.insert(j).second)
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

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const
{
    std::set<int> buffer {vertex};
    bool newVertexDetected;
    do
    {
        newVertexDetected = false;
        for (auto b : buffer)
        {
            for (const auto& v : adjacencyList)
            {
                for (int i : v.second)
                {
                    if (i == b)
                    {
                        if (buffer.insert(v.first).second)
                        {
                            newVertexDetected = true;
                        }
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

std::vector<std::pair<int, int>>* ListGraph::getEdges() {
    std::vector<std::pair<int,int>>* edges = new std::vector<std::pair<int,int>>();
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it)
    {
        if (!it->second.empty())
        {
            for (int i : it->second)
            {
                edges->push_back(std::make_pair(it->first, i));
            }
        }
        else
        {
            edges->push_back(std::make_pair(it->first, 0));
        }
    }
    return edges;
}

void ListGraph::printEdges()
{
    for (auto pair : *(getEdges()))
    {
        std::cout << "\t\t - " << pair.first << " : " << pair.second << "\n";
    }
}