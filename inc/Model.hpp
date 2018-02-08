#ifndef _MODEL_H_
# define _MODEL_H_

# include <Model.hpp>
# include <Texture.hpp>
# include <string>
# include "IObject.hpp"
# include "Exception.hpp"
# include "Input.hpp"

class		Model: public IObject
{
public:
  Model();
  Model(Model const&);
  virtual ~Model();

  bool		initialize();
  bool		load(std::string const&);

  void		draw(puff::AShader &, puff::Clock const&) const;

  void		setTexture(puff::Texture *);

  IObject	*clone() const;

  puff::Model	*getModel();

private:
  puff::Model	*_obj;
};

#endif /* !_MODEL_H_ */
