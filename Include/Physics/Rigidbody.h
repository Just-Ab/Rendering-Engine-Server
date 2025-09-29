#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <Algebra/glm/glm.hpp>

class Rigidbody
{
private:
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
    glm::vec3 forceAccumulator;
    float mass;
public:
    Rigidbody(float _mass);
    void update(float delta);
    void applyForce(glm::vec3 force);
    void applyForce(glm::vec3 normal,float length);

    const glm::vec3& getPosition();
};





#endif 