#ifndef _CUBE_HPP_
# define _CUBE_HPP_

# include "glm/glm.hpp"
# include "glm/gtc/matrix_transform.hpp"

# include <iostream>
# include "Geometry.hpp"
//# include <Texture.hh>
# include "Clock.hpp"
# include "IObject.hpp"
# include "Exception.hpp"
# include "Input.hpp"

class Input;

class Cube : public IObject
{
public:
    Cube();
    Cube(const std::string &);
    Cube(const Cube &);
    virtual ~Cube();
    virtual bool    initialize();
    virtual void    draw(puff::AShader &shader, puff::Clock const &) const;
    virtual IObject *clone() const;
//    void setTexture(gdl::Texture *texture);
    
private:
    
//    gdl::Texture *_texture;
    gdl::Geometry *_geometry;
    std::string _file;
};

#endif /* _CUBE_HPP_ */
