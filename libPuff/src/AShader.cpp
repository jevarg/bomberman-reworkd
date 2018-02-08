#include <AShader.hpp>

namespace puff
{
    AShader::AShader()
    {
        
    }
    
    AShader::~AShader()
    {
        
    }
    
    void AShader::bind()
    {
        
    }
    
    GLuint AShader::getProgramId() const
    {
        return 1;
    }
    
    bool AShader::load(const std::string &path, GLenum type)
    {
        return (true);
    }
    
    GLuint AShader::getUniformId(const std::string &k) const
    {
        return 0;
    }
    
    bool AShader::setUniform(const std::string &k, glm::vec2 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform2fv(location, 1, glm::value_ptr(v));
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, glm::vec3 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform3fv(location, 1, glm::value_ptr(v));
        return (true);
    }

    bool AShader::setUniform(const std::string &k, glm::vec4 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform4fv(location, 1, glm::value_ptr(v));
        return (true);
    }

    bool AShader::setUniform(const std::string &k, glm::mat2 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(v));
        return (true);
    }

    bool AShader::setUniform(const std::string &k, glm::mat3 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(v));
        return (true);
    }

    bool AShader::setUniform(const std::string &k, glm::mat4 const &v) const
    {
        GLint location = getUniformId(k);

        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(v));
        return (true);
    }

    bool AShader::setUniform(const std::string &k, glm::ivec2 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform2iv(location, 1, glm::value_ptr(v));
        return (true);
    }

    bool AShader::setUniform(const std::string & k, glm::ivec3 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform3iv(location, 1, glm::value_ptr(v));
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, glm::ivec4 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform4iv(location, 1, glm::value_ptr(v));
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, glm::uvec2 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform2uiv(location, 1, glm::value_ptr(v));
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, glm::uvec3 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform3uiv(location, 1, glm::value_ptr(v));
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, glm::uvec4 const &v) const
    {
        GLint location = getUniformId(k);
        
        glUniform4uiv(location, 1, glm::value_ptr(v));
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, float v) const
    {
        GLint location = getUniformId(k);
        
        glUniform1f(location, v);
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, unsigned int v) const
    {
        GLint location = getUniformId(k);
        
        glUniform1ui(location, v);
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, int v) const
    {
        GLint location = getUniformId(k);
        
        glUniform1i(location, v);
        return (true);
    }
    
    bool AShader::setUniform(const std::string &k, double v) const
    {
        GLint location = getUniformId(k);
        
        glUniform1d(location, v);
        return (true);
    }
    
    void AShader::_build()
    {
        
    }
    
    
    bool AShader::_compileShader(GLuint shaderId, const std::string &file) const
    {
        return true;
    }
    
    bool AShader::_linkProgram()
    {
        return true;
    }
    
    void AShader::_bindAttribLocation(GLuint location, const std::string &attribName)
    {
        
    }
    
    bool AShader::_bindTextureUnit(GLuint texUnit, const std::string &samplerName)
    {
        return true;
    }
}
