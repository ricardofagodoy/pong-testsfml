#ifndef BALL_IMPL
#define BALL_IMPL

#include "ball.h"

Ball::Ball(double speed, double radius) : speed(speed), radius(radius), sprite(radius), vx(speed), vy(speed) {
    sprite.setPosition(300, 300);
    sprite.setFillColor(sf::Color(255, 255, 255));
}

void Ball::processMovement() {
    int x = sprite.getPosition().x,
        y = sprite.getPosition().y;

    if(x <= 0 || x + vx >= C_WINDOW_WIDTH - this->radius)
        vx*=-1;

    if(y <= 0 || y + vy >= C_WINDOW_HEIGHT - this->radius)
        vy*=-1;

    sprite.setPosition(x + vx, y + vy);
}

void Ball::checkColision(sf::Rect<float> a) {
    if(this->getShape()->getGlobalBounds().intersects(a))
        vy*=-1;
}

#endif // BALL_IMPL
