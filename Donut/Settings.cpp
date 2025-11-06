#include "Settings.h"

#include <cstdlib>
#include <cstring>

#include "defines.h"

Settings::Settings(int argc, char* argv[]) : m_width(DEFAULT_WIDTH), m_height(DEFAULT_HEIGHT), m_resolution(DEFAULT_RESOLUTION)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-w") == 0)
        {
            i++;
            m_width = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-h") == 0)
        {
            i++;
            m_height = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-r") == 0)
        {
            i++;
            m_height = atoi(argv[i]);
        }
    }
}

int Settings::getWidth()
{
    return m_width;
}

int Settings::getHeight()
{
    return m_height;
}
