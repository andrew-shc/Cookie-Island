#ifndef HHH_CONST_H
#define HHH_CONST_H

#include <string>
#include <SFML/Graphics.hpp>

// all shape area and position is in (x, y) except for data and array(vector), it'll be flipped
// all blocks size is square

// --- GAME CONFIGURATION ---
unsigned int BLOCK_SZ = 50; // by pixels
unsigned int FPS_LIMIT = 80;
std::string LOCAL_DIR = "C:\\Users\\Andrew Shen\\Desktop\\Cookie-Island\\Cookie Island\\";
std::string RES_DIR = LOCAL_DIR+"resource\\";
sf::Vector2f SCREEN_SZ(1000, 1000);
sf::Vector2f SCREEN_VIEW_S(0, 0);  // Size in blocks; Screen View Size Start Position
sf::Vector2f SCREEN_VIEW_E(20, 20);  // Size in blocks; Screen View Size End Position
sf::RenderWindow window(sf::VideoMode(SCREEN_SZ.x, SCREEN_SZ.y), "Cookie Island");

// --- GAME MECHANICS ---
unsigned int SPEED = 5; // pixel per frame
sf::Vector2f PLAYER_SIZE(45, 90);
sf::Vector2i PLAYER_COLLISION_BOX(5, 5);  // size in block
//sf::Vector2f PLAYER_BOX_COL_OFS(0, 0);
sf::Vector2f PLAYER_ABS_POS(SCREEN_SIZE.x/2, SCREEN_SIZE.y/2);  // Player position to the screen



// --- GAME DATA ---
std::string TXTR_LOAD_FNAME[3] = {"air", "no-texture", "no-texture"};  // in order, followed by in block-id

#endif // CONST_H
