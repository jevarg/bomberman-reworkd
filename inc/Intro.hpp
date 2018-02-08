#ifndef _INTRO_HPP_
# define _INTRO_HPP_

# ifndef INT64_C
#  define INT64_C(c) (int64_t)(c)
#  define UINT64_C(c) (uint64_t)(c)
# endif

extern "C"
{

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif // WIN32

# include <libavcodec/avcodec.h>
# include <libavformat/avformat.h>
# include <libswscale/swscale.h>
}

# include <SdlContext.hpp>
# include <OpenGL.hpp>
# include <Clock.hpp>

# include "GameEngine.hpp"
# include "Input.hpp"

class Intro
{
public:
  Intro();
  ~Intro();

  bool initialize(const std::string &file);
  void play(t_gameinfo &gameInfo, puff::SdlContext &win, puff::AShader &shader);

private:
  bool nextFrame();
  void generateTexture();
  bool update(puff::SdlContext &win, puff::Clock &clock, Input &input, Settings &set);
  void draw(puff::AShader &shader, puff::SdlContext &win, puff::Clock clock, float x, float y);

  int		_video;
  GLuint	_texture;
  AVCodec	*_codec;
  AVFrame	*_frame;
  AVFrame	*_frameRGB;
  AVPacket	_packet;
  Square	_square;
  AVDictionary	*_dictionary;
  AVCodecContext	*_contCodec;
  AVFormatContext	*_contFormat;
  struct SwsContext	*_sws;
};

#endif /* _INTRO_HPP_ */
