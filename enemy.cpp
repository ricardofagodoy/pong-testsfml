#ifndef ENEMY_IMPL
#define ENEMY_IMPL

#include "enemy.h"

Enemy::Enemy(int level, double speed, double scale) : level(level), speed(speed),
                                                      scale(scale), paddle(450, 20, scale, speed) {

}

Paddle* Enemy::getPaddle() {
    return &this->paddle;
}

void Enemy::AI(Ball &b) {

    if(this->paddle.getX() > 0 &&
       b.getShape()->getPosition().x < this->paddle.getX() + this->paddle.getSprite()->getGlobalBounds().width/2)
        this->paddle.moveLeft();
    else if(this->paddle.getX() + this->speed < C_WINDOW_WIDTH)
        this->paddle.moveRight();
}

#endif // ENEMY_IMPL
