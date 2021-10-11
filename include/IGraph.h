#ifndef TASK_31_2_IGRAPH_H
#define TASK_31_2_IGRAPH_H

#include <vector>
#include <map>
#include <iostream>
//#include "MatrixGraph.h"
//#include "ListGraph.h"

//class MatrixGraph;
//class ListGraph;

class IGraph {

public:

    virtual ~IGraph(){};
    IGraph(){};
    IGraph(IGraph* other){};
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины ме

};


#endif //TASK_31_2_IGRAPH_H
