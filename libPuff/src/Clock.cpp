#include "Clock.hpp"
#include <iostream>

namespace puff {
    Clock::Clock()
    {
        _oldTime = SDL_GetTicks();
        _curTime = _oldTime;
    }
    
    Clock::~Clock()
    {
        
    }
    
    void Clock::update(double currentTime)
    {
        _oldTime = _curTime;
		_curTime = currentTime;
    }
    
    double Clock::getElapsed() const
    {
        return (_curTime - _oldTime) / 1000;
    }
}
