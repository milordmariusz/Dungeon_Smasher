#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2u imageCount, float switchTime, float speed, Vector2f position) :animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    this->startPosition = position;
    body.setPosition(position);
    body.setSize(sf::Vector2f(32.0f, 32.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setTexture(texture);
}

Enemy::~Enemy()
{

}

void Enemy::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);
    float moveVectorX;
    float moveVectorY;

    Vector2f direction = Vector2f(640.0f, 368.0f) - startPosition;

    float magnitude = sqrt((direction.x * direction.x) + (direction.y * direction.y));

    Vector2f unitVector(direction.x / magnitude, direction.y / magnitude);

    movement = speed * deltaTime * unitVector;

    if(movement.x >0 and movement.y>0)
        row = 0;
    if (movement.x < 0 and movement.y > 0)
        row = 1;
    if (movement.x > 0 and movement.y < 0)
        row = 2;
    if (movement.x < 0 and movement.y < 0)
        row = 3;

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

void Enemy::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}