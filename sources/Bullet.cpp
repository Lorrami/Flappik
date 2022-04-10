#include "Bullet.h"
#include "Bird.h"

Bullet::Bullet(float x, float y) {
    this->m_FirstPosX = x;
    this->m_FirstPosY = y;
    m_PosX = m_FirstPosX;
    m_PosY = m_FirstPosY;
    Texturing();
    setPosition(sf::Vector2f(m_PosX, m_PosY));
    setSize(sf::Vector2f(20, 30));
}

void Bullet::Update(float dt) {
    if(Level::Get().IsGameStarted) {
        PositionUpdate(dt);
        CollisionCheck();
    }
}

void Bullet::PositionUpdate(float dt) {
    if (!Level::Get().IsCrashed) {
        m_PosY += m_Speed * dt;
        setPosition(sf::Vector2f(m_PosX, m_PosY));
    }
    BordersUpdate();
}

void Bullet::BordersUpdate() {
    if(m_PosY >= 730) {
        m_PosY = m_FirstPosY;
    }
}

void Bullet::CollisionCheck() {
    if (Bird::Get().getGlobalBounds().findIntersection(this->getGlobalBounds())) {
        Level::Get().IsCrashed = true;
    }
}

void Bullet::Texturing() {
    auto *texture = new sf::Texture();
    texture->loadFromFile("../Sprites/bullet.png");
    setTexture(texture);
}