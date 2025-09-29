
#include <Rendering/Camera2D.h>


    Camera2D::Camera2D(glm::vec3 position,float projectionWidth,float projectionHeight,float near,float far)
    :Camera(position,projectionWidth,projectionHeight,near,far)
    {
        cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        // float aspect = (float)width/height;
        // projection = glm::ortho(-aspect,aspect,-1.0f,1.0f,near,far);
        projection = glm::ortho(-(projectionWidth/2),projectionWidth/2,-(projectionHeight/2),projectionHeight/2,near,far);

        update();
    }

    void Camera2D::update(){

        // cameraFront.y = sin(glm::radians(roll));
        // cameraFront.x = cos(glm::radians(roll));

        Camera::update();
    }

    glm::mat4 Camera2D::getView(){
        update();
        view = glm::translate(glm::mat4(1.0f),-cameraPosition);
        return view;
    }

    void Camera2D::move(const uint8_t direction,float delta)
    {
        update();
        if(direction==RIGHT){
            cameraPosition -= axisVectorX * velocity*delta;
        }
        if(direction==LEFT){
            cameraPosition += axisVectorX * velocity*delta;

        }
        if(direction==DOWN){
            cameraPosition += axisVectorY * velocity*delta;

        }
        if(direction==UP){
            cameraPosition -= axisVectorY * velocity*delta;
        }
        
        std::cout<<cameraPosition.x <<","<<cameraPosition.y <<","<<cameraPosition.z<<std::endl;
    }

    void Camera2D::rotate(float _roll){
        // roll+=_roll;
    }
