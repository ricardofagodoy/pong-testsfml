#include <iostream>
#include <SFML/Graphics.hpp>
#include "configuration.h"
#include "game.h"
#include "paddle.h"
#include "logger.h"

using namespace std;

int main(void)  // MISSING LOG
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(C_WINDOW_WIDTH, C_WINDOW_HEIGHT), C_WINDOW_NAME, sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    Game game(window);

    while (window.isOpen()) {

       if(!game.handleEventLoop())
           break;

       window.clear();

       game.handleDrawing();

       window.display();
    }

    printf("\nClosing game with success code...\n");
    return 0;
}
