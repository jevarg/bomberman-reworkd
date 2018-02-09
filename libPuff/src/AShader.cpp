#include <stdexcept>

#include "AShader.hpp"

namespace puff
{
    AShader::AShader()
    {

    }
    
    AShader::~AShader()
    {
        glDeleteShader(_vertexId);
        glDeleteShader(_fragmentId);
        glDeleteProgram(_programId);
        
        _vertexId = 0;
        _fragmentId = 0;
        _programId = 0;
    }
    
    bool AShader::load(const std::string &path, GLenum type)
    {
        GLuint shaderId = 0;
        
        if (type == GL_VERTEX_SHADER || type == GL_FRAGMENT_SHADER)
            shaderId = glCreateShader(type);
        else
        {
            throw std::runtime_error(std::string("Shader file: ") + path + std::string(" has a wrong type"));
        }
        
        if (_compileShader(shaderId, path) == true)
        {
            if (type == GL_VERTEX_SHADER)
                _vertexId = shaderId;
            else if (type == GL_FRAGMENT_SHADER)
                _fragmentId = shaderId;
            
            return (true);
        }
        
        return (false);
    }
    
    bool AShader::_compileShader(GLuint shaderId, const std::string &file) const
    {
        std::string src, srcLine;
        std::ifstream fileStream(file.c_str());
        
        if(!fileStream)
        {
            glDeleteShader(shaderId);
            std::cerr << "Shader file: " << file << " cannot be opened: " << std::endl;
            
            return (false);
        }
        
        while(getline(fileStream, srcLine))
        {
            src += srcLine + '\n';
        }
        
        fileStream.close();
        
        const GLchar* srcString = src.c_str();
        glShaderSource(shaderId, 1, &srcString, NULL);
        
        GLint shaderError(0), length(0);
        
        //    Compilation
        glCompileShader(shaderId);
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &shaderError);
        
        if(shaderError != GL_TRUE)
        {
            glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
            
            char *error = new char[length + 1];
            error[length] = '\0';
            
            glGetShaderInfoLog(shaderId, length, &length, error);
            
            std::cerr << "Shader file: " << file << " failed to compile: " << error << std::endl;
            delete [] error;
            
            return (false);
        }
        
        return (true);
    }
    
    void AShader::_build()
    {
        //    Program creation
        _programId = glCreateProgram();
        
        glAttachShader(_programId, _vertexId);
        glAttachShader(_programId, _fragmentId);
        
        _linkProgram();
    }
    
    bool AShader::_linkProgram()
    {
        //    Program Linking
        glLinkProgram(_programId);
        
        //    Check Linking state
        GLint link(0);
        glGetProgramiv(_programId, GL_LINK_STATUS, &link);
        
        if(link != GL_TRUE)
        {
            //        Getting error message length
            GLint length(0);
            char  *error(NULL);
            
            glGetProgramiv(_programId, GL_INFO_LOG_LENGTH, &length);
            
            error = new char[length + 1];
            
            // Copie de l'erreur dans la chaine de caractères
            glGetProgramInfoLog(_programId, length, &length, error);
            error[length] = '\0';
            
            std::cerr << "Shader file: failed to link:" << error << std::endl;
            delete[] error;
            
            return (false);
        }
        
        return (true);
    }
    
    void AShader::_bindAttribLocation(GLuint location, std::string const &attribName)
    {
        glBindAttribLocation(_programId, location, attribName.c_str());
    }
    
    //    void AShader::bindUniformMap()
    //    {
    //        int uniformNb;
    //        int uniformStringLength;
    //
    //        glGetProgramiv(_programId, GL_ACTIVE_UNIFORMS, &uniformNb);
    //        glGetProgramiv(_programId, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniformStringLength);
    //
    //        char* temp_buffer = new char[uniformStringLength + 1];
    //
    //
    //        for(int i = 0; i < uniformNb; i++)
    //        {
    //            unsigned int uniformType;
    //            int uniformID;
    //            int temp;
    //
    //            glGetActiveUniform(_programId, i, uniformStringLength, NULL, &temp ,&uniformType, temp_buffer);
    //            uniformID = glGetUniformLocation(_programId, temp_buffer);
    //            _uniformMap[std::string(temp_buffer)] = uniformID;
    //        }
    //
    //        delete[] temp_buffer;
    //    }
    
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
    
    void AShader::bind()
    {
        glUseProgram(_programId);
    }
    
    GLuint AShader::getProgramId() const
    {
        return _programId;
    }
    
    bool AShader::_bindTextureUnit(GLuint texUnit, const std::string &samplerName) {
//        glActiveTexture(texUnit);
        return 0;
    }
    
    GLuint AShader::getUniformId(const std::string &k) const {
        return glGetUniformLocation(_programId, k.c_str());
    }
    
    
    
    //    int AShader::operator[](const std::string &uni_string)
    //    {
    //        return _uniformMap[uni_string];
    //    }
    //
    //
    //    void AShader::deleteShader()
    //    {
    //        glDeleteShader(_vertexId);
    //        glDeleteShader(_fragmentId);
    //        glDeleteProgram(_programId);
    //
    //        _vertexId = 0;
    //        _fragmentId = 0;
    //        _programId = 0;
    //        _initialise = false;
    //    }
    //
    //
    //    Shader& AShader::operator=(AShader const &shader)
    //    {
    //        if (this != &shader)
    //        {
    //            _vertexSource = shader._vertexSource;
    //            _fragmentSource = shader._fragmentSource;
    //            _initialise = shader._initialise;
    //
    //            deleteShader();
    //            create();
    //        }
    //        return *this;
    //    }
}

