#include "Settings.h"

#include <cstdlib>
#include <cstring>

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

int Settings::getFrameDuration() const
{
    return m_frameDuration / 1000;
}
