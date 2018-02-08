#ifndef _SQUARE_HPP_
# define _SQUARE_HPP_

# include <iostream>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <Geometry.hpp>
# include <Texture.hpp>
# include <Clock.hpp>
# include "IObject.hpp"
# include "Exception.hpp"

class Square : public IObject
{
public:
    Square();
    Square(const std::string &);
    Square(const Square &);
    virtual ~Square();
    virtual bool initialize();
    virtual void draw(puff::AShader &shader, puff::Clock const &) const;
    virtual IObject *clone() const;
    
    void setTexture(puff::Texture *texture);
    void setPos(int x, int y);
    void setSize(int x, int y);
    void setScale(int x, int y);
    void fillGeometry();
    
private:
    
    int _x, _y, _sizeX, _sizeY, _scaleX, _scaleY;
    puff::Texture *_texture;
    puff::Geometry *_geometry;
    std::string _file;
};

#endif /* _SQUARE_HPP_ */
