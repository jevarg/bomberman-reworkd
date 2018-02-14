#pragma once

#include <SDL2/SDL_timer.h>

namespace    puff
{
    // Class used to get the elapsed time since the last update
    class Clock
    {
    private:
		double _oldTime;
		double _curTime;
        
    public:
        Clock();
        virtual ~Clock();

        // Do not call this function yourself!
        // It is used by the context to update the current time
        void update(double currentTime);
        
        // Function used to get the elapsed time since the last update
        double getElapsed() const;
    };
    
}
