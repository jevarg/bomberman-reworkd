
#include "Geometry.hpp"

namespace puff
{
    Geometry::Geometry() {
        ;
    }
    
    Geometry::~Geometry() {
        ;
    }
    
    Geometry &Geometry::pushVertex(const glm::vec3 &vertex)
    {
        _vertices.push_back(glm::vec4(vertex, 1.0f));
        return (*this);
    }
    
    Geometry &Geometry::pushUv(const glm::vec2 &uv)
    {
        _uvs.push_back(uv);
        return (*this);
    }
    
    Geometry &Geometry::pushNormal(const glm::vec3 &normal)
    {
        _normals.push_back(glm::vec4(normal, 1.0f));
        return (*this);
    }
    
    Geometry &Geometry::setColor(const glm::vec4 &color) {
        _colors.push_back(color);
        return (*this);
    }
    
    bool Geometry::build()
    {
        unsigned long verticesBytes, UVBytes, normalsBytes = 0;
        
        if (!_vertices.size() || !_uvs.size())
        {
            std::cerr << "Geometry Error: one vector is empty at least" << std::endl;
            return (false);
        }
        
        verticesBytes = sizeof(float) * _vertices.size() * 4;
        UVBytes = sizeof(float) * _uvs.size() * 3;
        normalsBytes = sizeof(float) * _normals.size() * 4;
        
        if (!verticesBytes)
        {
            std::cerr << "Geometry: Vertices empty" << std::endl;
            return (false);
        }
        
        glGenVertexArrays(1, &_vaoID);
        glGenBuffers(1, &_vboID);
        
        glBindBuffer(GL_ARRAY_BUFFER, _vboID);
        
        // VRAM allocation
        glBufferData(GL_ARRAY_BUFFER, verticesBytes + UVBytes + normalsBytes, NULL, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, verticesBytes, _vertices.data());
        glBufferSubData(GL_ARRAY_BUFFER, verticesBytes, UVBytes, _uvs.data());
        glBufferSubData(GL_ARRAY_BUFFER, verticesBytes + UVBytes, normalsBytes, _normals.data());
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindVertexArray(_vaoID);
        
        glBindBuffer(GL_ARRAY_BUFFER, _vboID);
        
        // Getting vertices from GPU
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);
        
        // Getting UVs from GPU
        glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(verticesBytes));
        glEnableVertexAttribArray(3);
        
        // Getting normals from GPU
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(verticesBytes + UVBytes));
        glEnableVertexAttribArray(2);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindVertexArray(0);
        
        return (true);
    }
    
    void Geometry::draw(puff::AShader &shader, const glm::mat4 &transform, GLenum drawMode)
    {
        glBindVertexArray(_vaoID);

        shader.setUniform("model", transform);
        glDrawArrays(drawMode, 0, (int) _vertices.size());

        glBindVertexArray(0);
    }
}

