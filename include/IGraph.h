#ifndef TASK_31_2_IGRAPH_H
#define TASK_31_2_IGRAPH_H

#include <vector>
#include <map>
#include <set>
#include <iostream>

class IGraph {

public:

    virtual ~IGraph(){};
    IGraph(){};
    IGraph(IGraph* other){};
    /**
     * @method Adds the edge between 2 vertices.
     * @param [in] from (int) From vertex
     * @param [in] to (int) To vertex
     */
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    /**
     * @method Returns the number of vertices in graph.
     * @return [out] verticesCount int
     */
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    /**
     * @method Get vertices that can be reached from named vertex and put them into vertices vector.
     * @param [in] vertex int
     * @param [out] vertices std::vector
     */
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    /**
     * @method Get vertices from which named vertex can be reached and put them into vertices vector.
     * @param [in] vertex int
     * @param [out] vertices std::vector
     */
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) const = 0; // Для конкретной вершины ме

    //Additional methods:
    virtual std::vector<std::pair<int,int>>* getEdges() = 0;
    virtual void printEdges() = 0;

};

#endif //TASK_31_2_IGRAPH_H