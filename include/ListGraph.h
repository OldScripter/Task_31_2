#ifndef TASK_31_2_LISTGRAPH_H
#define TASK_31_2_LISTGRAPH_H

#include "IGraph.h"

class ListGraph : public IGraph {

public:

    //Construction & destruction:
    ListGraph();
    ListGraph& operator=(IGraph& other);
    ListGraph& operator=(ListGraph& other);
    ListGraph(IGraph* other);
    ListGraph(ListGraph* other);

    //Override:
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    std::vector<std::pair<int, int>>* getEdges() override;
    void printEdges() override;

    //Additional
    /**
     * @mathod Get edges from edges list of another graph and send them to adjacency list.
     * @param [in] IGraph* otherGraph
     */
    void getListFromGraph(IGraph* otherGraph);
    /**
    * @metod Get the adjacency list.
    * @return [out] adjacencyList std::map
    */
    std::map<int, std::vector<int>>* getAdjacencyList();

private:

    std::map<int, std::vector<int>> adjacencyList;
};

#endif //TASK_31_2_LISTGRAPH_H