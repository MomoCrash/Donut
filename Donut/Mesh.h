#pragma once
#include <vector>

#include "Settings.h"

class Light;
struct Vertex;

class Mesh
{
public:

    enum class Axis
    {
        X,
        Y,
        Z
    };

    Mesh(Settings const& settings);

    void AddVertex(float x, float y, float z, float nx, float ny, float nz);
    void AddVertex(Vertex v);
    std::vector<Vertex> const& GetVertices() const;

    void Rotate(float angle, Axis axis);
    void Debug();

    float const* getRotation() const;
    void setPosition(float x, float y, float z);
    
    float getPositionX() const { return x; }
    float getPositionY() const { return y; }
    float getPositionZ() const { return z; }

protected:

    float x, y, z;
    std::vector<Vertex> m_vertices;
    float m_rotation[3];
    int m_resolution;
    
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

    void Rotate(float angle, Mesh::Axis axis);
    float ComputeIllumination(Light const& light);
    void Debug() const;
};
