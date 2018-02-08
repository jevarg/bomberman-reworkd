#pragma once

#include <AShader.hpp>

namespace    puff
{
    // Class used to compile the shaders basic.fp and basic.vp
    class BasicShader : public AShader
    {
    public:
        BasicShader();
        ~BasicShader();
        
        // Function used to build the shaders once they are loaded
        virtual bool build();
    };
    
}

