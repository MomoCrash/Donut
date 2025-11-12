#include "Mesh.h"

#include <iostream>

#include "defines.h"

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

std::vector<Mesh::Vertex> const& Mesh::GetVertices()
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

void Mesh::GenerateCircle(float radius)
{
    float angle     = 360.0f/(float)m_resolution;
    for (float i = 0; i <= 360; i += angle)
    {
        for (int j = 0; j < m_resolution; j++)
        {
            float distance = (float)j * radius / (float)m_resolution;
            float x = distance*cos(i * PI /180);
            float y = distance*sin(i * PI /180);
            AddVertex(x, y, 0);
        }
    }
    
}

void Mesh::GenerateHalfCircle(float radius)
{
    float angle     = 360.0f/(float)m_resolution;
    for (float i = 0; i <= 180; i += angle)
    {
        for (int j = 0; j < m_resolution; j++)
        {
            float distance = (float)j * radius / (float)m_resolution;
            float x = distance*cos(i * PI /180);
            float y = distance*sin(i * PI /180);
            AddVertex(x, y, 0);
        }
    }
    
}

void Mesh::GenerateRectangle(float width, float height)
{
    for (int i = 0; i <= width; i++)
    {
        if (0 > i && i > m_resolution)  return;
        for (int j = 0; j <= height; j++)
        {
            if (0 > j && j > m_resolution)  return;
            float x = 2*(float)i/((float)m_resolution-1)-1;
            float y = 2*(float)j/((float)m_resolution-1)-1;
            m_vertices.emplace_back(x, y, 0);
        }
    }
}

void Mesh::GenerateSquare(float size)
{
    for (int i = 0; i <= size; i++)
    {
        if (0 > i && i > m_resolution)  return;
        for (int j = 0; j <= size; j++)
        {
            if (0 > j && j > m_resolution)  return;
            float x = 2*(float)i/((float)m_resolution-1)-1;
            float y = 2*(float)j/((float)m_resolution-1)-1;
            m_vertices.emplace_back(x, y, 0);
        }
    }
}
