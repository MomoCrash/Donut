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
    
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for(int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = r * std::cos(theta);
            m_vertices[m_resolution * i + j].y = r * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
    
}

void Mesh::GenerateHalfCircle(float radius)
{
    GenerateCircle(radius, PI);
    
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        for(int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f*i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f*j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}

void Mesh::GenerateSquare(float size)
{
    GenerateRectangle(size, size);
}
