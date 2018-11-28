#ifndef HHH_PLAYER_H
#define HHH_PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants.h"

using namespace std;
using namespace sf;

class Player {
private:
    RectangleShape entity;
    Vector2f pos;
    Vector2f mot;
    Texture txtr;
public:
    Player();  // texture

    // loadPlayer();
    inline void show(RenderWindow& window);
    inline void update();

    void setPos(Vector2f& p);

    Vector2f getPos();
    Vector2f getMot();
};

Player::Player() {
entity = RectangleShape(PLAYER_SIZE);
entity.setPosition(PLAYER_ABS_POS); // This is the absolute position for the game (in center).
pos = Vector2f(0, 0);  // This is the position of the player (but technically it is the terrain's position)

if (!txtr.loadFromFile(RES_DIR+"no-texture.png")) {   // Loads the texture
    if (!txtr.loadFromFile(RES_DIR+"no-texture.png")) {
        cout << "[ERROR] Failed to load texture!\n";
        entity.setFillColor(Color(255, 0, 255));
    }
} else {
    cout << "Textured loaded successfully\n";
    entity.setTexture(&txtr);
}
}

void Player::show(RenderWindow& window) {
window.draw(entity);
}

void Player::update() {

if (Keyboard::isKeyPressed(Keyboard::W)) {  // get the keyboard input for movement
pos.y += SPEED;
mot.y = 1;
} else if (Keyboard::isKeyPressed(Keyboard::S)) {
pos.y -= SPEED;
mot.y = -1;
} else {
mot.y = 0;
}

if (Keyboard::isKeyPressed(Keyboard::A)) {
pos.x += SPEED;
mot.x = 1;
} else if (Keyboard::isKeyPressed(Keyboard::D)) {
pos.x -= SPEED;
mot.x = -1;
} else {
mot.x = 0;
}

}

void Player::setPos(Vector2f& p) {
    pos = p;
}

Vector2f Player::getPos() {
    return pos;
}

Vector2f Player::getMot() {
    return mot;
}



#endif // PLAYER_H
