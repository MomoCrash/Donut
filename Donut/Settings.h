#pragma once
#include "defines.h"

class Settings
{
public:
    Settings(int argc, char* argv[]);
    ~Settings() = default;

    int     getWidth() const;
    int     getHeight() const;
    int     getResolution() const;

    char    getScreenBackground() const;
    char    getScreenMeshProjection() const;
    float   getScreenPosition() const;
    
    float   getMeshRotationXPerFrame() const;
    float   getMeshRotationYPerFrame() const;
    float   getMeshRotationZPerFrame() const;
    int     getFrameDuration() const;

private:
    int     m_width                     = DEFAULT_WIDTH;
    int     m_height                    = DEFAULT_HEIGHT;
    
    int     m_resolution                = DEFAULT_RESOLUTION;
    char    m_screenBackground          = ' ';
    char    m_screenMeshProjection      = 'X';
    float   m_screenPosition            = 10;
    float   m_meshRotationXPerFrame     = 0.02f;
    float   m_meshRotationYPerFrame     = 0.04f;
    float   m_meshRotationZPerFrame     = 0.00f;
    int     m_frameDuration             = 100000;
};
