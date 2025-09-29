#include <Window/Window.h>
#include <Rendering/Shader.h>
#include <Rendering/Camera2D.h>
#include <Input/Input.h>
#include <Rendering/Buffers/UBO.h>
#include <Rendering/Sprite.h>
#include <Game/SandSimulation.h>
#include <Physics/Rigidbody.h>
#include <time.h>

constexpr int WIDTH = 900;
constexpr int HEIGHT = 900;



Window window("Window",WIDTH,HEIGHT);
Camera2D camera(glm::vec3(0.0f,0.0f,0.0f),450.0f,450.0f,-1.0f,1.0f);
Sprite sprite;
Input input(window);

Shader spriteShader("Assets/Shaders/Sprite.vert","Assets/Shaders/Sprite.frag");

UBO matrices(sizeof(glm::mat4)*2);

Rigidbody rb(10.0f);

int main(int argc, char const *argv[])
{
    matrices.setData(0,sizeof(glm::mat4),glm::value_ptr(camera.getProjection()));
    matrices.setData(sizeof(glm::mat4),sizeof(glm::mat4),glm::value_ptr(camera.getView()));
    matrices.bindToIndex(0);

    spriteShader.bindUniformBlock("matrices",0);
    spriteShader.setInstanceAttributes({
        {2,2,GL_FLOAT,0}
    });
    spriteShader.setVertexAttributes({
        {0,3,GL_FLOAT,0},{1,2,GL_FLOAT,12}
    });

    glfwSwapInterval(1);

    double prevTime,currentTime,delta=1.0f/60.0f;
    prevTime=glfwGetTime();
    double timer=0.00;

    sprite.defineVertexAttributes(spriteShader.getVertexAttributes());
    sprite.defineInstanceAttributes(spriteShader.getInstanceAttributes());
    std::vector<SpriteDataInstance> spriteInstances={{glm::vec2(0.0f)}};
    sprite.setTexture("Assets/Textures/grid.png");
    while (!window.shouldClose())
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        currentTime = glfwGetTime();
        delta = currentTime-prevTime;
        prevTime = currentTime;
        if(input.isKeyPressed(GLFW_KEY_LEFT)){
            rb.applyForce(glm::vec3(-70.0f,0.0f,0.0f));
        }
        if(input.isKeyPressed(GLFW_KEY_RIGHT)){
            rb.applyForce(glm::vec3(70.0f,0.0f,0.0f));
        }
        rb.update(delta);
        spriteInstances[0]=(SpriteDataInstance){glm::vec2(rb.getPosition().x,rb.getPosition().y)};
        sprite.draw(spriteShader,spriteInstances);

        std::cout<<"("<<rb.getPosition().x<<','<<rb.getPosition().y<<','<<rb.getPosition().z<<") time: "<<currentTime<<'\n';
        



        timer+=delta;
        if (timer>=2){
            timer=0;
            std::cout<<"FPS: "<<1.0f/delta<<'\n';
        }
        window.swapBuffer();
    }
    window.destroy();
    glfwTerminate();
    return 0;
}




