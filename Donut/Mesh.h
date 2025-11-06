#pragma once



class Mesh
{
public:
    struct Vertex
    {
        float x;
        float y;
        float z;
        Vertex(float x, float y, float z);
    };

    Mesh(int width, int height);
};
