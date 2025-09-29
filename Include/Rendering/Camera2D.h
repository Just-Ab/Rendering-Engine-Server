#ifndef CAMERA2D_H
#define CAMERA2D_H

#include <Rendering/Camera.h>

    class Camera2D:public Camera{

        private:
            float roll;
            float velocity=1.0f;

        public:
            Camera2D(glm::vec3 position,float projectionWidth,float projectionHeight,float near,float far);
            void update() override;
            glm::mat4 getView() override;
            void rotate(float _roll);
            void move(const uint8_t direction,float delta);

    };
    
#endif 
