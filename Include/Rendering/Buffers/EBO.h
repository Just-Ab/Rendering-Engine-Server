#ifndef EBO_H
#define EBO_H

#include <Rendering/OpenGl/glad/glad.h>
#include <Rendering/OpenGl/GLFW/glfw3.h>
#include <vector>




class EBO
{
private:
    unsigned ID;
public:
    EBO();
    EBO(std::vector<unsigned int> indices);

    void setIndices(std::vector<unsigned int> indices);

    unsigned int getId();

    void bind();

    void unBind();
};



#endif