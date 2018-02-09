#include "Model.hpp"

Model::Model()
  : IObject()
{
  _obj = NULL;
}

Model::Model(Model const& model)
  : IObject(), _obj(model._obj)
{
}

Model::~Model()
{
  if (_obj != NULL)
    delete _obj;
}

IObject *Model::clone() const
{
  return (new Model(*this));
}

bool		Model::initialize()
{
  return (true);
}

void	Model::draw(puff::AShader &shader, puff::Clock const& clock) const
{
  _obj->draw(shader, getTransformation(), clock.getElapsed());
}

bool		Model::load(std::string const& path)
{
  if (_obj != NULL)
    delete _obj;
  _obj = new puff::Model();
  if (!_obj->load(path))
    return (false);
  _obj->setCurrentAnim(0, true);
  return (true);
}

void		Model::setTexture(puff::Texture *)
{
    
}

puff::Model	*Model::getModel()
{
  return (_obj);
}
