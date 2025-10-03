#ifndef RENDERINGSERVER_H
#define RENDERINGSERVER_H

#include <Window/Window.h>
#include <Rendering/Instances/ColorRectInstance.h>
#include <Rendering/Instances/SpriteInstance.h>
#include <Rendering/Shader.h>

#include <vector>
#include <deque>

#include <string>
#include <memory>
class RenderingServer
{
private:



        static RenderingServer*server;
        
        std::unique_ptr<Window> window;
        
        std::deque<Shader> shaders;
        
        std::deque<Texture> textures;

        std::deque<ColorRectResource> colorRectResources;
        std::deque<ColorRectInstance> colorRectInstances;

        std::deque<SpriteResource> spriteResources;
        std::deque<SpriteInstance> spriteInstances;

        RenderingServer();

public:
        
        static RenderingServer* getSingleton();
        
        void createWindow(std::string name,unsigned int width,unsigned int height);
        Window* getWindow();

        Shader* createShader(std::string vertexShader,std::string fragmentShader,std::string geometryShader="");

        Texture* createTexture(std::string path);

        ColorRectInstance* createColorRect(unsigned int count=1);
        ColorRectInstance* createColorRect(Shader* _shader,unsigned int count=1);

        SpriteInstance* createSprite(Texture* texture,unsigned int count=1);
        SpriteInstance* createSprite(Texture* texture,Shader* _shader,unsigned int count=1);

        void beginFrame();
        void drawFrame();
        void endFrame();

        
        static void destroy();
};





#endif