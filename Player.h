#pragma once
#include<SFML/Graphics.hpp>
class Player {
public:
    Player();
    void update();
    void handleInput();
    void draw(sf::RenderWindow& window);


private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f velocity;
    const float acceleration = 1.7f;
    const float drag = 0.75f;
    const float jumpSpeed = -17.f;
    const float gravity = 1.2f;
    bool jumping;

};
