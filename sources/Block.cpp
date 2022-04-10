#include <iostream>
#include "Block.h"
#include "Level.h"
#include "Bird.h"

Block::Block(float x, float y) {
    this->m_PosX = x;
    this->m_PosY = y;
    Texturing();
    setPosition(sf::Vector2f(m_PosX, m_PosY));
    setSize(sf::Vector2f(200, 80));
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
}

void Block::CollisionCheck() {
    std::cout << Bird::Get().getGlobalBounds().top << std::endl;
    if (Bird::Get().getGlobalBounds().findIntersection(this->getGlobalBounds())) {
        Level::Get().IsCrashed = true;
        std::cout << "Crashed";
    }
}

void Block::Texturing() {
    auto *texture = new sf::Texture();
    texture->loadFromFile("../Sprites/ground.png");
    setTexture(texture);
}
