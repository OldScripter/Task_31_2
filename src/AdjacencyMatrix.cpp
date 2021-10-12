#include "../include/AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int dimensions)
{
    for (int h = 0; h < dimensions; ++h)
    {
        std::vector<bool>* v = new std::vector<bool>();
        for (int w = 0; w < dimensions; ++w)
        {
            v->push_back(false);
        }
        matrix.push_back(*v);
        delete v;
        v = nullptr;
    }
}

void AdjacencyMatrix::printMatrix()
{
    for (auto vector : matrix)
    {
        for (bool value : vector)
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}


AdjacencyMatrix::AdjacencyMatrix(AdjacencyMatrix *other)
{
    this->matrix = other->matrix;
}

AdjacencyMatrix &AdjacencyMatrix::operator=(const AdjacencyMatrix &other)
{
    this->matrix.clear();
    this->matrix = other.matrix;
    return *this;
}

void AdjacencyMatrix::setVerticesCount(int dimensions)
{
    if (matrix.size() < dimensions)
    {
        for (int i = matrix.size(); i < dimensions; ++i)
        {
            std::vector<bool>* v = new std::vector<bool>();
            matrix.push_back(*v);
            delete v;
            v = nullptr;
        }
        for (auto& vector : matrix)
        {
            while (vector.size() < dimensions)
            {
                vector.push_back(false);
            }
        }
    }
    else
    {
        std::cout << "New dimensions can\'t be less or equal to actual.\n";
    }
}

int AdjacencyMatrix::getVerticesCount() const
{
   return matrix.size();
}

bool AdjacencyMatrix::getEdge(int from, int to) const
{
    if (from > getVerticesCount() + 1 || to > getVerticesCount() + 1 || from < 1 || to < 1)
    {
        std::cerr << "Matrix error - wrong row or column\n";
        return false;
    }
    return (matrix[from - 1])[to - 1];
}

void AdjacencyMatrix::setEdge(int from, int to, bool value)
{
    if (from > getVerticesCount() + 1 || to > getVerticesCount() + 1 || from < 1 || to < 1)
    {
        std::cerr << "Matrix error - wrong row or column\n";
        return;
    }
    else
    {
        (matrix[from - 1])[to - 1] = value;
    }
}

void AdjacencyMatrix::clearMatrix()
{
    matrix.clear();
}
