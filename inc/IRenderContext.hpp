//
//  IRenderContext.hpp
//  bomberman
//
//  Created by bobbyghetto on 07/02/2018.
//  Copyright © 2018 bobbyghetto. All rights reserved.
//

#ifndef IRenderContext_h
# define IRenderContext_h

# include <SDL2/SDL.h>
# include "Input.hpp"
# include "Clock.hpp"

namespace    puff
{
    // Class for an SFML Context
    class IRenderContext
    {
    public:
        virtual ~IRenderContext() {};
        
        // Start the context, create a window
        virtual bool    start(unsigned int swidth, unsigned int sheight, const std::string &name, int initFlags = SDL_INIT_VIDEO, int windowsFlags = SDL_WINDOW_OPENGL) = 0;

        // Update the inputs
        virtual void    updateInputs(Input &input) const = 0;
        // Update the game clock
        virtual void    updateClock(Clock &clock) const = 0;
        // Flush the screen to show what has been drawn
        virtual void    flush() const = 0;
        // Close the context and the window
        virtual void    stop() const = 0;
    };
    
}

#endif /* IRenderContext_h */
