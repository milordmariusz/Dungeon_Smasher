#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);

	sf::IntRect uvRect;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

private:
	float totalTime;
	float switchTime;
};

