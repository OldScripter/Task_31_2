#ifndef TASK_31_2_ADJACENCYMATRIX_H
#define TASK_31_2_ADJACENCYMATRIX_H

#include <vector>
#include <iostream>

class AdjacencyMatrix {

public:

    AdjacencyMatrix()= default;
    explicit AdjacencyMatrix(int verticesCount);
    explicit AdjacencyMatrix(AdjacencyMatrix* other);
    AdjacencyMatrix& operator= (const AdjacencyMatrix& other);
    /**
     * @method Set vertices count for the graph (set graph dimensions).
     * @param [in] int dimensions
     */
    void setVerticesCount(int dimensions);
    /**
     * @method Get the vertices count (graph dimensions).
     * @return [out] int dimensions
     */
    int getVerticesCount() const;
    /**
     * @method Get the edge status vertices 'from' 'to'.
     * @param [in] int from
     * @param [in] int to
     * @return [out] bool edge state (true if there is an edge between named vertices)
     */
    bool getEdge(int from, int to) const;
    /**
     * @method Set the edge between vertices 'from' and 'to'.
     * @param [in] int from
     * @param [in] int to
     * @param [in] bool value (true - to create the edge, false - to remove the edge)
     */
    void setEdge(int from, int to, bool value);
    /**
     * @method Print the adjacency matrix to console.
     */
    void printMatrix();
    /**
     * @method Clear the adjacency matrix.
     */
    void clearMatrix();

private:
    std::vector<std::vector<bool>> matrix;
};

#endif //TASK_31_2_ADJACENCYMATRIX_H