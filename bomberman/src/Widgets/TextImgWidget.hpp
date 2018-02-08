#ifndef _TEXTIMGWIDGET_H_
# define _TEXTIMGWIDGET_H_

# include "TextWidget.hpp"
# include "Menu.hpp"

class	TextImgWidget : public TextWidget
{
public:
  TextImgWidget(int x, int y, int height, int width,
		const std::string &texture, const std::string &text);
  ~TextImgWidget();

  const std::string	&getContent() const;
  virtual void	draw(puff::AShader &shader, const puff::Clock &clock);

protected:
  std::string	_sentence;
};

#endif /* _TEXTIMGWIDGET_H_ */
