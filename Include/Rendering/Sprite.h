#ifndef SPRITE_H
#define SPRITE_H

#include<Rendering/Entity.h>
#include<Rendering/Texture.h>

#include <vector>
#include <iostream>
#include <cstdint>

class Sprite:public Entity<SpriteVertex,SpriteDataInstance>
{
private:
    Texture texture;
    void setup();
public:
    Sprite();
    
    
    void setTexture(const char* path);
    void setTexture(Texture _texture);

    void draw(Shader& shader,unsigned int instances) override;
    void draw(Shader& shader,std::vector<SpriteDataInstance>& instances) override;

};


#endif