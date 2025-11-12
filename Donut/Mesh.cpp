#include "Mesh.h"

#include <iostream>

Mesh::Vertex::Vertex(float x, float y, float z) : x(x), y(y), z(z){}

void Mesh::Vertex::Debug()
{
    std::cout << "x:" << x << ", y:" << y << ", z:" << z << std::endl;
}

Mesh::Mesh(int resolution) : m_resolution(resolution)
{
}

void Mesh::AddVertex(float x, float y, float z)
{
    m_vertices.emplace_back(x, y, z);
}

void Mesh::AddVertex(Vertex v)
{
    m_vertices.emplace_back(v);
}

void Mesh::Debug()
{
    for (int i = 0; i < m_vertices.size(); i++)
    {
        m_vertices[i].Debug();
    }
}
