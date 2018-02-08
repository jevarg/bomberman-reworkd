#pragma once

#include <vector>
#include <iostream>
#ifdef _WIN32
# include <GL/glew.h>
#else
# include <OpenGL/gl3.h>
#endif

#include "glm/glm.hpp"
#include "Shader.hpp"

# define BUFFER_OFFSET(a) ((char*)NULL + (a)) // VBO macro

namespace puff
{
    class VertexBuffer;
    
    // Class used to create raw geometry by pushing vertex informations
    class Geometry
    {
    public:
        Geometry();
        ~Geometry();
        
        // Push a vertice
        Geometry &pushVertex(const glm::vec3 &t);
        
        // Push a UV texture coordinate
        Geometry &pushUv(const glm::vec2 &t);
        
        // Push a normal
        Geometry &pushNormal(const glm::vec3 &t);
        
        // Push a color
        Geometry &setColor(const glm::vec4 &t);
        
        // Build the geometry, must be called once
        void build(GLenum usage);
        
        // Draw the geometry, the build function must have been called before
        void draw(Shader *shader, const glm::mat4 &modelView, const glm::mat3 &normal, GLenum drawMode);
        
    private:
        VertexBuffer			*_buffer;
        
        std::vector<glm::vec3>	_vertices;
        std::vector<glm::vec4>	_colors;
        std::vector<glm::vec3>	_normals;
        std::vector<glm::vec2>	_UVs;
        
        glm::vec4				_currentColor;
        
        GLuint                  _vboID;
        GLuint                  _vaoID;
    };
}
