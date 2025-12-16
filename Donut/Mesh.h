#pragma once
#include <vector>

#include "defines.h"
#include "Settings.h"


class Light;

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
        float x     = 0;
        float y     = 0;
        float z     = 0;
        
        float nx    = 0;
        float ny    = 0;
        float nz    = 0;
        
        Vertex() = default;
        Vertex(float x, float y, float z, float nx, float ny, float nz);

        void Rotate(float angle, Axis axis);
        float ComputeIllumination(Light const& light);
        void Debug();
    };

    Mesh(Settings& settings);

    void AddVertex(float x, float y, float z, float nx, float ny, float nz);
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
