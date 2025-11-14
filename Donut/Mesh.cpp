#include "Mesh.h"

#include <iostream>

#include "defines.h"

Mesh::Vertex::Vertex(float x, float y, float z) : x(x), y(y), z(z){}

void Mesh::Vertex::Debug()
{
    std::cout << "x:" << x << ", y:" << y << ", z:" << z << std::endl;
}

Mesh::Mesh(Settings& settings) : m_resolution(settings.getResolution())
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

std::vector<Mesh::Vertex> const& Mesh::GetVertices() const
{
    return m_vertices;
}

void Mesh::Debug()
{
    for (int i = 0; i < m_vertices.size(); i++)
    {
        m_vertices[i].Debug();
    }
}

void Mesh::GenerateCircle(float radius, float angle)
{
    for (float i = 0; i < m_resolution; i++)
    {
        float r = (radius * i)/((float)m_resolution-1);
        for (int j = 0; j < m_resolution; j++)
        {
            float theta = (float)j * angle / ((float)m_resolution - 1);
            float x = r*cos(theta);
            float y = r*sin(theta);
            AddVertex(x, y, 0);
        }
    }
    
}

void Mesh::GenerateHalfCircle(float radius)
{
    GenerateCircle(radius, PI);
    
}

void Mesh::GenerateRectangle(float width, float height)
{
    for (int i = 0; i < m_resolution; i++)
    {
        for (int j = 0; j < m_resolution; j++)
        {
            float x = width*(float)i/((float)m_resolution-1);
            float y = height*(float)j/((float)m_resolution-1);
            m_vertices.emplace_back(x, y, 0);
        }
    }
}

void Mesh::GenerateSquare(float size)
{
    GenerateRectangle(size, size);
}
