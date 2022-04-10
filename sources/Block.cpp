#include <iostream>
#include "Block.h"
#include "Level.h"
#include "Bird.h"
#include <random>

Block::Block(float x, float y) {
    this->m_PosX = x;
    this->m_PosY = y;
    Texturing();
    setPosition(sf::Vector2f(m_PosX, m_PosY));
    setSize(sf::Vector2f(500, 80));
}

void Block::Update(float dt) {
    if(Level::Get().IsGameStarted) {
        PositionUpdate(dt);
        BirdCheck(dt);
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
        m_PosY = -100;
    }
}

void Block::CollisionCheck() {
    if (Bird::Get().getGlobalBounds().findIntersection(this->getGlobalBounds())) {
        Level::Get().IsCrashed = true;
        if(m_file == 0) {
            m_file++;
            Level::Get().FileWriter();
        }
        return;
    }
}

void Block::BirdCheck(float dt) {
    if((int)this->getPosition().y == 380) {
        Level::Get().Record += 0.25f;
        Bird::Get().WindSpeed = ((rand() % 3) - 1) * 100;
        std::cout << Bird::Get().WindSpeed << '\n';
    }
}

void Block::Texturing() {
    auto *texture = new sf::Texture();
    texture->loadFromFile("../Sprites/ground.png");
    setTexture(texture);
}
