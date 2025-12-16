#include "Mesh.h"

#include <iostream>

#include "defines.h"
#include "Light.h"

Mesh::Vertex::Vertex(float x, float y, float z, float nx, float ny, float nz)
: x(x), y(y), z(z), nx(nx), ny(ny), nz(nz)
{
}

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
                float _ny = _cos * y - _sin * z;
                float _nz = _sin * y + _cos * z;
                y = _y;
                z = _z;
                ny = _ny;
                nz = _nz;
                break;
            }
        case Axis::Y:
            {
                float _x = _cos * x - _sin * z;
                float _z = _sin * x + _cos * z;
                float _nx = _cos * x - _sin * z;
                float _nz = _sin * x + _cos * z;
                x = _x;
                z = _z;
                nx = _nx;
                nz = _nz;
                break;
            }
        case Axis::Z:
            {
                float _x =  _cos * x + _sin * y;
                float _y = -_sin * x + _cos * y;
                float _nx =  _cos * x + _sin * y;
                float _ny = -_sin * x + _cos * y;
                x = _x;
                y = _y;
                nx = _nx;
                ny = _ny;
            }
        
            
    }
}

float Mesh::Vertex::ComputeIllumination(Light const& light)
{
    return (nx * light.x + ny * light.y + nz * light.z);
}

void Mesh::Vertex::Debug()
{
    std::cout << "x:" << x << ", y:" << y << ", z:" << z << std::endl;
}

Mesh::Mesh(Settings& settings) : m_rotation{0.0f, 0.0f, 0.0f}, m_resolution(settings.getResolution())
{
}

void Mesh::AddVertex(float x, float y, float z, float nx, float ny, float nz)
{
    m_vertices.emplace_back(x, y, z, nx, ny, nz);
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

    switch (axis)
    {
    case Axis::X:
        {
            m_rotation[0] += angle;
            break;
        }
    case Axis::Y:
        {
            m_rotation[1] += angle;
            break;
        }
    case Axis::Z:
        {
            m_rotation[2] += angle;
            break;
        }
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
        float costheta = cos(majorR), sintheta = sin(majorR);
        
        for (int j = 0; j < m_resolution; j++)
        {
            float minorR = PI - (2.0f*PI * j) / ((float)m_resolution - 1);
            float cosphi = cos(minorR), sinphi = sin(minorR);
            
            for (int k = 0; k < m_resolution; k++)
            {
                
                float x = (majorRadius + minorRadius * cosphi) * costheta;
                float y = (majorRadius + minorRadius * sinphi) * sintheta;
                float z = minorR * sinphi;
                
                /* tangent vector with respect to big circle */
                float tx = -sin(majorR);
                float ty = cos(majorR);
                float tz = 0;
                /* tangent vector with respect to little circle */
                float sx = cos(majorR)*(-sin(minorR));
                float sy = sin(majorR)*(-sin(minorR));
                float sz = cos(minorR);
                /* normal is cross-product of tangents */
                float nx = ty*sz - tz*sy;
                float ny = tz*sx - tx*sz;
                float nz = tx*sy - ty*sx;
                /* normalize normal */
                float length = sqrt(nx*nx + ny*ny + nz*nz);
                
                AddVertex(x, y, z, nx / length, ny / length, nz / length);

                
            }
        }
    }
}

float const* Mesh::getRotation() const
{
    return m_rotation;
}
