#include "Asteroids.h"
#include "Engine.h"

Enemy::Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize,GLuint initTextureID,float mass): GameObject2D(initPosition, initOrientation, initSize, initTextureID) 
{
	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f); // default to 0 velocity
}
void Enemy::update(double tDelta) 
{
	//glm::vec2 a = F * (1.0f / mass);//calculate acceleration.If f = ma, a = f / m
	//velocity = velocity + (a * (float)tDelta);//integate to get new velocity
	//position = position + (velocity * (float)tDelta);//integrate to get new position

	orientation += glm::radians(145.0f) * (float)tDelta;

	// make the enemy wrap around the screen
	if (position.x > getViewplaneHeight() / 2.0f)
	{
		position.x = (-getViewplaneHeight() / 2.0f) - 1;//add a little offset so it doesnt immediately wrap back
	}
	else if (position.x < - getViewplaneHeight() / 2.0f)
	{
		position.x = (getViewplaneHeight() / 2.0f) + 1;
	}
	else if (position.y < - getViewplaneHeight() / 2.0f)
	{
		position.y = (getViewplaneHeight() / 2.0f) + 1;
	}
	else if (position.y > getViewplaneHeight() / 2.0f)
	{
		position.y = (- getViewplaneHeight() / 2.0f) - 1;
	}
}
//orientation += glm::radians(145.0f) * (float)tDelta;