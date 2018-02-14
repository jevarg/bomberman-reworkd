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
        
//        if (tga_read(&lTGAImage, pFilePath.Buffer()) == TGA_NOERR)
//        {
//            // Make sure the image is left to right
//            if (tga_is_right_to_left(&lTGAImage))
//            tga_flip_horiz(&lTGAImage);
//
//            // Make sure the image is bottom to top
//            if (tga_is_top_to_bottom(&lTGAImage))
//            tga_flip_vert(&lTGAImage);
//
//            // Make the image BGR 24
//            tga_convert_depth(&lTGAImage, 24);
//
//            // Transfer the texture date into GPU
//            glGenTextures(1, &pTextureObject);
//            glBindTexture(GL_TEXTURE_2D, pTextureObject);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//            //                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//            //                printf("error: %x\n", glGetError());
//            //                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//            //                printf("error: %x\n", glGetError());
//            //                glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, lTGAImage.width, lTGAImage.height, 0, GL_BGR, GL_UNSIGNED_BYTE, lTGAImage.image_data);
//            glBindTexture(GL_TEXTURE_2D, 0);
//
//
//            tga_free_buffers(&lTGAImage);
//
//            std::cout << "Loaded texture: " << pFilePath << std::endl;
//            return true;
//        }
        
        result = tga_read(&loadedImage, path.c_str());
        if (result != TGA_NOERR)
        {
            std::cerr << "Targa image: " << tga_error(result) << ": " << path << std::endl;
            return (false);
        }
        
        // Make sure the image is left to right
        if (tga_is_right_to_left(&loadedImage))
            tga_flip_horiz(&loadedImage);
        
        // Make sure the image is bottom to top
        if (tga_is_top_to_bottom(&loadedImage))
            tga_flip_vert(&loadedImage);
        
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
