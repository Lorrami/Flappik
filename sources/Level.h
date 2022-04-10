#ifndef MAIN_CPP_LEVEL_H
#define MAIN_CPP_LEVEL_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"

class Level {
    static Level *s_Instance;
private:
    std::vector<GameObject*> m_Objects;
    sf::RectangleShape *m_Background;
private:
    void AddingObjects();
    void BackgroundSettings();
public:
    void Initialize();
    void Update(float dt);
    void Draw(sf::RenderWindow *window);
public:
    bool IsGameStarted = false;
    bool IsCrashed = false;

    static Level &Get();
};


#endif //MAIN_CPP_LEVEL_H
