#include <Window/Window.h>


Window::Window(std::string name,int _width,int _height){
    this->width=_width;this->height=_height;

    if(!glfwInit()){
        std::cout<<"Failed initializing GLFW!"<<std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    window=glfwCreateWindow(width,height,name.c_str(),NULL,NULL);

    if(!window){
        std::cout<<"Failed initializing Window!"<<std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout<<"Failed initializing GLAD!"<<std::endl;
        exit(EXIT_FAILURE);
    }
    glClearColor(0.3f,0.3f,0.3f,1.0f);
}

GLFWwindow *Window::getGLFWWindow(){return window;}

bool Window::shouldClose(){
    return glfwWindowShouldClose(window);
}

void Window::swapBuffer(){
    glfwSwapBuffers(window);
}

int Window::getHeight(){return height;}

int Window::getWidth(){return width;}

void Window::errorCallBack(int error,const char* description){
    std::cout<<description<<std::endl;;
}

void Window::close(){
    glfwSetWindowShouldClose(window,1);
}

void Window::destroy(){
    glfwDestroyWindow(window);
}

