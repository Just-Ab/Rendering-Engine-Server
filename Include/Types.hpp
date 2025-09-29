#pragma once
#include <Algebra/glm/glm.hpp>
#include <Algebra/glm/gtc/quaternion.hpp>
#include <vector>
#include <string>

enum FrameBufferTypes
    {
        TEXTURE_COLOR,
        TEXTURE_DEPTH,
        TEXTURE_DEPTH24,
        TEXTURE_STENCIL,
        TEXTURE_DEPTH_STENCIL,

        RBO_COLOR,
        RBO_DEPTH,
        RBO_DEPTH24,
        RBO_STENCIL,
        RBO_DEPTH_STENCIL
    };


template<typename vertexT>
struct Shape{
    std::vector<vertexT> vertices;
    std::vector<unsigned int> indices;
};


struct ColorRectVertex{
    glm::vec3 position;
};

struct ColorRectDataInstance{
    glm::vec2 position;
    float hue;

};

struct SpriteVertex{
    glm::vec3 position;
    glm::vec2 texel;
};

struct SpriteDataInstance{
    glm::vec2 position;
};

struct MeshVertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texel;
};

struct MeshDataInstance{
    glm::mat4 model;
    };




inline GLsizei glTypeSize(GLenum type) {
    switch (type) {
        case GL_BYTE:           return sizeof(GLbyte);
        case GL_UNSIGNED_BYTE:  return sizeof(GLubyte);
        case GL_SHORT:          return sizeof(GLshort);
        case GL_UNSIGNED_SHORT: return sizeof(GLushort);
        case GL_INT:            return sizeof(GLint);
        case GL_UNSIGNED_INT:   return sizeof(GLuint);
        case GL_HALF_FLOAT:     return sizeof(GLhalf);
        case GL_FLOAT:          return sizeof(GLfloat);
        case GL_DOUBLE:         return sizeof(GLdouble);
        default: return 0;
    }
}


