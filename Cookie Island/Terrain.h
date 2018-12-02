#ifndef HHH_TERRAIN_H
#define HHH_TERRAIN_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "BlockData.h"

using namespace std;
using namespace sf;

class Terrain {
private:
    Vector2i TERRAIN_SZ;
    Vector2f pos;  // the position of the terrain by pixels
    Vector2i ofs;  // the offset by size of blocks
    vector<Texture> txtr;
    vector<vector<unsigned int>> TERRAIN_DT;

public:
    Terrain(Vector2i sz, Vector2i start_pos);

    void loadTexture();
    void generateTerrain();
    inline void showTerrain();

    void setPos(Vector2f _mov);

    Vector2f getPos();  // get position
    Vector2i getOfs();  // get offset

};

Terrain::Terrain(Vector2i sz, Vector2i start_ofs) {
  TERRAIN_SZ = sz;
  ofs = start_ofs;
}

void Terrain::loadTexture() {
  string fname;
  for (int i = 0; i < sizeof(TXTR_LOAD_FNAME)/sizeof(TXTR_LOAD_FNAME[0]); ++i) {
    fname = TXTR_LOAD_FNAME[i];
    Texture t;
    if (t.loadFromFile(RES_DIR+fname+".png")) {
        txtr.push_back(t);
    } else {
        if (t.loadFromFile(RES_DIR+"no-texture"+".png")) {
            txtr.push_back(t);
        } else {
            cout << "[ERROR] Cannot load texture " << fname;
        }
    }
  }
}

void Terrain::generateTerrain() {
  for (int y = 0; y < TERRAIN_SZ.y; ++y) {
    TERRAIN_DT.push_back(vector<unsigned int>());
    for (int x = 0; x < TERRAIN_SZ.x; ++x) {
      if (x % 3 == 0 and y % 3 == 0) {
        TERRAIN_DT[y].push_back(AIR);
      } else {
        TERRAIN_DT[y].push_back(REQT);
      }
    }
  }
}


void Terrain::showTerrain() {
  RectangleShape block(Vector2f(BLOCK_SZ, BLOCK_SZ));
  cout << "CRD: " << ofs.y << " " << ofs.x << endl;
  for (int y = SCREEN_VIEW_S.y; y < SCREEN_VIEW_E.y; ++y) {
      for (int x = SCREEN_VIEW_S.x; x < SCREEN_VIEW_E.x; ++x) {
        block.setPosition(x*BLOCK_SZ+pos.x, y*BLOCK_SZ+pos.y);
        block.setTexture(&txtr[TERRAIN_DT[y-ofs.y][x-ofs.x]]);
        window.draw(block);
      }
  }
}

void Terrain::setPos(Vector2f _mov) {
  if (_mov.x == 1 and ofs.x < 0-SCREEN_VIEW_S.x) pos.x += SPEED;   // terrain movement; and to prevent the player getting out of the world
  if (_mov.y == 1 and ofs.y < 0-SCREEN_VIEW_S.y) pos.y += SPEED;
  if (_mov.x == -1 and ofs.x > -TERRAIN_SZ.x+SCREEN_VIEW_E.x) pos.x -= SPEED;
  if (_mov.y == -1 and ofs.y > -TERRAIN_SZ.y+SCREEN_VIEW_E.y) pos.y -= SPEED;

  if (pos.x/BLOCK_SZ >= 1) {  // to edit the offset (gives an illusion of movement)
      pos.x = 0;
      ofs.x += 1;
  }
  if (pos.y/BLOCK_SZ >= 1) {
      pos.y = 0;
      ofs.y += 1;
  }
  if (pos.x/BLOCK_SZ <= -1) {
      pos.x = 0;
      ofs.x -= 1;
  }
  if (pos.y/BLOCK_SZ <= -1) {
      pos.y = 0;
      ofs.y -= 1;
  }
}

Vector2f Terrain::getPos() {
  return pos;
}

Vector2i Terrain::getOfs() {
  return ofs;
}

#endif
