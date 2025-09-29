#include <Rendering/GridSprite.h>

GridSprite::GridSprite(unsigned int _width,unsigned int _height,GLenum _internalFormat,GLenum _format,GLenum _contentType){
    vertices = PrimitiveShapes::SpriteQuad.vertices;
    indices = PrimitiveShapes::SpriteQuad.indices;
    width = _width;
    height=_height;
    internalFormat=_internalFormat;
    format=_format;
    contentType=_contentType;
    setup();
}

void GridSprite::setup(){    
    vao.bind();
    vbo.setVertices(vertices);
    EBO ebo(indices);
    vbo.unBind();
    vao.unBind();
    texture.bind();

    texture.createNullTexture(width,height,internalFormat,format,contentType);

    int maxChunkWidth = 32;
    int maxChunkHeight = 32;

    int xChunks = (width  + maxChunkWidth  - 1) / maxChunkWidth;;
    int yChunks = (height  + maxChunkHeight  - 1) / maxChunkHeight;;

    int baseChunkWidth = width/xChunks;
    int baseChunkHeight = height/yChunks;

    int xExtraChunks = width%xChunks;
    int yExtraChunks = height%yChunks;

    std::vector<unsigned char> _data;

    int yOffset=0;
    for (int y = 0; y < yChunks; y++)
    {
        int curretChunkHeight = baseChunkHeight + (y<yExtraChunks?1:0);
        int xOffset=0;
        for (int x = 0; x < xChunks; x++)
        {
            int curretChunkWidth = baseChunkWidth + (x<xExtraChunks?1:0);
            _data.assign(curretChunkHeight*curretChunkWidth*3,(x+y)*10);
            textureChunks.push_back({
                _data,
                glm::ivec2(xOffset,yOffset),
                glm::ivec2(curretChunkWidth,curretChunkHeight
            )});
            xOffset += curretChunkWidth;
        }    
        yOffset += curretChunkHeight;
    }

    cellToChunk.resize(width * height, {-1, -1});
    for (int i = 0; i < (int)textureChunks.size(); i++) {
        auto& c = textureChunks[i];
        for (int yy = 0; yy < c.resolution.y; yy++) {
            for (int xx = 0; xx < c.resolution.x; xx++) {
                int gx = c.offset.x + xx;
                int gy = c.offset.y + yy;
                int globalIdx = gx + gy * width;
                int localIdx  = xx + yy * c.resolution.x;
                cellToChunk[globalIdx] = {i, localIdx};
            }
        }
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    for (int i = 0; i < textureChunks.size(); i++)
    {
        chunk tChunk = textureChunks[i];
        texture.setTextureData(tChunk.offset.x,tChunk.offset.y,tChunk.resolution.x,tChunk.resolution.y,tChunk.data.data());
    }   
    chunksIndicesRecord.assign(textureChunks.size(),0);
}


void GridSprite::setCell(int idx,const iColor & _hue){
    if(idx<0||idx>=width*height){return;}
    auto [chunkIdx, localIdx] = cellToChunk[idx];
    if (chunkIdx == -1) return;

    // textureChunks[chunkIdx].data[localIdx*3] = _hue.R;
    // textureChunks[chunkIdx].data[localIdx*3+1] = _hue.G;
    // textureChunks[chunkIdx].data[localIdx*3+2] = _hue.B;

    textureChunks[chunkIdx].data[localIdx*3] = _hue.R;
    textureChunks[chunkIdx].data[localIdx*3+1] = _hue.G;
    textureChunks[chunkIdx].data[localIdx*3+2] = _hue.B;
    chunksIndicesRecord[chunkIdx]=1;
}

void GridSprite::setCell(int x,int y,const iColor& _hue){
    int idx = x + y * width;
    setCell(idx,_hue);
}

void GridSprite::setCell(glm::ivec2 position,const iColor& _hue){
    int idx = position.x + position.y * width;
    setCell(idx,_hue);
}

void GridSprite::draw(Shader& shader,unsigned int instances){
    shader.activate();
    vao.bind();
    glActiveTexture(GL_TEXTURE0);

    for (int i = 0; i < chunksIndicesRecord.size(); i++)
    {
        if(!chunksIndicesRecord[i]){
            continue;
        }
        chunk tChunk = textureChunks[i];
        texture.setTextureData(tChunk.offset.x,tChunk.offset.y,tChunk.resolution.x,tChunk.resolution.y,tChunk.data.data());     }
    
    chunksIndicesRecord.assign(textureChunks.size(),0);

    texture.bind();
    glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instances);
    glBindTexture(GL_TEXTURE_2D,0);
    vao.unBind();
    shader.disactivate();
}

void GridSprite::draw(Shader& shader,std::vector<SpriteDataInstance>& instances){
    shader.activate();
    vao.bind();
    glActiveTexture(GL_TEXTURE0);

    for (int i = 0; i < chunksIndicesRecord.size(); i++)
    {
        if(!chunksIndicesRecord[i]){
            continue;
        }
        chunk tChunk = textureChunks[i];
        texture.setTextureData(tChunk.offset.x,tChunk.offset.y,tChunk.resolution.x,tChunk.resolution.y,tChunk.data.data());}
    
    chunksIndicesRecord.assign(textureChunks.size(),0);

    texture.bind();
    setInstances(instances);
    glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instances.size());
    glBindTexture(GL_TEXTURE_2D,0);
    vao.unBind();
    shader.disactivate();
}
