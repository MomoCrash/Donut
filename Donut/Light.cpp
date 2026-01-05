#include "Light.h"

#include <iostream>

Light::Light(Settings const& settings)
{

    // No need to position light because we only need light direction
    m_lightVertex.x = 0.f;
    m_lightVertex.y = 0.f;
    m_lightVertex.z = 0.f;
    
    float nx = settings.getLightDirectionX();
    float ny = settings.getLightDirectionY();
    float nz = settings.getLightDirectionZ();
    float directionNorm = std::sqrt(nx*nx + ny*ny + nz*nz);
    if(directionNorm != 0.f)
    {
        m_lightVertex.nx = nx/directionNorm;
        m_lightVertex.ny = ny/directionNorm;
        m_lightVertex.nz = nz/directionNorm;
    }
    
}
