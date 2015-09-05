#ifndef PADDLE_IMPL
#define PADDLE_IMPL

#include "configuration.h"
#include "paddle.h"

Paddle::Paddle(int posX, int posY, double scale, double speed) : scale(scale), speed(speed) {

    if(!this->sprite.getTexture()) {
        printf("Initializing sprite texture...");

        if (!this->texture.loadFromFile(C_PADDLE_TEXTURE)) {
            printf("Texture %s not found!", C_PADDLE_TEXTURE);
            return;
        }

        this->sprite.setTexture(this->texture);
        printf("Texture applied successfuly!");
    }

    this->sprite.setPosition(posX, posY);
    this->sprite.setScale(this->scale, 1);

    printf("Paddle created");
}

double Paddle::getScale() const {
    return this->scale;
}

double Paddle::getSpeed() const {
    return this->speed;
}

void Paddle::setSpeed(const double speed) {
    this->speed = speed;
}

void Paddle::setScale(const double scale) {
    this->scale = scale;
}

unsigned int Paddle::getX() const {
    return this->sprite.getPosition().x;
}

unsigned int Paddle::getY() const {
    return this->sprite.getPosition().y;
}

bool Paddle::moveLeft() {
    this->sprite.setPosition(this->getX()-speed, this->getY());
    return true;
}

bool Paddle::moveRight() {
    this->sprite.setPosition(this->getX()+speed, this->getY());
    return true;
}

Paddle::~Paddle() {
    printf("Paddle destroyed");
}

#endif // PADDLE_IMPL
