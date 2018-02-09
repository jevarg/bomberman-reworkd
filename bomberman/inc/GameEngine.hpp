#ifndef _GAMEENGINE_HPP_
# define _GAMEENGINE_HPP_

# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif // WIN32


# include "glm/glm.hpp"
# include "glm/gtc/matrix_transform.hpp"
# include <vector>
# include <map>
# include <deque>
# include <Game.hpp>
# include <BasicShader.hpp>
# include <SdlContext.hpp>
# include <Clock.hpp>
# include "Input.hpp"
# include "Cube.hpp"
# include "Exception.hpp"
# include "Camera.hpp"
# include "IObject.hpp"
# include "Model.hpp"
# include "Save.hpp"
# include "Container.hpp"
# include "AEntity.hpp"
# include "Map.hpp"
# include "Spawn.hpp"
# include "Settings.hpp"
# include "Input.hpp"
# include "Player.hpp"
# include "Text.hpp"
# include "Condvar.hpp"
# include "Mutex.hpp"
# include "Console.hpp"
# include "Scopelock.hpp"
# include "ModelFactory.hpp"
# include "EntityFactory.hpp"
# include "SpeedItem.hpp"
# include "HealthItem.hpp"
# include "StockItem.hpp"
# include "RangeItem.hpp"
# include "Text.hpp"
# include "Light.hpp"
# include "Sound.hpp"
# include "Flame.hpp"
# include "Bomb.hpp"
# include "Box.hpp"
# include "IA.hpp"
# include "Hud.hpp"

# define WALL_TEXTURE "./Resources/Assets/wall.tga"
# define SKY_TEXTURE "./Resources/Assets/skybox.tga"
# define BOX_TEXTURE "./Resources/Assets/box.tga"
# define FLAME_TEXTURE "./Resources/Assets/flames.tga"
# define GROUND_TEXTURE "./Resources/Assets/ground.tga"

# define WIN_TEXTURE "./Resources/Assets/You-Win.tga"
# define LOSE_TEXTURE "./Resources/Assets/You-Lose.tga"

# define HEALTHITEM_MODEL "./Resources/Assets/health_item.fbx"
# define SPEEDITEM_MODEL "./Resources/Assets/speed_item.fbx"
# define STOCKITEM_MODEL "./Resources/Assets/stock_item.fbx"
# define RANGEITEM_MODEL "./Resources/Assets/range_item.fbx"
# define CHARACTER_MODEL "./Resources/Assets/steve.fbx"
# define CHARACTER2_MODEL "./Resources/Assets/villager.fbx"
# define BOT_MODEL "./Resources/Assets/pigman.fbx"
# define BOMB_MODEL "./Resources/Assets/tnt.fbx"
# define CHICKEN_MODEL "./Resources/Assets/chicken.fbx"
# define CRAZYCHICKEN_MODEL "./Resources/Assets/crazy_chicken.fbx"

# define ABS(x) (((x) < 0) ? (-(x)) : (x))

typedef struct s_score
{
  std::vector<std::string> name;
  std::vector<int> score;
}	       t_score;

typedef struct	s_gameinfo
{
  s_gameinfo(puff::Clock *pclock, Map *pmap, Settings *pset, Input *pinput, Sound *psound, Save *psave) :
    clock(pclock), input(pinput), set(pset), sound(psound), map(pmap), save(psave)
  {
  }
  puff::Clock   	*clock;
  Input	       	*input;
  Settings     	*set;
  Sound		*sound;
  Map	       	*map;
  Mutex		*mutex;
  Condvar	*condvar;
  Save		*save;
  t_score	score;
}		t_gameinfo;

class GameEngine : public puff::Game
{
public:
  GameEngine(puff::SdlContext *win, puff::BasicShader *shader, t_gameinfo *gameInfo);
  ~GameEngine();

  virtual bool	initialize();
  virtual bool	update();
  virtual void	draw();

  void		setMulti(bool multi);
  void		setPlayer(Player *player1, Player *player2);
  void		setShutdown(bool shutdown);
  bool		loadMap(const std::string &file);
  void		resetAlreadyPlayed();
  void		setConsole(Console * const console);
  bool		isShutedDown() const;
  bool		loadSave(const std::string &file);
  bool		loadMap(const std::string &file, int ia);

private:
  void	mainInput();
  int	clearElements();
  void	displayScore();
  void	moveGround(Player *player, float mapX, float mapY);
  void	fillScore(const std::string &name, int score);

  puff::SdlContext		*_win;
  puff::BasicShader		_shader;
  puff::BasicShader		*_textShader;
  Cube				*_ground;
  Cube				*_skybox;
  Console			*_console;
  unsigned int			_mapX;
  unsigned int			_mapY;
  std::map<eType, IObject *>	_type;
  std::map<eType, puff::Texture *>	_texture;
  Player			*_player;
  t_gameinfo			*_gameInfo;
  bool				_already_played;
  bool				_shutdown;
  int				_frames;
  std::vector<Light*>		_lights;
  Player			*_player1;
  Player			*_player2;
  std::vector<Player *>		_players;
  HUD				*_hud;
  Square			*_end_screen[2];
  std::map<std::string, int>	_score;
  Text				_fps;
  bool				_multi;
};

#endif /* _GAMEENGINE_HPP_ */
