#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "drawable.h"
#include "paddle.h"
#include "enemy.h"
#include "ball.h"
#include <list>

using namespace std;

class Game {
    sf::RenderWindow *window;
    list<Drawable*> *draw_list;

    sf::RectangleShape field;
    Paddle player;
    Enemy enemy;
    Ball ball;

    Game();
public:
    Game(sf::RenderWindow&);
    bool handleEventLoop();
    void handleDrawing();
    void addDrawable(Drawable&);
    ~Game();
};

#endif // GAME

