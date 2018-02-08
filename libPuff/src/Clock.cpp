#include "Clock.hpp"

namespace puff {
    Clock::Clock()
    {
        _oldTime = 0;
        _curTime = 0;
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
        return (_curTime - _oldTime);
    }
}
