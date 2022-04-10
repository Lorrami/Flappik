#ifndef MAIN_CPP_LEVEL_H
#define MAIN_CPP_LEVEL_H


#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"

class Level {
    static Level *s_Instance;
private:
    sf::RectangleShape *m_Background;
private:
    void AddingObjects();
    void BackgroundSettings();
    void StartText();
public:
    void Initialize();
    void FileWriter() const;
    void Update(float dt);
    void Draw(sf::RenderWindow *window);
private:
    sf::Font *m_Font = new sf::Font();
    sf::Text *EntryText = new sf::Text();
public:
    std::vector<GameObject*> m_Objects;

    bool IsGameStarted = false;
    bool IsCrashed = false;
    float Record = 0;

    static Level &Get();
};


#endif //MAIN_CPP_LEVEL_H
