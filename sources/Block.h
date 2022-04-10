#ifndef MAIN_CPP_BLOCK_H
#define MAIN_CPP_BLOCK_H


#include "GameObject.h"

class Block : public GameObject {
private:
    float m_FirstPosX, m_FirstPosY;
    float m_PosX, m_PosY;
    float m_Speed = 300.0f;
private:
    void PositionUpdate(float dt);
    void BordersUpdate();
    void Texturing();
public:
    Block(float x, float y);
    void Update(float dt) override;

    void CollisionCheck();
};


#endif //MAIN_CPP_BLOCK_H
