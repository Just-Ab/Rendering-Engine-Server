#ifndef VBO_H
#define VBO_H

#include <Rendering/OpenGl/glad/glad.h>
// #include <Rendering/OpenGl/GLFW/glfw3.h>
#include <vector>
#include <Types.hpp>


template<typename VertexT,typename InstanceDataT>
class VBO
{
private:
    unsigned ID;
    unsigned int instancesAllocated=0;
public:

    VBO();

    VBO(std::vector<VertexT>& vertices);
    void setVertices(std::vector<VertexT>& vertices);

    void setInstances(std::vector<InstanceDataT>& data);
    void allocateData(size_t size,GLenum type);

    unsigned int getId() const;
    void bind();
    void unBind();
};



#endif