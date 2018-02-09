#include "Texture.hpp"
#include <iostream>

namespace puff
{
    Texture::Texture() {

    }
    
    Texture::Texture(const Texture &o) {

    }
    
    Texture::~Texture() {

    }
    
    bool Texture::load(const std::string &path, bool genMipmaps) {
        tga_image  loadedImage;
        tga_result result;
        
        result = tga_read(&loadedImage, path.c_str());
        if (result != TGA_NOERR)
        {
            std::cerr << "Targa image: " << tga_error(result) << ": " << path << std::endl;
            return (false);
        }
        
        if (loadedImage.origin_y)
        {
            tga_flip_vert(&loadedImage);//TODO REWORK
        }
        
        _width  = loadedImage.width;
        _height = loadedImage.height;

        glGenTextures(1, &_id);
        
        // "Bind" the newly created texture : all future texture functions will modify this texture
        glBindTexture(GL_TEXTURE_2D, _id);
        
        if (loadedImage.pixel_depth == 32) //TODO REWORK
        {
            // Give the image to OpenGL
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_BGRA, GL_UNSIGNED_BYTE, loadedImage.image_data);
        }
        else
        {
            // Give the image to OpenGL
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_BGR, GL_UNSIGNED_BYTE, loadedImage.image_data);
        }
        
        // When MAGnifying the image (no bigger mipmap available), use LINEAR filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        if (genMipmaps)
        {
            // When MINifying the image, use a LINEAR blend of two mipmaps, each filtered LINEARLY too
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            
            // Generate mipmaps, by the way.
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        
        tga_free_buffers(&loadedImage);
        return (true);
    }
    
    GLuint Texture::getId() const {
        return _id;
    }
    
    void Texture::bind() const {
        glBindTexture(GL_TEXTURE_2D, _id);
    }
    
    GLuint Texture::getWidth() const {
        return _width;
    }
    
    GLuint Texture::getHeight() const {
        return _height;
    }
    
    Texture &Texture::operator=(const Texture &o) {
        _id     = o.getId();
        _width  = o.getWidth();
        _height = o.getHeight();
        
        return (*this);
    }
}
