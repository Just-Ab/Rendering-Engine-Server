 #ifndef GRIDSPRITE_H
#define GRIDSPRITE_H

#include<Rendering/Entity.h>
#include<Rendering/Texture.h>
#include<Colors.hpp>

#include <vector>
#include <iostream>
#include <cstdint>
#include <unordered_set>


namespace std {
    template <>
    struct hash<glm::ivec2> {
        size_t operator()(const glm::ivec2& v) const noexcept {
            size_t h1 = std::hash<int>{}(v.x);
            size_t h2 = std::hash<int>{}(v.y);
            return h1 ^ (h2 << 1);
        }
    };
}

class GridSprite:public Entity<SpriteVertex,SpriteDataInstance>
{
private:

    struct chunk{
        std::vector<unsigned char> data;
        glm::ivec2 offset;
        glm::ivec2 resolution;
    };

    struct cellMap{
        int chunkindx;
        int cellidx;
    };

    std::vector<chunk> textureChunks;

    std::vector<unsigned char> textureData;
    std::vector<unsigned char> chunksIndicesRecord;

    std::vector<cellMap> cellToChunk;

    unsigned int width,height;
    GLenum internalFormat,format,contentType;
    Texture texture;
    void setup();
public:
    GridSprite(unsigned int _width,unsigned int _height,GLenum _internalFormat,GLenum _format,GLenum _contentType);
    
    void setCell(int idx,const iColor& _hue);
    void setCell(int x,int y,const iColor& _hue);
    void setCell(glm::ivec2 position,const iColor& _hue);

    void draw(Shader& shader,unsigned int instances) override;
    void draw(Shader& shader,std::vector<SpriteDataInstance>& instances) override;

};


#endif