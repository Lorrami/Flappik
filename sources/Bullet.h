#ifndef MAIN_CPP_BULLET_H
#define MAIN_CPP_BULLET_H

#include "Level.h"
#include "GameObject.h"

class Bullet : public GameObject {
private:
    float m_FirstPosX, m_FirstPosY;
    float m_PosX, m_PosY;
    float m_Speed = 450.0f;
public:
    Bullet(float x, float y);
    void Update(float dt) override;
    void PositionUpdate(float dt);
    void BordersUpdate();
    void CollisionCheck();
    void Texturing();
};


#endif //MAIN_CPP_BULLET_H
