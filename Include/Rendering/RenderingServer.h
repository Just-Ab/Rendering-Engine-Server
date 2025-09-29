#ifndef RENDERINGSERVER_H
#define RENDERINGSERVER_H

#include <Window/Window.h>
#include <vector>
#include <string>
#include <memory>
class RenderingServer
{
private:
        static RenderingServer*server;
        
        std::unique_ptr<Window> window;
        
        RenderingServer();

public:
        
        static RenderingServer* getSingleton();
        
        void createWindow(std::string name,unsigned int width,unsigned int height);
        Window* getWindow();

        void beginFrame();
        void endFrame();

        
        static void destroy();
};





#endif