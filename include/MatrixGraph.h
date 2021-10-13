#ifndef TASK_31_2_MATRIXGRAPH_H
#define TASK_31_2_MATRIXGRAPH_H

#include "IGraph.h"
#include "AdjacencyMatrix.h"

class MatrixGraph : public IGraph {

public:

    MatrixGraph();
    ~MatrixGraph();
    MatrixGraph& operator=(IGraph& other);
    MatrixGraph(IGraph* Other);
    MatrixGraph(MatrixGraph* other);

    //Override:
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;
    /**
     * @method Get the pointer to adjacency matrix.
     * @return [out] adjacencyMatrix
     */
    AdjacencyMatrix* getAdjacencyMatrix();
    std::vector<std::pair<int, int>> * getEdges() override;
    void printEdges() override;
    void getMatrixFromList(IGraph* listGraph);

private:
    AdjacencyMatrix* adjacencyMatrix{};
};


#endif //TASK_31_2_MATRIXGRAPH_H