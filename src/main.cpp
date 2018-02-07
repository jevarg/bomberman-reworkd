#include <iostream>
#include "SdlContext.hpp"
//#include "Menu.hpp"
#include <string>
//#include "GameEngine.hpp"
//#include "Menu.hpp"
//#include "Exception.hpp"
//#include "Player.hpp"
#include <unistd.h>
//#include "AObject.hpp"
//#include "Shader.hpp"
//#include "Cube.hpp"
//#include "Camera.hpp"
//#include "Input.hpp"

int	main()
{
    int	seed;
    
    __asm__ volatile ("rdtsc" : "=A" (seed));
    std::srand(seed);
    
    puff::SdlContext *context = new puff::SdlContext();
    
    context->start(800, 600, "Bomberman");
    
    while(1) {
        context->flush();
    }
    //  try
    //    {
    //      Menu menu;
    //      menu.launch();
    //    }
    //  catch (const Exception &e)
    //    {
    //      std::cerr << e.what() << std::endl;
    //      return (1);
    //    }
    
    
//    Camera *camera = new Camera(window.getSize().x, window.getSize().y);
//    
//    camera->setPos(glm::vec3(6.0f, 8.0f, 6.0f));
//    camera->setPointView(glm::vec3(0.1f, 0.1f, 0.1f));
//    glEnable (GL_DEPTH_TEST);
//    
//    //puff::Shader *shader = new puff::Shader("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag");
//    
//    puff::Shader *shader = new puff::Shader("Resources/Shaders/cell_shading.vert", "Resources/Shaders/cell_shading.frag");
//    shader->create();
//    
//    Cube *cube = new Cube();
//    
//    cube->initialize();
//    cube->setTexture("Resources/Assets/skybox.jpg");
//    cube->scale(glm::vec3(3));
//    
//    // run the main loop
//    bool running = true;
//    while (running)
//    {
//        // handle events
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                // end the program
//                running = false;
//            }
//            else if (event.type == sf::Event::Resized)
//            {
//                // adjust the viewport when the window is resized
//                glViewport(0, 0, event.size.width, event.size.height);
//            }
//        }
//
//        // clear the buffers
//        //        glClearColor(.7f, .2f, .2f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        camera->lookAt();
//        glm::mat4 view = camera->getTransformation();
//
//        shader->bind();
//        shader->setUniform("projection", camera->getProjection());
//        cube->draw(shader, view);
//        cube->rotate(glm::vec3(0, 1.0f, 0), .02f);
//
//        // end the current frame (internally swaps the front and back buffers)
//        window.display();
//    }
    //    GameEngine graphic(1640, 1024);
    //
    //    graphic.initOpenGL();
    //    graphic.run();
    
    return (0);
}
