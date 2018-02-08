
#include "Geometry.hpp"

namespace puff
{
    Geometry::Geometry() {
        ;
    }
    
    Geometry::~Geometry() {
        ;
    }
    
    Geometry &Geometry::pushVertex(const glm::vec3 &t) {
        return (*this);
    }
    
    Geometry &Geometry::pushUv(const glm::vec2 &t) {
        return (*this);
    }
    
    Geometry &Geometry::pushNormal(const glm::vec3 &t) {
        return (*this);
    }
    
    Geometry &Geometry::setColor(const glm::vec4 &t) {
        return (*this);
    }
    
    bool Geometry::build() {
        return true;
    }
    
    void Geometry::draw(puff::AShader &shader, const glm::mat4 &transform, GLenum drawMode)
    {
        
    }
}

