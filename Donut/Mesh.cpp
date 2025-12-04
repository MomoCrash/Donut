#include "Mesh.h"

#include <iostream>

#include "defines.h"

Mesh::Vertex::Vertex(float x, float y, float z) : x(x), y(y), z(z){}

void Mesh::Vertex::Rotate(float angle, Axis axis)
{

    float _cos = cos(angle);
    float _sin = sin(angle);

    switch (axis)
    {
        case Axis::X:
            {
                float _y = _cos * y - _sin * z;
                float _z = _sin * y + _cos * z;
                y = _y;
                z = _z;
                break;
            }
        case Axis::Y:
            {
                float _x = _cos * x - _sin * z;
                float _z = _sin * x + _cos * z;
                x = _x;
                z = _z;
                break;
            }
        case Axis::Z:
            {
                float _x =  _cos * x + _sin * y;
                float _y = -_sin * x + _cos * y;
                x = _x;
                y = _y;
            }
        
            
    }
}

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

void Mesh::Rotate(float angle, Axis axis)
{
    for (int i = 0; i < m_vertices.size(); i++)
    {
        m_vertices[i].Rotate(angle, axis);
    }  
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

void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
    for (float i = 0; i < m_resolution; i++)
    {
        float majorR = (2.f*PI * i)/((float)m_resolution-1);
        for (int j = 0; j < m_resolution; j++)
        {
            float minorR = (2.f*PI * j) / ((float)m_resolution - 1);
            for (int k = 0; k < m_resolution; k++)
            {
                float x = (majorRadius + minorRadius * cos(minorR)) * cos(majorR);
                float y = (majorRadius + minorRadius * cos(minorR)) * cos(majorR);
                float z = minorR * sin(minorR);
                AddVertex(x, y, z);
            }
        }
    }
}
