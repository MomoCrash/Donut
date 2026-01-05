#pragma once
#include "../Mesh.h"

#include <iostream>

class Circle : public Mesh
{
public:
    explicit Circle(float radius, float angle=2*PI, Settings const& settings)
        : Mesh(settings)
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
};
