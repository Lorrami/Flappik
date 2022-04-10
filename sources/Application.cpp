#include "Application.h"

Application *Application::s_Instance = nullptr;

Application::Application() {
    m_MainWindow = new sf::RenderWindow(sf::VideoMode(700, 700), "Flappik");
}

void Application::Run() {
    m_Level.Initialize();
    while(m_MainWindow->isOpen()) {
        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();

        m_MainWindow->clear();

        m_Level.Update(dt);
        m_Level.Draw(m_MainWindow);

        m_MainWindow->display();
    }
}

Application &Application::Get() {
    if(s_Instance == nullptr) {
        s_Instance = new Application();
    }
    return *s_Instance;
}
