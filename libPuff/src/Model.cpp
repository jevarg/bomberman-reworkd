#include "Model.hpp"

namespace puff
{
    Model::Model() {
        ;
    }
    
    Model::~Model() {
        ;
    }
    
    void Model::pause(bool pauseAnim) {
        ;
    }
    
    bool Model::setCurrentAnim(int stack, bool loop) {
        return (true);
    }
    
    bool Model::setCurrentAnim(const std::string &name, bool loop) {
        return (true);
    }
    
    int Model::getAnimationFrameNumber(int stack) {
        return (1);
    }
    
    int Model::getAnimationFrameNumber(const std::string &name) {
        return (1);
    }
    
    float Model::getFrameDuration() {
        return (1.0f);
    }
    
    bool Model::createSubAnim(int stack, const std::string &subAnimName, int frameStart, int frameEnd) {
        return (true);
    }
    
    bool Model::createSubAnim(const std::string &name, const std::string &subAnimName, int frameStart, int frameEnd) {
        return (true);
    }
    
    bool Model::setCurrentSubAnim(const std::string &name, bool loop) {
        return (true);
    }
    
    bool Model::load(const std::string &path) {
        return (true);
    }
    
    void Model::draw(puff::AShader &shader, const glm::mat4 &transform, double deltaTime) {
        ;
    }
    
    void Model::removeFromManager()
    {
        ;
    }
    
}
