#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
using namespace sf;

class Enemy
{
public:
	Enemy(Texture* texture, Vector2u imageCount, float switchTime, float speed, Vector2f position);
	~Enemy();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);

	auto getEnemyBounds() { return body.getGlobalBounds(); };
	Vector2f GetPosition() { return body.getPosition(); };

private:
	Vector2f startPosition;
	RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
};

