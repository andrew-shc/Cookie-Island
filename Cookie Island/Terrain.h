#ifndef HHH_TERRAIN_H
#define HHH_TERRAIN_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Constants.h"

using namespace std;
using namespace sf;

class Terrain {
private:
    Vector2f TERRAIN_SZ;
    Vector2f pos;  // the position of the terrain, resets if exceed by 1 v
    Vector2f ofs;  // the offset                             and adds by 1 in offset
    vector<unsigned int> gen_terrain;  // generated terrain or all the terrain data set in vector
    vector<unsigned int> cur_terrain;  // the current terrain, or the terrain that is visible to see you to minimize lag
    vector<Texture> txtr;

public:
    Terrain(Vector2f sz);

    void loadTexture();
    void generateTerrain();
    inline void showTerrain();

    void setPos(Vector2f _mov);

    vector<unsigned int> getTerrain();
    Vector2f getPos();


};

Terrain::Terrain(Vector2f sz) {
TERRAIN_SZ = sz;
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
    for (int x = 0; x < TERRAIN_SZ.x; ++x) {
        if (y % 3 == 0) {
            gen_terrain.push_back(0);
        } else {
            gen_terrain.push_back(1);
        }
    }
}

}


void Terrain::showTerrain() {
RectangleShape block(Vector2f(BLOCK_SZ, BLOCK_SZ));
unsigned int vect_loc = 0;
Vector2f S_B(ofs.x+SCREEN_VIEW_B.x, ofs.y+SCREEN_VIEW_B.y);
Vector2f S_F(ofs.x+SCREEN_VIEW_F.x, ofs.y+SCREEN_VIEW_F.y);

for (int y = SCREEN_VIEW_B.y; y < SCREEN_VIEW_F.y; ++y) {
    for (int x = SCREEN_VIEW_B.x; x < SCREEN_VIEW_F.x; ++x) {
        vect_loc = (y-ofs.y)*TERRAIN_SZ.x+(x+ofs.x);  // ERROR <<<
        block.setPosition(x*BLOCK_SZ+pos.x, y*BLOCK_SZ+pos.y);
        //cout << gen_terrain[vect_loc] << " " << vect_loc << endl;
        block.setTexture(&txtr[gen_terrain[vect_loc]]);
        //block.setTexture(&txtr[1]);
        window.draw(block);
    }
}
}

void Terrain::setPos(Vector2f _mov) {
cout << "POS: " <<pos.x << " " << pos.y << " OFS: " <<ofs.x << " " << ofs.y << endl;

if (_mov.x == 1 and ofs.x < TERRAIN_SZ.x) pos.x += SPEED;   // terrain movement; and to prevent the player getting out of the world
if (_mov.y == 1 and ofs.y < TERRAIN_SZ.y) pos.y += SPEED;
if (_mov.x == -1 and ofs.x > 0) pos.x -= SPEED;
if (_mov.y == -1 and ofs.y > 0) pos.y -= SPEED;

if (pos.x/BLOCK_SZ >= 1) {
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

//pos = _pos;
}

vector<unsigned int> Terrain::getTerrain() {
return gen_terrain;
}

Vector2f Terrain::getPos() {
return pos;
}

#endif
