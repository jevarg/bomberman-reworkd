
#include "Geometry.hpp"

namespace puff
{
    Geometry::Geometry()
    {
        
    }
    
    Geometry::~Geometry()
    {
        glDeleteBuffers(1, &_vboID);
        glDeleteVertexArrays(1, &_vaoID);
    }
    
    Geometry    &Geometry::pushVertex(const glm::vec3 &vertex)
    {
        _vertices.push_back(vertex);

        return (*this);
    }
    
    Geometry    &Geometry::pushUv(const glm::vec2 &vertexUV)
    {
        _UVs.push_back(vertexUV);

        return (*this);
    }
    
    Geometry    &Geometry::pushNormal(const glm::vec3 &vertexNormal)
    {
        _normals.push_back(vertexNormal);

        return (*this);
    }
    
    void    Geometry::draw(Shader *shader, const glm::mat4 &modelView, const glm::mat3 &normal, GLenum drawMode)
    {
        glBindVertexArray(_vaoID);
        
        shader->setUniform("modelView", modelView);
        shader->setUniform("normal", normal);

        glDrawArrays(drawMode, 0, (GLsizei) _vertices.size());
        glBindVertexArray(0);
    }
    
    void    Geometry::build(GLenum usage)
    {
        unsigned long verticesBytes, UVsBytes, normalsBytes = 0;
        size_t floatSize = sizeof(float);
        
        if (!_vertices.size() || !_UVs.size())
        {
            std::cerr << "Geometry Error: one vector is empty at least" << std::endl;
            return ;
        }
        
        verticesBytes = (floatSize * _vertices.size() * 3);
        UVsBytes = (floatSize * _UVs.size() * 3);
        normalsBytes = (floatSize * _normals.size() * 3);
        
        if (!verticesBytes)
        {
            std::cerr << "Geometry: Vertices empty" << std::endl;
            return ;
        }
        
        glGenBuffers(1, &_vboID);
        glGenVertexArrays(1, &_vaoID);
        
        glBindBuffer(GL_ARRAY_BUFFER, _vboID);
        
        // VRAM allocation
        glBufferData(GL_ARRAY_BUFFER, verticesBytes + UVsBytes + normalsBytes, NULL, usage);
        glBufferSubData(GL_ARRAY_BUFFER, 0, verticesBytes, _vertices.data());
        glBufferSubData(GL_ARRAY_BUFFER, verticesBytes, UVsBytes, _UVs.data());
        glBufferSubData(GL_ARRAY_BUFFER, verticesBytes + UVsBytes, normalsBytes, _normals.data());
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindVertexArray(_vaoID);
        
        glBindBuffer(GL_ARRAY_BUFFER, _vboID);
        
        // Getting vertices from GPU
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
        glEnableVertexAttribArray(0);
        
        // Getting UVs from GPU
        glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(verticesBytes));
        glEnableVertexAttribArray(3);
        
        // Getting normals from GPU
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(verticesBytes + UVsBytes));
        glEnableVertexAttribArray(2);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindVertexArray(0);
    }
}
