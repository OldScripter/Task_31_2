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
    void setVerticesCount(int dimensions);
    int getVerticesCount() const;
    bool getEdge(int from, int to) const;
    void setEdge(int from, int to, bool value);
    void printMatrix();
    void clearMatrix();

private:
    std::vector<std::vector<bool>> matrix;
};

#endif //TASK_31_2_ADJACENCYMATRIX_H