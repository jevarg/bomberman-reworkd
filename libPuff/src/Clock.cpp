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
    
    void Clock::update(unsigned int currentTime)
    {
        _oldTime = _curTime;
		_curTime = currentTime;
    }
    
    double Clock::getElapsed() const
    {
        double elapsedTime = static_cast<double>((_curTime - _oldTime) / 1000.0);
        return elapsedTime;
    }
}
