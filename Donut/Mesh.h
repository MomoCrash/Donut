#pragma once
#include <vector>


class Mesh
{
public:
    struct Vertex
    {
        float x = 0;
        float y = 0;
        float z = 0;
        Vertex() = default;
        Vertex(float x, float y, float z);

        void Debug();
    };

    Mesh(int resolution);

    void AddVertex(float x, float y, float z);
    void AddVertex(Vertex v);
    std::vector<Vertex> const& GetVertices();
    void Debug();

    void GenerateCircle     (float radius);
    void GenerateHalfCircle (float radius);
    void GenerateRectangle  (float width, float height);
    void GenerateSquare     (float size);

private:
    std::vector<Vertex> m_vertices;
    int m_resolution;

};
