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

    inline void show(RenderWindow& window);
    inline void update();
    inline void collision(RenderWindow& w, Vector2f _pos);

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

void Player::collision(RenderWindow& w, Vector2f _pos) {
  int LN_SZ = 5;
  int PBX = PLAYER_COLLISION_BOX.x*BLOCK_SZ;
  int PBY = PLAYER_COLLISION_BOX.y*BLOCK_SZ;
  Vector2f ADD(round(PLAYER_ABS_POS.x/BLOCK_SZ)*BLOCK_SZ-round(PLAYER_COLLISION_BOX.x/2), round(PLAYER_ABS_POS.y/BLOCK_SZ)*BLOCK_SZ-round(PLAYER_COLLISION_BOX.y/2));
  RectangleShape rline(Vector2f(LN_SZ, PBY));
  RectangleShape lline(Vector2f(LN_SZ, PBY));
  RectangleShape tline(Vector2f(PBX, LN_SZ));
  RectangleShape bline(Vector2f(PBX, LN_SZ));
  rline.setPosition(Vector2f(PBX+_pos.x+ADD.x, 0+_pos.y+ADD.y));
  lline.setPosition(Vector2f(0+_pos.x+ADD.x, 0+_pos.y+ADD.y));
  tline.setPosition(Vector2f(0+_pos.x+ADD.x, 0+_pos.y+ADD.y));
  bline.setPosition(Vector2f(0+_pos.x+ADD.x, PBY+_pos.y+ADD.y));
  w.draw(rline);
  w.draw(lline);
  w.draw(tline);
  w.draw(bline);
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
