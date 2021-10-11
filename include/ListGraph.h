#ifndef TASK_31_2_LISTGRAPH_H
#define TASK_31_2_LISTGRAPH_H

#include "IGraph.h"
#include "MatrixGraph.h"

class ListGraph : public IGraph {

public:
    ListGraph(){};
    ListGraph(std::map<int, std::vector<int>>& adjacencyList) : adjacencyList(adjacencyList){};
    ListGraph(IGraph* other);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    std::map<int, std::vector<int>>* getAdjacencyList();
    void getListFromMatrix(MatrixGraph* matrixGraph);

private:
    std::map<int, std::vector<int>> adjacencyList;
};


#endif //TASK_31_2_LISTGRAPH_H