#ifndef MAIN_CPP_GAMEOBJECT_H
#define MAIN_CPP_GAMEOBJECT_H


#include <SFML/Graphics.hpp>

class GameObject : public sf::RectangleShape {
public:
    virtual void Update(float dt) = 0;
};


#endif //MAIN_CPP_GAMEOBJECT_H
