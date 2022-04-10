#include "Bird.h"
#include "Block.h"
#include "Level.h"
#include <iostream>

Bird Bird::s_Instance;

Bird::Bird() {
    setPosition(sf::Vector2f(m_PosX, m_PosY));
    setSize(sf::Vector2f(m_SizeX, m_SizeY));
//    setOrigin(sf::Vector2f(m_SizeX/2, m_SizeY/2));
    Texturing();
}

void Bird::Update(float dt) {
    if(!Level::Get().IsGameStarted) {
        FirstAnimation(dt);
    }
    KeyboardCheck(dt);
    PositionUpdate();
}

void Bird::PositionUpdate() {
    if(!Level::Get().IsCrashed) {
        setPosition(sf::Vector2f(m_PosX, m_PosY));
    }
}

void Bird::KeyboardCheck(float dt) {
    if(m_PosX < 679.0f) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            m_PosX += m_Speed * dt;
            Level::Get().IsGameStarted = true;
        }
    }
    if(m_PosX > 21.0f) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_PosX -= m_Speed * dt;
            Level::Get().IsGameStarted = true;
        }
    }
}

void Bird::Texturing() {
    auto *texture = new sf::Texture();
    texture->loadFromFile("../Sprites/bird.png");
    setTexture(texture);
}

void Bird::FirstAnimation(float dt) {
    if (m_LeftMove) {
        m_PosX -= m_AnimationSpeed * dt;
        if (m_PosX <= 310.0f)
            m_LeftMove = false;
    }
    if (!m_LeftMove) {
        m_PosX += m_AnimationSpeed * dt;
        if (m_PosX >= 370.0f)
            m_LeftMove = true;
    }
}

Bird &Bird::Get() {
    return s_Instance;
}