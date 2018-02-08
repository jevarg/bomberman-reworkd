#include "Texture.hpp"

namespace puff
{
    Texture::Texture() {
        ;
    }
    
    Texture::Texture(const puff::Texture &o) {
        ;
    }
    
    Texture::~Texture() {
        ;
    }
    
    bool Texture::load(const std::string &path, bool genMimaps) {
        return (true);
    }
    
    GLuint Texture::getId() const {
        return 0;
    }
    
    void Texture::bind() const {
        ;
    }
    
    GLuint Texture::getWidth() const {
        return 0;
    }
    
    GLuint Texture::getHeight() const {
        return 0;
    }
    
    Texture &Texture::operator=(const puff::Texture &o) {
        return (*this);
    }
}
