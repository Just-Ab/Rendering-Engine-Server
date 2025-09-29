#ifndef CAMERA_H
#define CAMERA_H

#include <Rendering/OpenGl/glad/glad.h>

#include <Algebra/glm/glm.hpp>
#include <Algebra/glm/gtc/matrix_transform.hpp>
#include <Algebra/glm/gtc/type_ptr.hpp>

#include <iostream>

    class Camera{

        protected:
            const glm::vec3 VECTOR_WORLD_UP=glm::vec3(0.0f,1.0f,0.0f); 

            glm::mat4 projection = glm::mat4(1.0f), view = glm::mat4(1.0f);

            glm::vec3 axisVectorX,axisVectorY,axisVectorZ,cameraPosition,cameraFront=glm::vec3(0.0f,0.0f,-1.0f);



        public:
            const uint8_t RIGHT=0,LEFT=1,UP=2,DOWN=3,FORWARD=4,BACKWARD=5;
            Camera(glm::vec3 position,float width,float height,float near,float far);

            virtual void update();

            virtual glm::mat4 getView();

            glm::mat4 getProjection();
            
    };
    
#endif 
