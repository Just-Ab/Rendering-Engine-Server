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

// struct ColorRectVertex{
//     glm::vec3 position;
// };

// struct ColorRectDataInstance{
//     glm::vec2 position;
//     float hue;

// };



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


