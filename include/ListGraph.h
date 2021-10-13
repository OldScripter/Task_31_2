#ifndef TASK_31_2_LISTGRAPH_H
#define TASK_31_2_LISTGRAPH_H

#include "IGraph.h"

class ListGraph : public IGraph {

public:

    ListGraph(){std::cout << "List Graph is created.\n";};
    ListGraph& operator=(IGraph& other);
    ListGraph(IGraph* other);
    ListGraph(ListGraph* other);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    /**
     * @metod Get the adjacency list.
     * @return [out] adjacencyList std::map
     */
    std::map<int, std::vector<int>>* getAdjacencyList();
    /**
     * @metod Get all edges as vertex pairs 'from - to' and return them as pointer to allocated vector.
     * @return [out] edges std::vector
     */
    std::vector<std::pair<int, int>>* getEdges() override;
    /**
     * @method Prints the all edges in format 'from - to' into console.
     */
    void printEdges() override;

    void getListFromMatrix(IGraph* matrixGraph);

private:
    std::map<int, std::vector<int>> adjacencyList;
};

#endif //TASK_31_2_LISTGRAPH_H