#ifndef HHH_CONST_H
#define HHH_CONST_H

#include <string>
#include <SFML/Graphics.hpp>

// all shape area and position is in (x, y) except for data and array(vector), it'll be flipped
// all blocks size is square

// --- GAME CONFIGURATION ---
unsigned int BLOCK_SZ = 50; // by pixels
unsigned int FPS_LIMIT = 80;
std::string LOCAL_DIR = "C:\\Users\\Andrew Shen\\Desktop\\Cookie Island\\";
std::string RES_DIR = LOCAL_DIR+"resource\\";
sf::Vector2f SCREEN_SIZE(1000, 1000);
sf::Vector2f SCREEN_VIEW_B(5, 5);  // Size in blocks; Screen View Size Start Position
sf::Vector2f SCREEN_VIEW_F(15, 15);  // Size in blocks; Screen View Size Second Position
sf::RenderWindow window(sf::VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Cookie Island");

// --- GAME MECHANICS ---
unsigned int SPEED = 5; // pixel per frame
sf::Vector2f PLAYER_SIZE(45, 90);
//sf::Vector2f PLAYER_BOX_COLLISION(20, 40);
// sf::Vector2f PLAYER_BOX_COL_OFS(0, 0);
sf::Vector2f PLAYER_ABS_POS(SCREEN_SIZE.x/2, SCREEN_SIZE.y/2);  // Player position to the screen



// --- GAME DATA ---
std::string TXTR_LOAD_FNAME[3] = {"air", "box_frame", "no-texture"};  // in order, followed by in block-id

#endif // CONST_H
