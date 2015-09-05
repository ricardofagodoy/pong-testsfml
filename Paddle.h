#ifndef PADDLE
#define PADDLE

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "configuration.h"
#include "drawable.h"

class Paddle : public Drawable {
    sf::Sprite sprite;
    sf::Texture texture;
    double scale, speed;
    Paddle();
public:
    Paddle(int, int, double, double);
    bool moveLeft();
    bool moveRight();
    double getScale() const;
    double getSpeed() const;
    void setScale(const double);
    void setSpeed(const double);
    unsigned int getX() const;
    unsigned int getY() const;

    sf::Sprite* getSprite() {
        return &this->sprite;
    }

    ~Paddle();
};

#endif // PADDLE

