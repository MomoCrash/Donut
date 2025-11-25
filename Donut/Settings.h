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

private:
    int     m_width                 = DEFAULT_WIDTH;
    int     m_height                = DEFAULT_HEIGHT;
    
    int     m_resolution            = DEFAULT_RESOLUTION;
    char    m_screenBackground      = '.';
    char    m_screenMeshProjection  = 'X';
    float   m_screenPosition        = 10;
};
