#include <SFML/Graphics.hpp>
#include"Player.h"
#include "iostream"
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Player Example");
    window.setFramerateLimit(60);

    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        player.handleInput();
        player.update();

        window.clear();
        player.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
