#include <Algebra/glm/glm.hpp>

#include <vector>
#include <Colors.hpp>

class SandSimulation
{
private:
    unsigned int width,height,size;

    static constexpr unsigned int VOID=0,AIR=1,SAND=2,BLOCK=3;

    struct material{
        unsigned int type;
        iColor color;
    };

    static constexpr material 
        voidMaterial={VOID,{0,0,0}},
        air={AIR,{10,90,170}},
        sand={SAND,{120,120,60}},
        stone={BLOCK,{150,150,150}};

    std::vector<material> backmapData,frontmapData;
    std::vector<unsigned int> dirtyCells;


    
public:
    SandSimulation(unsigned int width,unsigned int height);
    int index(int x,int y);
    void init();
    void update();
    const material& getCell(unsigned int x,unsigned int y);
    const std::vector<material>& getmapData();
    const std::vector<unsigned int>& getdirtyCells();

};