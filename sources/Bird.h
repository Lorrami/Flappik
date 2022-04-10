#ifndef MAIN_CPP_BIRD_H
#define MAIN_CPP_BIRD_H


#include "GameObject.h"

class Bird : public GameObject {
    static Bird s_Instance;
private:
    float m_PosX = 340.0f, m_PosY = 360.0f;
    float m_SizeX = 42.0f, m_SizeY = 29.0f;
    float m_Speed = 300.0f, m_AnimationSpeed = m_Speed / 2;
    bool m_LeftMove = true;
private:
    void KeyboardCheck(float dt);
    void PositionUpdate();
    void Texturing();
    void FirstAnimation(float dt);
public:
    Bird();
    void Update(float dt) override;

    static Bird &Get();
};


#endif //MAIN_CPP_BIRD_H
