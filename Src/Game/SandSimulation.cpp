#include <Game/SandSimulation.h>

SandSimulation::SandSimulation(unsigned int _width,unsigned int _height){
    width = _width;
    height = _height;
    size = _width * _height;
}

void SandSimulation::init(){
    frontmapData.assign(size, air);
    for (int y= 0; y < width/2; y++)
    {
        for (int x= 0; x < height; x++)
        {
            if(x<30||x>80){continue;}
            frontmapData[index(x,y)]=sand;
        }    
    }
    
    
}

int SandSimulation::index(int x, int y){
    if(x < 0 || x >= (int)width || y < 0 || y >= (int)height) return -1;
    return x + y * width;
}

void SandSimulation::update(){
    backmapData = frontmapData;
    dirtyCells.clear();

    int dir = rand() % 2;
    int xStart = dir ? 0 : width - 1;
    int xStep  = dir ? 1 : -1;
    int xEnd   = dir ? width : -1;

    for(int y = (int)height - 1; y >= 0; y--){
        for(int x = xStart; x != xEnd; x += xStep){
            int selfIdx = index(x, y);
            if(selfIdx == -1) continue;
            material materialSelf = frontmapData[selfIdx];

            if(materialSelf.type == SAND){
                int indexRight   = index(x+1, y);
                int indexLeft    = index(x-1, y);
                int indexBCenter = index(x, y+1);
                int indexBRight  = index(x+1, y+1);
                int indexBLeft   = index(x-1, y+1);

                material materialRight   = (indexRight == -1)   ? voidMaterial : frontmapData[indexRight];
                material materialLeft    = (indexLeft == -1)    ? voidMaterial : frontmapData[indexLeft];
                material materialBCenter = (indexBCenter == -1) ? voidMaterial : frontmapData[indexBCenter];
                material materialBRight  = (indexBRight == -1)  ? voidMaterial : frontmapData[indexBRight];
                material materialBLeft   = (indexBLeft == -1)   ? voidMaterial : frontmapData[indexBLeft];

                if(materialBCenter.type == AIR && backmapData[indexBCenter].type == AIR){
                    backmapData[indexBCenter] = materialSelf;
                    backmapData[selfIdx] = air;
                    dirtyCells.push_back(selfIdx);
                    dirtyCells.push_back(indexBCenter);
                }
                else if(materialBLeft.type == AIR && backmapData[indexBLeft].type == AIR &&
                        materialBRight.type == AIR && backmapData[indexBRight].type == AIR){
                    dir = rand() % 2;
                    if(dir == 0){
                        backmapData[indexBRight] = materialSelf;
                        backmapData[selfIdx] = air;
                        dirtyCells.push_back(selfIdx);
                        dirtyCells.push_back(indexBRight);
                    } else {
                        backmapData[indexBLeft] = materialSelf;
                        backmapData[selfIdx] = air;
                        dirtyCells.push_back(selfIdx);
                        dirtyCells.push_back(indexBLeft);
                    }
                }
                else if(materialBRight.type == AIR && backmapData[indexBRight].type == AIR){
                    backmapData[indexBRight] = materialSelf;
                    backmapData[selfIdx] = air;
                    dirtyCells.push_back(selfIdx);
                    dirtyCells.push_back(indexBRight);
                }
                else if(materialBLeft.type == AIR && backmapData[indexBLeft].type == AIR){
                    backmapData[indexBLeft] = materialSelf;
                    backmapData[selfIdx] = air;
                    dirtyCells.push_back(selfIdx);
                    dirtyCells.push_back(indexBLeft);
                }
                else{
                    backmapData[selfIdx] = materialSelf;
                }
            }
            else if(materialSelf.type == BLOCK){
                backmapData[selfIdx] = materialSelf;
            }
        }
    }

    frontmapData.swap(backmapData);
}

const std::vector<SandSimulation::material>& SandSimulation::getmapData(){
    return frontmapData;
}

const SandSimulation::material& SandSimulation::getCell(unsigned int x,unsigned int y){
    int idx = index(x,y);
    return (idx==-1?voidMaterial:getmapData()[idx]);
}

const std::vector<unsigned int>& SandSimulation::getdirtyCells(){
    return dirtyCells;
}
