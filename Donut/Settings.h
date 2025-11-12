#pragma once
#include "defines.h"

class Settings
{
public:
    Settings(int argc, char* argv[]);
    ~Settings() = default;

    int getWidth();
    int getHeight();
    int getResolution();

private:
    int m_width         = DEFAULT_WIDTH;
    int m_height        = DEFAULT_HEIGHT;
    
    int m_resolution    = DEFAULT_RESOLUTION;
};
