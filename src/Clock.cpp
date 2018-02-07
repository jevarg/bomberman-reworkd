#include "Clock.hpp"

namespace puff {
    Clock::Clock()
    {
        _oldTime = SDL_GetTicks();
        _curTime = SDL_GetTicks();
    }
    
    Clock::~Clock()
    {
        
    }
    
    void Clock::update(unsigned int currentTime)
    {
        _oldTime = _curTime;
        _curTime = SDL_GetTicks();
    }
    
    double Clock::getElapsed() const
    {
        return (_curTime - _oldTime);
    }
}
