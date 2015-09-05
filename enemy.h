#ifndef ENEMY
#define ENEMY

#include "Paddle.h"
#include "ball.h"

class Enemy {
    int level;
    double speed, scale;

    Paddle paddle;

    Enemy();
public:
    Enemy(int, double, double);
    Paddle *getPaddle();
    void AI(Ball& b);
};

#endif // ENEMY

