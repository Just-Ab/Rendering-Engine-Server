#ifndef UBO_H
#define UBO_H

#include <Rendering/OpenGl/glad/glad.h>
#include <Rendering/OpenGl/GLFW/glfw3.h>
#include <vector>




class UBO
{
private:
    unsigned ID;
public:
    
    UBO(size_t size);

    void bindToIndex(unsigned int index);
    void setData(size_t offset,size_t size,const void* data);



    unsigned int getId();

    void bind();
    void unBind();


};



#endif