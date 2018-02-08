#pragma once

# include <GL/glew.h>

#ifdef _WIN32
# include <Windows.h>
# include <GL\GL.h>
# include <GL\GLU.h>
# include <GL\glext.h>
#elif __APPLE__
#
#else
# include <GL/gl.h>
# include <GL/glu.h>
#endif

