#ifndef TASK_31_2_MATRIXGRAPH_H
#define TASK_31_2_MATRIXGRAPH_H

#include "IGraph.h"
#include "AdjacencyMatrix.h"

class MatrixGraph : public IGraph {

public:

    //Construction & destruction:
    MatrixGraph();
    ~MatrixGraph();
    MatrixGraph& operator=(IGraph& other);
    MatrixGraph& operator=(MatrixGraph& other);
    MatrixGraph(IGraph* Other);
    MatrixGraph(MatrixGraph* other);

    //Override:
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    std::vector<std::pair<int, int>> * getEdges() override;
    void printEdges() override;

    //Additional
    /**
    * @mathod Get edges from edges list of another graph and send them to adjacency matrix.
    * @param [in] IGraph* otherGraph
    */
    void getMatrixFromGraph(IGraph* otherGraph);
    /**
     * @method Get the pointer to adjacency matrix.
     * @return [out] adjacencyMatrix
     */
    AdjacencyMatrix* getAdjacencyMatrix();

private:

    AdjacencyMatrix* adjacencyMatrix{};
};

#endif //TASK_31_2_MATRIXGRAPH_H