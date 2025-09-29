#ifndef SHADER_H
#define SHADER_H
    
    
#include <Rendering/OpenGl/glad/glad.h>

#include <Algebra/glm/glm.hpp>
#include <Algebra/glm/gtc/matrix_transform.hpp>
#include <Algebra/glm/gtc/type_ptr.hpp>

#include <FileTools.h>

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstdint>


    struct Attribute{
        unsigned int index;
        unsigned int size;
        GLenum type;
        size_t offset;
    };


    class Shader{
        private:

            std::vector<Attribute> vertexAttributes,instanceAttributes;
            

            bool setupShader(unsigned int*shader,GLenum type,const char* sourcePath);

            bool setupProgram(unsigned int*program,unsigned int**shader,uint8_t count);

            unsigned int shaderProgram;

            

        public:
            Shader(const char* vertexShaderPath,const char* fragmentShaderPath);

            Shader(const char* vertexShaderPath,const char* fragmentShaderPath,const char* geometryShaderPath);


            void activate();
            void disactivate();

            unsigned int getID();

            void setBool(const char*attributeName,bool value);
            void setInt(const char*attributeName,int value);
            void setFloat(const char*attributeName,float value);
            void setVec3(const char*attributeName,glm::vec3 value);
            void setMat4(const char*attributeName,glm::mat4 value);


            void setVertexAttributes(Attribute attribute);
            void setVertexAttributes(std::vector<Attribute> attributes);

            void setInstanceAttributes(Attribute attribute);
            void setInstanceAttributes(std::vector<Attribute> attributes);

            std::vector<Attribute>& getVertexAttributes();
            std::vector<Attribute>& getInstanceAttributes();


            unsigned int getUniformBlockIndex(const char* blockName);
            void bindUniformBlock(const char* blockName,unsigned int index);

        };    


#endif