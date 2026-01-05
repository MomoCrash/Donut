#pragma once
#include "../Mesh.h"

class Torus : public Mesh
{
public:
    explicit Torus(float majorRadius, float minorRadius, Settings const& settings)
        : Mesh(settings)
    {

        m_vertices.resize(m_resolution * m_resolution);
        for(int i = 0; i < m_resolution; i++)
        {
            float angleY = (2 * PI * i) / (m_resolution - 1);
            for(int j = 0; j < m_resolution; j++)
            {
                float angleZ = (2 * PI * j) / (m_resolution - 1);
                m_vertices[m_resolution * i + j].x = majorRadius + minorRadius * std::cos(angleZ);
                m_vertices[m_resolution * i + j].y = minorRadius * std::sin(angleZ);
                m_vertices[m_resolution * i + j].z = 0.f;
                m_vertices[m_resolution * i + j].nx = std::cos(angleZ);
                m_vertices[m_resolution * i + j].ny = std::sin(angleZ);
                m_vertices[m_resolution * i + j].nz = 0.f;
                m_vertices[m_resolution * i + j].Rotate(angleY, Axis::Y);
            }
        }
        
    }
};
