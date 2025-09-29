#ifndef CAMERA3D_H
#define CAMERA3D_H

#include <Rendering/Camera.h>

    class Camera3D:public Camera{

        private:
            float yaw,pitch;
            float velocity=20.9f;

        public:
            Camera3D(glm::vec3 position,float FOV,float projectionWidth,float projectionHeight,float near,float far);
            void update() override;
            void rotate(float _yaw,float _pitch);
            void move(const uint8_t direction,float delta);
            glm::vec3 getPosition();
            glm::vec3 getDirection();
    };
    
#endif 
