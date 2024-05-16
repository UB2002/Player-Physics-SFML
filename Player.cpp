#include "Player.h"

Player::Player() : velocity(0.f, 0.f), jumping(false) {
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !jumping) {
        velocity.y = jumpSpeed;
        jumping = true;

    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}