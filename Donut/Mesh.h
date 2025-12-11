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
        
        float sinphi = 0;
        float cosphi = 0;
        float sintheta = 0;
        float costheta = 0;
        Vertex() = default;
        Vertex(float x, float y, float z, float sinphi, float cosphi, float sintheta, float costheta);

        void Rotate(float angle, Axis axis);
        void Debug();
    };

    Mesh(Settings& settings);

    void AddVertex(float x, float y, float z, float sinphi, float cosphi, float sintheta, float costheta);
    void AddVertex(Vertex v);
    std::vector<Vertex> const& GetVertices() const;

    void Rotate(float angle, Axis axis);
    void Debug();

    void GenerateCircle     (float radius, float angle=2*PI);
    void GenerateHalfCircle (float radius);
    void GenerateRectangle  (float width, float height);
    void GenerateSquare     (float size);
    void GenerateTorus      (float majorRadius, float minorRadius);

    float const* getRotation() const;

private:
    std::vector<Vertex> m_vertices;
    float m_rotation[3];
    int m_resolution;

};
