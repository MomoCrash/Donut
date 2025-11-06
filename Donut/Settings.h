#pragma once

class Settings
{
public:
    Settings(int argc, char* argv[]);
    ~Settings() = default;

    int getWidth();
    int getHeight();
    int getResolution();

private:
    int m_width;
    int m_height;
    
    int m_resolution;
};
