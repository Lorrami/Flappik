#include <iostream>
#include <cstdio>
#include <sstream>
#include "Level.h"
#include "Bird.h"
#include "Block.h"

Level *Level::s_Instance = nullptr;

void Level::Initialize() {
    m_Font->loadFromFile("../Sprites/Text1.ttf");
    StartText();
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
    if(!IsGameStarted) {
        window->draw(*EntryText);
    }
    for(auto obj: m_Objects) {
        window->draw(*obj);
    }
}

void Level::FileWriter() const {
    FILE * records;
    records = fopen ("../Records.txt","w");
    if(records != nullptr)
    {
        int i_Record = (int)(ceil(Record / 2));
        char array[10];
        sprintf(array, "%i", i_Record);
        fputs(array,records);
        fclose(records);
    }
}

void Level::AddingObjects() {
    m_Objects.push_back(&Bird::Get());
    //m_Objects.push_back(new Bullet(340.0f, -30.0f));
    m_Objects.push_back(new Block(-250, -100));
    m_Objects.push_back(new Block(450, -100));
    m_Objects.push_back(new Block(-250, -510));
    m_Objects.push_back(new Block(450, -510));
}

void Level::BackgroundSettings() {
    m_Background = new sf::RectangleShape();
    auto *background_texture = new sf::Texture();
    background_texture->loadFromFile("../Sprites/fone.png");
    m_Background->setTexture(background_texture);
    m_Background->setSize(sf::Vector2f(700, 700));
}

void Level::StartText() {
    EntryText = new sf::Text("Flappik", *m_Font, 60);
    EntryText->setFillColor(sf::Color::Black);
    EntryText->setPosition(sf::Vector2f(265, 200));
}

Level &Level::Get() {
    if(s_Instance == nullptr) {
        s_Instance = new Level();
    }
    return *s_Instance;
}

