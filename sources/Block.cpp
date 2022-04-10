#include <iostream>
#include "Block.h"
#include "Level.h"
#include "Bird.h"

Block::Block(float x, float y) {
    this->m_FirstPosX = x;
    this->m_FirstPosY = y;
    m_PosX = m_FirstPosX;
    m_PosY = m_FirstPosY;
    Texturing();
    setPosition(sf::Vector2f(m_PosX, m_PosY));
    setSize(sf::Vector2f(500, 80));
}

void Block::Update(float dt) {
    if(Level::Get().IsGameStarted) {
        PositionUpdate(dt);
        CollisionCheck();
    }
}
void Block::PositionUpdate(float dt) {
    if (!Level::Get().IsCrashed) {
        m_PosY += m_Speed * dt;
        setPosition(sf::Vector2f(m_PosX, m_PosY));
    }
    BordersUpdate();
}

void Block::BordersUpdate() {
    if(m_PosY >= 780) {
        m_PosY = m_FirstPosY;
    }
}

void Block::CollisionCheck() {
    if (Bird::Get().getGlobalBounds().findIntersection(this->getGlobalBounds())) {
        Level::Get().IsCrashed = true;
    }
}

void Block::Texturing() {
    auto *texture = new sf::Texture();
    texture->loadFromFile("../Sprites/ground.png");
    setTexture(texture);
}
