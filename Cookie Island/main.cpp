#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Constants.h"
#include "Terrain.h"
#include "Player.h"


using namespace std;
using namespace sf;


int main()
{
    cout << "Initializing...\n";
    //err().rdbuf(NULL);  // No error message (especially with the error message file can't load)

    Terrain terrain(Vector2f(100, 100));  // x, y
    Player player;

    terrain.loadTexture();
    terrain.generateTerrain();
    window.setFramerateLimit(FPS_LIMIT);

    Vector2f ply_movement;

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
