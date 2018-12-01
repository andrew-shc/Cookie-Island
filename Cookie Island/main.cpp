#include <iostream>
#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Terrain.h"
#include "Player.h"

using namespace std;
using namespace sf;


int main()
{
    cout << "Initializing...\n";
    //err().rdbuf(NULL);  // No error message (especially with the error message file can't load)
    Vector2i WORLD_SIZE(100, 100);
    Vector2i PLAYER_START_POS(-50, -50);  // Player starting location (-ofs, -ofs) as where in Quad IV
    Vector2f ply_movement;

    Terrain terrain(WORLD_SIZE, PLAYER_START_POS);
    Player player;

    terrain.loadTexture();
    terrain.generateTerrain();
    window.setFramerateLimit(FPS_LIMIT);

    cout << "Game Started!\n";

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        player.update();
        ply_movement = player.getMot();

        terrain.setPos(ply_movement);

        terrain.showTerrain();

        player.show(window);
        window.display();

    }
    cout << "Game Ended!\n";
    return 0;
}
