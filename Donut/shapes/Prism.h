#pragma once
#include "../Mesh.h"

class Prism : public Mesh
{
public:
    inline int index(int face, int faceSize, int i, int j)
    {
        return face * faceSize + i * m_resolution + j;
    }
    
    explicit Prism(float width, float height, float depth, Settings const& settings)
        : Mesh(settings)
    {
        float side = 10;
        float h = side * 0.5f;
        int faceSize = m_resolution * m_resolution;
        m_vertices.resize(6 * faceSize);

        for (int i = 0; i < m_resolution; i++)
        {
            float u = (float)i / (m_resolution - 1) - 0.5f;
            for (int j = 0; j < m_resolution; j++)
            {
                float v = (float)j / (m_resolution - 1) - 0.5f;
                // Avant 
                {
                    Vertex& vert = m_vertices[index(0, faceSize, i, j)];
                    vert.x = u * width;
                    vert.y = v * height;
                    vert.z = depth;
                    vert.nx = 0; 
                    vert.ny = 0; 
                    vert.nz = 1;
                }

                // Arrière
                {
                    Vertex& vert = m_vertices[index(1, faceSize, i, j)];
                    vert.x = u * width;
                    vert.y = v * height;
                    vert.z = -depth;
                    vert.nx = 0; 
                    vert.ny = 0; 
                    vert.nz = -1;
                }

                // Droite
                {
                    Vertex& vert = m_vertices[index(2, faceSize, i, j)];
                    vert.x = width;
                    vert.y = u * height;
                    vert.z = v * depth;
                    vert.nx = 1; 
                    vert.ny = 0; 
                    vert.nz = 0;
                }

                // Gauche
                {
                    Vertex& vert = m_vertices[index(3, faceSize, i, j)];
                    vert.x = -width;
                    vert.y = u * height;
                    vert.z = v * depth;
                    vert.nx = -1;
                    vert.ny = 0;
                    vert.nz = 0;
                }

                // Bas
                {
                    Vertex& vert = m_vertices[index(4, faceSize, i, j)];
                    vert.x = u * width;
                    vert.y = height;
                    vert.z = v * depth;
                    vert.nx = 0; 
                    vert.ny = 1; 
                    vert.nz = 0;
                }

                // Haut
                {
                    Vertex& vert = m_vertices[index(5, faceSize, i, j)];
                    vert.x = u * width;
                    vert.y = -height;
                    vert.z = v * depth;
                    vert.nx = 0; 
                    vert.ny = -1; 
                    vert.nz = 0;
                }
            }
        }
    }
};
