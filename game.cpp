#ifndef GAME_IMPL
#define GAME_IMPL

#include "game.h"

Game::Game(sf::RenderWindow &window) : window(&window), player(500, 700, 1, 5), enemy(1, 4, 1), ball(5, 15),
                                        field(sf::Vector2f(C_WINDOW_WIDTH-20, C_WINDOW_HEIGHT-20)) {

    this->draw_list = new list<Drawable*>();

    this->addDrawable(this->player);
    this->addDrawable(*this->enemy.getPaddle());

    field.setPosition(10, 10);
    field.setFillColor(sf::Color(0,0,0));
    field.setOutlineColor(sf::Color(255, 255, 255));
    field.setOutlineThickness(10);

    printf("Game created on window!");
}

bool Game::handleEventLoop() {

    sf::Event event;

    while (this->window->pollEvent(event)) {

        switch(event.type) {
            case sf::Event::Closed:
                return false;

            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                    return false;
        }
    }

    ball.processMovement();

    ball.checkColision(player.getSprite()->getGlobalBounds());
    ball.checkColision(enemy.getPaddle()->getSprite()->getGlobalBounds());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.moveLeft();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.moveRight();

    enemy.AI(ball);

    return true;
}

void Game::addDrawable(Drawable &drawable) {
    this->draw_list->push_back(&drawable);
}

void Game::handleDrawing() {

    this->window->draw(field);

    this->window->draw(*ball.getShape());

    for(Drawable *d : *(this->draw_list))
        if(d->isVisible())
            this->window->draw(*(d->getSprite()));
}

Game::~Game() {
    delete(this->draw_list);
}

#endif // GAME_IMPL

