#include "Level.h"
#include "Bird.h"
#include "Block.h"

Level *Level::s_Instance = nullptr;

void Level::Initialize() {
    AddingObjects();
    BackgroundSettings();
}

void Level::Update(float dt) {
    for(auto obj : m_Objects) {
        obj->Update(dt);
    }
}

void Level::Draw(sf::RenderWindow *window) {
    window->draw(*m_Background);

    for(auto obj : m_Objects) {
        window->draw(*obj);
    }
}

void Level::AddingObjects() {
    m_Objects.push_back(new Bird());
    m_Objects.push_back(new Block(0, -100));
}

void Level::BackgroundSettings() {
    m_Background = new sf::RectangleShape();
    auto *background_texture = new sf::Texture();
    background_texture->loadFromFile("../Sprites/fone.png");
    m_Background->setTexture(background_texture);
    m_Background->setSize(sf::Vector2f(700, 700));
}

Level &Level::Get() {
    if(s_Instance == nullptr) {
        s_Instance = new Level();
    }
    return *s_Instance;
}