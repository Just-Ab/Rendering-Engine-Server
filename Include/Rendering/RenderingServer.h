#ifndef RENDERINGSERVER_H
#define RENDERINGSERVER_H


class RenderingServer
{
private:
        RenderingServer*server;

        RenderingServer(){}

public:
    
        RenderingServer getSingleton();

};

RenderingServer::RenderingServer(/* args */)
{
}

RenderingServer::~RenderingServer()
{
}





#endif