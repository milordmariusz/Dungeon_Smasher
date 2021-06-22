#include "Enemy.h"

Enemy::Enemy(Texture* textureWalk, Vector2u walkCount, Texture* textureAttack, Vector2u attackCount, float switchTime, float speed, Vector2f position, int pointValue, int attackPower)
    :animationWalk(textureWalk, walkCount, switchTime), animationAttack(textureAttack, attackCount, switchTime)
{
    //variables
    this->walkTexture = textureWalk;
    this->attackTexture = textureAttack;
    this->speed = speed;
    this->state = 0;
    this->startPosition = position;
    this->value = pointValue;
    this->attackFinished = false;
    this->attackPower = attackPower;
    row = 0;
    // setting body - texture 
    body.setPosition(position);
    body.setSize(sf::Vector2f(128.0f, 128.0f));
    body.setOrigin(body.getSize() / 2.0f);
    // setting hitbox
    hitbox.setPosition( (position.x + body.getSize().x / 3.0f), (position.y + body.getSize().y / 3.0f));
    hitbox.setSize(sf::Vector2f(128.0f/3.0f, 128.0f / 3.0f));
    hitbox.setOrigin(body.getSize() / 2.0f);
}

Enemy::~Enemy()
{

}

void Enemy::Update(float deltaTime)
{
    //Movement section
    sf::Vector2f movement(0.0f, 0.0f);
    float moveVectorX;
    float moveVectorY;

    //Setting direction to center and setting movement
    Vector2f direction = Vector2f(640.0f, 368.0f) - startPosition;
    float magnitude = sqrt((direction.x * direction.x) + (direction.y * direction.y));
    Vector2f unitVector(direction.x / magnitude, direction.y / magnitude);
    movement = speed * deltaTime * unitVector;

    //Animation section 0-walk 1-attack 2-hit | row-0 down-right | row-1 down-left | row-2 up-right | row-3 up-left |
    if(movement.x >0 and movement.y>0)
        row = 0;
    if (movement.x < 0 and movement.y > 0)
        row = 1;
    if (movement.x > 0 and movement.y < 0)
        row = 2;
    if (movement.x < 0 and movement.y < 0)
        row = 3;

    if (state == 0) //setting animation to walk
    {
        body.setTexture(walkTexture);
        animationWalk.Update(row, deltaTime);
        body.setTextureRect(animationWalk.uvRect);
        body.move(movement);
        hitbox.move(movement);
    }
    else if (state == 1) //setting animation to attack 
    {
        body.setTexture(attackTexture);
        animationAttack.Update(row, deltaTime);
        body.setTextureRect(animationAttack.uvRect);
        if (animationAttack.currentImage.x >= animationAttack.imageCount.x-1) //deleting enemy after attack
        {
            attackFinished = true;
        }
    }
}

void Enemy::Draw(sf::RenderWindow& window) //render enemy
{
    window.draw(body);
}