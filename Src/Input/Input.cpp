
#include <Input/Input.h>

    
    bool Input::isKeyPressed(GLenum key){
        const bool isPressed = glfwGetKey(window,key)==GLFW_PRESS;
        if (isPressed){
            return true;
        }
        return false;
    }


    bool Input::isKeyJustPressed(GLenum key){
        const bool isPressed = (glfwGetKey(window,key)==GLFW_PRESS);
        if (isPressed && key!=prevKey){
            prevKey = key;
            return true;
        }
        if(!isPressed && key==prevKey){
            prevKey=GLFW_KEY_UNKNOWN;
        }
        return false;
    }

    std::pair<float,float> Input::getMouseOffset(float mouseX,float mouseY,float sensitivity){
        float offsetX = mouseX - prevMousePoX;
        float offsetY = prevMousePoY - mouseY;

        prevMousePoX = mouseX;
        prevMousePoY = mouseY;

        std::pair<float,float> result;
        result.first = offsetX * sensitivity;
        result.second = offsetY * sensitivity;

        return result;


    }