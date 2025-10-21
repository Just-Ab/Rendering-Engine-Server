#ifndef RENDERINGSERVER_H
#define RENDERINGSERVER_H

#include <Window/Window.h>
#include <Rendering/Instances/ColorRectInstance.h>
#include <Rendering/Instances/SpriteInstance.h>

#include <Rendering/ShaderProgram.h>
#include <Rendering/Camera2D.h>

#include <vector>
#include <deque>

#include <string>
#include <memory>
class RenderingServer
{
private:



        static RenderingServer*server;
        
        std::unique_ptr<Window> window;
        
        Camera2D* currentCamera=nullptr;

        std::deque<ShaderProgram> shaderPrograms;
        
        std::deque<Texture> textures;

        std::deque<Camera2D> cameras;

        ColorRectResource *colorRectResource=nullptr;
        std::deque<ColorRectInstance> colorRectInstances;

        SpriteResource *spriteResource=nullptr;
        std::deque<SpriteInstance> spriteInstances;

        RenderingServer();

public:
        
        static RenderingServer* getSingleton();
        
        void initServer(std::string name,unsigned int width,unsigned int height);
        Window* getWindow();

        ShaderProgram* createShaderProgram(std::string vertexShaderProgram,std::string fragmentShaderProgram);
        ShaderProgram* createShaderProgram(std::string vertexShaderProgram,std::string fragmentShaderProgram,std::string geometryShaderProgram);

        Camera2D* createCamera2D(float width,float height,float near,float far);
        void makeCamera2DCurrent(Camera2D* camera);

        Texture* createTexture(std::string path);

        ColorRectInstance* createColorRect();
        ColorRectInstance* createColorRect(ShaderProgram* _ShaderProgram);

        SpriteInstance* createSprite(Texture* texture);
        SpriteInstance* createSprite(Texture* texture,ShaderProgram* _ShaderProgram);

        void beginFrame();
        void drawFrame();
        void endFrame();

        
        static void destroy();
};





#endif