#include <SFML/Graphics.hpp>
#include <iostream>

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

Player::Player() : velocity(0.f, 0.f), jumping(false){
    texture.loadFromFile("ub.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);

    sprite.setPosition(400.f, 300.f);
    sprite.setScale(2, 2);
}

void Player::update() {
    velocity.x *= drag;
    sprite.move(velocity);

    if (velocity.x > 0) {
        sprite.setScale(2, 2);
        sprite.setOrigin(0.f, 0.f);
    }
    else if (velocity.x < 0) {
        sprite.setScale(-2, 2);
        sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, 0);
    }

    velocity.y += gravity;

    if (sprite.getPosition().y >= 300.f) {
        velocity.y = 0.f;
        jumping = false;
        sprite.setPosition(sprite.getPosition().x, 300.f);
    }
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= acceleration;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += acceleration;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumping ) {
        velocity.y = jumpSpeed;
        jumping = true;
        
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

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
