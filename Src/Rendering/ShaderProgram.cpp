        
        
#include <Rendering/ShaderProgram.h> 

        
        bool ShaderProgram::setupShader(unsigned int*shader,GLenum type,const char* source){
            char *sourceCode = readFile(source);
            int result;
            *shader = glCreateShader(type);
            glShaderSource(*shader,1,&sourceCode,NULL);
            glCompileShader(*shader);

            glGetShaderiv(*shader,GL_COMPILE_STATUS,&result);
            if (!result){
                std::cout<<"SHADER-LINK-FAILED!"<<std::endl;
                char*errBuffer = (char*)malloc(500*sizeof(char));
                glGetShaderInfoLog(*shader,500,NULL,errBuffer);
                std::cout<<errBuffer<<std::endl;
                return false;
            }
            return true;
        }

        bool ShaderProgram::setupProgram(unsigned int*program,unsigned int**shader,uint8_t count){
            int result;
            *program = glCreateProgram();
            for (uint8_t i = 0; i < count; i++)
            {
                glAttachShader(*program,*shader[i]);
            }
            glLinkProgram(*program);

            glGetProgramiv(*program,GL_LINK_STATUS,&result);
            if (!result){
                char infoLog[512];
                glGetProgramInfoLog(*program, 512, NULL, infoLog);
                std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
                return false;
            }
            return true;
        }

        ShaderProgram::ShaderProgram(const char* vertexShaderPath,const char* fragmentShaderPath){
            unsigned int vertexShader,fragmentShader;
            setupShader(&vertexShader,GL_VERTEX_SHADER,vertexShaderPath);
            setupShader(&fragmentShader,GL_FRAGMENT_SHADER,fragmentShaderPath);

            unsigned int *shaders[2]={&vertexShader,&fragmentShader};

            setupProgram(&shaderProgram,shaders,2);
            glUseProgram(0);
        }

        ShaderProgram::ShaderProgram(const char* vertexShaderPath,const char* fragmentShaderPath,const char* geometryShaderPath){
            unsigned int vertexShader,fragmentShader,geometryShader;
            setupShader(&vertexShader,GL_VERTEX_SHADER,vertexShaderPath);
            setupShader(&fragmentShader,GL_FRAGMENT_SHADER,fragmentShaderPath);
            setupShader(&geometryShader,GL_GEOMETRY_SHADER,geometryShaderPath);


            unsigned int *shaders[3]={&vertexShader,&geometryShader,&fragmentShader};

            setupProgram(&shaderProgram,shaders,3);
            glUseProgram(0);
        }

        void ShaderProgram::activate(){
            glUseProgram(shaderProgram);
        }  

        void ShaderProgram::disactivate(){
            glUseProgram(0);
        }  

        unsigned int ShaderProgram::getID(){
            return shaderProgram;
        }

        void ShaderProgram::setBool(const char*uniformName,bool value){
            GLint location = glGetUniformLocation(shaderProgram,uniformName);
            if (location>=0){
                glUniform1i(location,value);
            }
            else{std::cout<<"Bool Location "<<uniformName<<" Failed!"<<std::endl;}
        }
        void ShaderProgram::setInt(const char*uniformName,int value){
            GLint location = glGetUniformLocation(shaderProgram,uniformName);
            if (location>=0){
                glUniform1i(location,value);
            }
            else{std::cout<<"Int Location "<<uniformName<<" Failed!"<<std::endl;}
        }
        void ShaderProgram::setFloat(const char*uniformName,float value){
            GLint location = glGetUniformLocation(shaderProgram,uniformName);
            if (location>=0){
                glUniform1f(location,value);
            }
            else{std::cout<<"Float Location "<<uniformName<<" Failed!"<<std::endl;}
        }
        void ShaderProgram::setMat4(const char*uniformName,glm::mat4 value){
            GLint location = glGetUniformLocation(shaderProgram,uniformName);
            if (location>=0){
                glUniformMatrix4fv(location,1,GL_FALSE,glm::value_ptr(value));
            }
            else{std::cout<<"Mat4 Location "<<uniformName<<" Failed!"<<std::endl;}
        }
        void ShaderProgram::setVec3(const char*uniformName,glm::vec3 value){
            GLint location = glGetUniformLocation(shaderProgram,uniformName);
            if (location>=0){
                glUniform3f(location,value.x,value.y,value.z);
            }
            else{std::cout<<"Vec3 Location "<<uniformName<<" Failed!"<<std::endl;}
        }

        void ShaderProgram::setVertexAttributes(Attribute _attribute){
            vertexAttributes.resize(1);
            vertexAttributes[0] = _attribute;
        }
        void ShaderProgram::setVertexAttributes(std::vector<Attribute> _attributes){
            vertexAttributes = _attributes;
        }

        void ShaderProgram::setInstanceAttributes(Attribute _attribute){
            instanceAttributes.resize(1);
            instanceAttributes[0] = _attribute;
        }
        void ShaderProgram::setInstanceAttributes(std::vector<Attribute> _attributes){
            instanceAttributes = _attributes;
        }

        std::vector<Attribute>& ShaderProgram::getVertexAttributes(){
            return vertexAttributes;
        }

        std::vector<Attribute>& ShaderProgram::getInstanceAttributes(){
            return instanceAttributes;
        }

        unsigned int ShaderProgram::getUniformBlockIndex(const char* blockName){
                return glGetUniformBlockIndex(shaderProgram,blockName);
            }

        void ShaderProgram::bindUniformBlock(const char* blockName,unsigned int index){
            unsigned int blockIndex = glGetUniformBlockIndex(shaderProgram,blockName);
            glUniformBlockBinding(shaderProgram,blockIndex,index);
        }


        const std::string ShaderProgram::getVertexShaderPath(){
            return vertexShaderPath;
        }
        const std::string ShaderProgram::getFragmentShaderPath(){
            return fragmentShaderPath;
        }
        const std::string ShaderProgram::getGeometryShaderPath(){
            return geometryShaderPath;
        }