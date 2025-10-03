#ifndef VBO_H
#define VBO_H

#include <Rendering/OpenGl/glad/glad.h>
// #include <Rendering/OpenGl/GLFW/glfw3.h>
#include <vector>
#include <Types.hpp>


class VBO
{
private:
    unsigned ID;
    unsigned int instancesAllocated=0,activeInstances=0;
public:

    VBO();

    VBO(const void* vertices,size_t size,GLenum usage);
    void setVertices(const void* vertices,size_t size,GLenum usage);
    void setInstances(const void* instancess,size_t stride,size_t count);
    void allocateData(size_t size,GLenum type);

    unsigned int getId() const;
    void bind();
    void unBind();
};



#endif