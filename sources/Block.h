#ifndef MAIN_CPP_BLOCK_H
#define MAIN_CPP_BLOCK_H


#include "GameObject.h"

class Block : public GameObject {
private:
    int m_file = 0;
    float m_PosX, m_PosY;
    float m_Speed = 300.0f;
    float m_t = 0;
private:
    void PositionUpdate(float dt);
    void BordersUpdate();
    void CollisionCheck();
    void BirdCheck(float dt);
    void Texturing();
public:
    Block(float x, float y);
    void Update(float dt) override;
};


#endif //MAIN_CPP_BLOCK_H
