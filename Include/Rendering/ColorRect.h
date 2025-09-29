#ifndef COLORRECT_H
#define COLORRECT_H


#include <Rendering/Entity.h>

#include <Colors.hpp>
#include <vector>
#include <iostream>
#include <cstdint>

class ColorRect:public Entity<ColorRectVertex,ColorRectDataInstance>
{
private:

    ColorA color;
    void setup();

public:
    ColorRect();

    void setColor(float _r,float _g,float _b,float _a);
    void setColor(fColor _color,float _a);

    void draw(Shader& shader,unsigned int instances) override;
    void draw(Shader& shader,std::vector<ColorRectDataInstance>& instances) override;
};




#endif