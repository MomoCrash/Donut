#pragma once
#include <vector>

#include "defines.h"
#include "Settings.h"


class Mesh
{
public:

    enum class Axis
    {
        X,
        Y,
        Z
    };

    
    struct Vertex
    {
        float x = 0;
        float y = 0;
        float z = 0;
        Vertex() = default;
        Vertex(float x, float y, float z);

        void Rotate(float angle, Axis axis);
        void Debug();
    };

    Mesh(Settings& settings);

    void AddVertex(float x, float y, float z);
    void AddVertex(Vertex v);
    std::vector<Vertex> const& GetVertices() const;

    void Rotate(float angle, Axis axis);
    void Debug();

    void GenerateCircle     (float radius, float angle=2*PI);
    void GenerateHalfCircle (float radius);
    void GenerateRectangle  (float width, float height);
    void GenerateSquare     (float size);
    void GenerateTorus      (float innerRadius, float radius);

private:
    std::vector<Vertex> m_vertices;
    int m_resolution;

};
