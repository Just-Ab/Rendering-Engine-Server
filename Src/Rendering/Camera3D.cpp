
#include <Rendering/Camera3D.h>


    Camera3D::Camera3D(glm::vec3 position,float FOV,float projectionHeight,float projectionWidth,float near,float far)
    :Camera(position,projectionHeight,projectionWidth,near,far)
    {
        if(near<=0.0f){
            std::cerr<<"Dividing on 0, Check Camera Setup!"<<std::endl;
            near = 0.1f;
        }
        yaw=-90.0f;
        projection = glm::perspective(glm::radians(FOV),((float)projectionWidth)/((float)projectionHeight),near,far);
        update();
    }

    void Camera3D::update(){
        cameraFront.x = cos( glm::radians(yaw))*cos( glm::radians(pitch) );
        cameraFront.y = sin( glm::radians(pitch)); 
        cameraFront.z = sin( glm::radians(yaw))*cos( glm::radians(pitch) );
        cameraFront = glm::normalize(cameraFront);
        Camera::update();
    }
    
    void Camera3D::move(const uint8_t direction,float delta){
        update();
        if(direction==RIGHT){
            cameraPosition -= axisVectorX * velocity*delta;
        }
        if(direction==LEFT){
            cameraPosition += axisVectorX * velocity*delta;

        }
        if(direction==FORWARD){
            cameraPosition -= axisVectorZ * velocity*delta;

        }
        if(direction==BACKWARD){
            cameraPosition += axisVectorZ * velocity*delta;
        }
        if(direction==UP){
            cameraPosition -= axisVectorY * velocity*delta;

        }
        if(direction==DOWN){
            cameraPosition += axisVectorY * velocity*delta;
        }
        // std::cout<<cameraPosition.x <<","<<cameraPosition.y <<","<<cameraPosition.z<<std::endl;
    }

    void Camera3D::rotate(float _yaw,float _pitch){
        yaw+=_yaw;
        pitch+=_pitch;
        if(pitch > 89.0f)
        pitch =  89.0f;
        if(pitch < -89.0f)
        pitch = -89.0f;
    }

    glm::vec3 Camera3D::getPosition(){
        return cameraPosition;
    }

    glm::vec3 Camera3D::getDirection(){
        return cameraFront;
    }
