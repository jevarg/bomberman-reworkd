#ifndef _HUD_HPP_
# define _HUD_HPP_

# include <BasicShader.hpp>
# include "Player.hpp"
# include "Square.hpp"
# include "Text.hpp"

typedef struct s_gameinfo t_gameinfo;

# define STOCK_TEXTURE "./Resources/Assets/stock.tga"
# define NOSTOCK_TEXTURE "./Resources/Assets/nostock.tga"
# define HEART_TEXTURE "./Resources/Assets/heart.tga"
# define NOHEART_TEXTURE "./Resources/Assets/noheart.tga"

class HUD
{
public:
  HUD(puff::AShader &shader);
  ~HUD();

  void setScore(float score, float x);
  void draw(Player *player, t_gameInfo &gameInfo, bool multi);

private:
  puff::AShader &_shader;
  Square _stock;
  Square _nostock;
  Square _heart;
  Square _noHeart;
  Text	 _score;
};

#endif /* _HUD_HPP_ */
