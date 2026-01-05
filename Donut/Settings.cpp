#include "Settings.h"

#include <cstdlib>
#include <cstring>
#include <string>

#include "defines.h"

Settings::Settings(int argc, char* argv[]) : m_width(DEFAULT_WIDTH), m_height(DEFAULT_HEIGHT), m_resolution(DEFAULT_RESOLUTION)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-w") == 0 && argc > i+1)
        {
            i++;
            m_width = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-h") == 0 && argc > i+1)
        {
            i++;
            m_height = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-r") == 0 && argc > i+1)
        {
            i++;
            m_resolution = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-b") == 0 && argc > i+1)
        {
            i++;
            m_screenBackground = argv[i][0];
        }
        if (strcmp(argv[i], "-p") == 0 && argc > i+1)
        {
            i++;
            m_screenMeshProjection = argv[i][0];
        }
        if (strcmp(argv[i], "-s") == 0 && argc > i+1)
        {
            i++;
            m_screenPosition = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-x") == 0 && argc > i+1)
        {
            i++;
            m_meshRotationXPerFrame = atof(argv[i]);
        }
        if (strcmp(argv[i], "-y") == 0 && argc > i+1)
        {
            i++;
            m_meshRotationYPerFrame = atof(argv[i]);
        }
        if (strcmp(argv[i], "-z") == 0 && argc > i+1)
        {
            i++;
            m_meshRotationZPerFrame = atof(argv[i]);
        }
        if (strcmp(argv[i], "-f") == 0 && argc > i+1)
        {
            i++;
            m_frameDuration = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-lx") == 0 && i + 1 < argc)
        {
            m_lightDirectionX = std::atof(argv[i+1]);
            i++;
        }
        if (strcmp(argv[i], "-ly") == 0 && i + 1 < argc)
        {
            m_lightDirectionY = std::atof(argv[i+1]);
            i++;
        }
        if (strcmp(argv[i], "-lz") == 0&& i + 1 < argc)
        {
            m_lightDirectionZ = std::atof(argv[i+1]);
            i++;
        }
    }
}

int Settings::getWidth() const
{
    return m_width;
}

int Settings::getHeight() const
{
    return m_height;
}

int Settings::getResolution() const
{
    return m_resolution;
}

char Settings::getScreenBackground() const
{
    return m_screenBackground;
}

char Settings::getScreenMeshProjection() const
{
    return m_screenMeshProjection;
}

float Settings::getScreenPosition() const
{
    return m_screenPosition;
}

float Settings::getMeshRotationXPerFrame() const
{
    return m_meshRotationXPerFrame;
}

float Settings::getMeshRotationYPerFrame() const
{
    return m_meshRotationYPerFrame;
}

float Settings::getMeshRotationZPerFrame() const
{
    return m_meshRotationZPerFrame;
}

float Settings::getLightDirectionX() const
{
    return m_lightDirectionX;
}

float Settings::getLightDirectionY() const
{
    return m_lightDirectionY;
}

float Settings::getLightDirectionZ() const
{
    return m_lightDirectionZ;
}

int Settings::getFrameDuration() const
{
    return m_frameDuration / 1000;
}
