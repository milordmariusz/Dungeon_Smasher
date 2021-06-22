#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
using namespace sf;

class Enemy
{
public:
	Enemy(Texture* textureWalk, Vector2u walkCount, Texture* textureAttack, Vector2u attackCount, float switchTime, float speed, Vector2f position, int pointValue, int attackPower);
	~Enemy();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);

	auto getEnemyBounds() { return hitbox.getGlobalBounds(); };
	Vector2f GetPosition() { return body.getPosition(); };

	int state; //0-walk 1-attack
	int value;
	int attackPower;
	bool attackFinished;

private:
	Texture* walkTexture;
	Texture* attackTexture;
	RectangleShape hitbox;
	Vector2f startPosition;
	RectangleShape body;
	Animation animationWalk;
	Animation animationAttack;
	unsigned int row;
	float speed;
};

