#ifndef _IOBJECT_HPP_
# define _IOBJECT_HPP_

//# include <Clock.hpp>
# include <Texture.hpp>
# include "ATransformation.hpp"
# include "Shader.hpp"
//# include "Input.hpp"

class IObject: public ATransformation
{
public:
    IObject(): ATransformation() {};
    virtual ~IObject() {};
    
    virtual bool initialize() = 0;
    //  virtual void draw(puff::AShader &shader, puff::Clock const &clock) const = 0;
    virtual void draw(puff::Shader *shader, const glm::mat4 &view) const = 0;
    virtual IObject *clone() const = 0;
    virtual void setTexture(puff::Texture *) = 0;
};

#endif /* _IOBJECT_HPP_ */
