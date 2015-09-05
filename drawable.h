#ifndef DRAWABLE
#define DRAWABLE

#include <SFML/Graphics/Sprite.hpp>

class Drawable {
    bool visible;
public:
    Drawable() {
        this->visible = true;
    }

    void setVisible(bool visible) {
        this->visible = visible;
    }

    bool isVisible() {
        return visible;
    }

    virtual sf::Sprite* getSprite() = 0;
};

#endif // DRAWABLE

