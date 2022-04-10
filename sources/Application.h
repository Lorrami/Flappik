#ifndef MAIN_CPP_APPLICATION_H
#define MAIN_CPP_APPLICATION_H


#include <SFML/Graphics.hpp>
#include "Level.h"

class Application {
    static Application *s_Instance;
private:
    sf::RenderWindow *m_MainWindow;
    sf::Clock clock;
    Level *m_Level;
private:
    Application();
public:
    void Run();

    static Application &Get();
};


#endif //MAIN_CPP_APPLICATION_H
