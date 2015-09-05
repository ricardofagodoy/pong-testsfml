#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>
#include "drawable.h"
#include "configuration.h"

class Ball : public Drawable {
    double speed, radius;

    sf::CircleShape sprite;
    int vx, vy;

    Ball();
public:
    Ball(double, double);

    void processMovement();
    void checkColision(sf::Rect<float>);

    sf::Sprite* getSprite() {
        return 0;
    }

    sf::CircleShape* getShape() {
        return &this->sprite;
    }
};

#endif // BALL

