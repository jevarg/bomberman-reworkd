#ifndef _QUITWIDGET_HPP_
# define _QUITWIDGET_HPP_

#include "AWidget.hpp"
#include "Menu.hpp"

class	QuitWidget : public AWidget
{
public:
  QuitWidget(int x, int y, int height, int width, const std::string &texture);
  ~QuitWidget();

  virtual void	draw(puff::AShader &shader, const puff::Clock &clock);

  void	onClick(t_gameinfo &gameInfo, Menu &menu);
};

#endif
