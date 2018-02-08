#ifndef CONSOLE_HPP_
# define CONSOLE_HPP_

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif // WIN32

# include <string>
# include <map>
# include <list>
# include <SdlContext.hpp>
# include "Settings.hpp"
# include "Input.hpp"
# include "Settings.hpp"
# include "Text.hpp"

class		Console
{
public:
  Console(Settings &set, Input &input, puff::Clock &clock, puff::AShader &shader);
  ~Console();

  bool		parseCmd(const std::string &, std::string &);
  bool		aff(puff::SdlContext const&, float x, float y);

private:
  bool		import(const std::string &, std::string &, int);
  bool		bind(const std::string &, std::string &, int);
  bool		set(const std::string &, std::string &, int);
  bool		help(const std::string &, std::string &, int);
  bool		isPrintable(char key);
  void		print(Text &text, int winY);
  void		handleClock(const puff::SdlContext &win, int &frame,
			    double &time, double fps);

  Settings	&_set;
  Input		&_input;
  puff::Clock	&_clock;
  puff::AShader	&_shader;
  std::map<std::string, bool (Console::*)(const std::string &, std::string &, int)> _cmd;
  std::list<std::string>  _history;
  std::string	_buf;
  std::string	_ret;
};

#endif /* !CONSOLE_HPP_ */
