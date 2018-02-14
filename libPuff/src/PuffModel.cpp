#include "PuffModel.hpp"

namespace puff
{
    Model::Model()
    {
        ;
    }
    
    Model::~Model() {
        ;
    }
    
    void Model::pause(bool pauseAnim) {
        _model->SetPause(pauseAnim);
    }
    
    bool Model::setCurrentAnim(int stack, bool loop) {
        _loop = loop;
        return (_model->SetCurrentAnimStack(stack));
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
        _model = new FbxModel(path.c_str(), true);
        return _model->LoadFile();
    }
    
    void Model::draw(puff::AShader &shader, const glm::mat4 &transform, double deltaTime) {
        _model->OnDisplay(&shader, transform);
    }
    
    void Model::removeFromManager()
    {
        ;
    }
    
}
