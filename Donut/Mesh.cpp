#include "Mesh.h"

#include <iostream>

#include "Light.h"

Vertex::Vertex(float x, float y, float z, float nx, float ny, float nz)
: x(x), y(y), z(z), nx(nx), ny(ny), nz(nz)
{
}

void Vertex::Rotate(float angle, Mesh::Axis axis)
{

    float _cos = cos(angle);
    float _sin = sin(angle);

    switch (axis)
    {
        case Mesh::Axis::X:
            {
                float _y =  _cos * y - _sin * z;
                float _z =  _sin * y + _cos * z;
                float _ny = _cos * ny - _sin * nz;
                float _nz = _sin * ny + _cos * nz;
                y = _y;
                z = _z;
                ny = _ny;
                nz = _nz;
                break;
            }
        case Mesh::Axis::Y:
            {
                float _x =  _cos * x - _sin * z;
                float _z =  _sin * x + _cos * z;
                float _nx = _cos * nx - _sin * nz;
                float _nz = _sin * nx + _cos * nz;
                x = _x;
                z = _z;
                nx = _nx;
                nz = _nz;
                break;
            }
        case Mesh::Axis::Z:
            {
                float _x =  _cos * x + _sin * y;
                float _y =  -_sin * x + _cos * y;
                float _nx = _cos * nx + _sin * ny;
                float _ny = -_sin * nx + _cos * ny;
                x = _x;
                y = _y;
                nx = _nx;
                ny = _ny;
            }
    }
}

float Vertex::ComputeIllumination(Light const& light)
{
    return nx*light.GetNormalizedLight().nx + ny*light.GetNormalizedLight().ny + nz*light.GetNormalizedLight().nz; 
}

void Vertex::Debug() const
{
    std::cout << "x:" << x << ", y:" << y << ", z:" << z << std::endl;
}

Mesh::Mesh(Settings const& settings) : m_rotation{0.0f, 0.0f, 0.0f}, m_resolution(settings.getResolution())
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

std::vector<Vertex> const& Mesh::GetVertices() const
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

float const* Mesh::getRotation() const
{
    return m_rotation;
}

void Mesh::setPosition(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}