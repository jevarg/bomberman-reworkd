#include "SdlContext.hpp"

namespace puff
{
    bool    SdlContext::start(unsigned int swidth, unsigned int sheight,
                              const std::string &name, int initFlags, int windowsFlags)
    {
        if (SDL_Init(initFlags) < 0)
        {
            std::cerr << "Failed to initialize SDL" << std::endl;
            return (false);
        }
        
        
        _window = SDL_CreateWindow(name.c_str(),
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   swidth, sheight, windowsFlags);
        
        if(_window == NULL)
        {
            // Display error message
            std::cerr << "Window could not be created! SDL_Error:" << SDL_GetError() << std::endl;
            return (false);
        }
        else
        {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

            // Create OpenGL context
            _glContext = SDL_GL_CreateContext(_window);
            
            if(_glContext == NULL)
            {
                // Display error message
                std::cerr << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << std::endl;
                return (false);
            }
            else
            {
                // Initialize glew
                GLenum err = glewInit();
                std::cout << "GLEW Initialized" << std::endl;
                if (err != GLEW_OK)
                {
                    //Problem: glewInit failed, something is seriously wrong.
                    fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
                    return (false);
                }
                
                glEnable(GL_DEPTH_TEST);
                glClearColor (0, 0, 0, 1.0f);
            }
        }
        return (true);
    }
    
    // Update the inputs
    void    SdlContext::updateInputs(Input &input) const
    {

    }
    
    // Update the game clock
    void    SdlContext::updateClock(Clock &clock) const
    {
        unsigned int currentTime = SDL_GetTicks();
        clock.update(currentTime);
    }
    
    // Flush the screen to show what has been drawn
    void    SdlContext::flush() const
    {
        SDL_GL_SwapWindow(_window);
//        SDL_Event event;
//        while (SDL_PollEvent(&event))
//        {
//            if (event.type == SDL_QUIT ||
//                event.type == SDL_KEYDOWN)
//                loop = false;
//        }
    }
    
    // Close the context and the window
    void    SdlContext::stop() const
    {
        SDL_GL_DeleteContext(_glContext);
        SDL_DestroyWindow(_window);
    }
}
