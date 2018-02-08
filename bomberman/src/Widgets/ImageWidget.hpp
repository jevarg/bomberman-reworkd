#ifndef _IMAGEWIDGET_HPP_
# define _IMAGEWIDGET_HPP_

# include "AWidget.hpp"
# include "Menu.hpp"

class	ImageWidget : public AWidget
{
public:
  ImageWidget(int x, int y, int height, int width, const std::string &texture);
  ~ImageWidget();

  virtual void	draw(puff::AShader &shader, const puff::Clock &clock);

  bool	isClicked(int x, int y);
  void	onClick(t_gameinfo &gameInfo, Menu &menu);
};

#endif
