# ifdef _WIN32
#  include <io.h>
# else
#  include <unistd.h>
# endif // WIN32

#include <iostream>
#include <SdlContext.hpp>
#include <string>
#include "BasicShader.hpp"
#include "Menu.hpp"
#include "GameEngine.hpp"
#include "Exception.hpp"
#include "Player.hpp"
#include "AObject.hpp"
#include "Cube.hpp"
#include "Camera.hpp"
#include "Input.hpp"

#ifdef _WIN32
FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
    return _iob;
}
#endif // WIN32

//int    main()
//{
//    puff::SdlContext *context = new puff::SdlContext();
//    context->start(800, 600, "Bomberman");
//
//    puff::BasicShader shader;
//    shader.load("./Resources/Shaders/basic.frag", GL_FRAGMENT_SHADER);
//    shader.load("./Resources/Shaders/basic.vert", GL_VERTEX_SHADER);
//    shader.build();
//
//    Camera *camera;
//    Cube cube;
//    puff::Texture texture;
//
//    texture.load("Resources/Assets/box.tga");
//    cube.initialize();
//    cube.setTexture(&texture);
//    cube.setPos(glm::vec3(3, 3, 1));
//    t_gameinfo ginfo(NULL, NULL, NULL, NULL, NULL, NULL);
//
//    ginfo.input = new Input();
//    ginfo.set = new Settings();
//    ginfo.sound = new Sound();
//    ginfo.clock = new puff::Clock();
//    ginfo.map = NULL;
//    ginfo.set->loadFile(DEFAULT_FILE);
//    ginfo.set->loadFile(USER_FILE);
//
//    camera = new Camera(&ginfo, false);
//    camera->setPos(glm::vec3(0, 1, 4));
//    camera->lookAt();
//
//    Model model;
//    model.load(BOMB_MODEL);
//    model.setPos(glm::vec3(0, -1.5f, 0));
//
//    while(1) {
//        SDL_PumpEvents();
//        context->updateClock(*ginfo.clock);
//
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        shader.bind();
//        shader.setUniform("projection", camera->getProjection());
//        shader.setUniform("view", camera->getTransformation());
//        model.draw(shader, *ginfo.clock);
//        model.rotate(glm::vec3(0, 1, 0), 0.02f);
//
//        cube.draw(shader, *ginfo.clock);
////        cube.rotate(glm::vec3(0, 1, 0), 0.02f);
//
//        context->flush();
//
//        usleep(1000);
//    }
//
//    return (0);
//}

int    main()
{
    int    seed;
    
    __asm__ volatile ("rdtsc" : "=A" (seed));
    std::srand(seed);

    try
    {
        Menu menu;
        menu.launch();
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}
