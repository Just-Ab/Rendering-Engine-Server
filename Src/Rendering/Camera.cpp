
#include <Rendering/Camera.h>


    Camera::Camera(glm::vec3 position,float height,float width,float near,float far){
        cameraPosition = position;
        update();
    }

    void Camera::update(){

        axisVectorZ = glm::normalize(-cameraFront);
        axisVectorX = glm::normalize(glm::cross(axisVectorZ,VECTOR_WORLD_UP));
        axisVectorY = glm::cross(axisVectorZ,axisVectorX);
    }
    

    glm::mat4 Camera::getView(){
        update();
        view = glm::lookAt(cameraPosition,cameraPosition+cameraFront,VECTOR_WORLD_UP);
        return view;
    }
    glm::mat4 Camera::getProjection(){
        return projection;
    }
    

    