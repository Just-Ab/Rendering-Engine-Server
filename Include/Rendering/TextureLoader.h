#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <Rendering/OpenGl/glad/glad.h>
#include <Rendering/OpenGl/GLFW/glfw3.h>

#include <Algebra/glm/glm.hpp>
#include <Algebra/glm/gtc/matrix_transform.hpp>
#include <Algebra/glm/gtc/type_ptr.hpp>

#include <Rendering/stb_image.h>

#include <Types.hpp>
#include <vector>
#include <iostream>


    class TextureLoader
    {
    public:
        unsigned int generateTexture(unsigned int width,unsigned int height,GLenum internalFormat,GLenum format,GLenum contentType);
        unsigned int loadTexture2D(std::string path);
        unsigned int loadCubeMap(std::vector<std::string> &path);

        // void use(GLenum where,GLenum unit);
    };


#endif