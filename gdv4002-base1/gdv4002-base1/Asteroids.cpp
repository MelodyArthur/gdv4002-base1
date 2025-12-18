#include "Asteroids.h"
#include "Engine.h"

Enemy::Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize,GLuint initTextureID,float mass, float angleChangePerSecond): GameObject2D(initPosition, initOrientation, initSize, initTextureID) 
{
	
	this->mass = mass;//set mass
	velocity = glm::vec2(0.0f, 0.0f); // default to 0 velocity
	this->angleChangePerSecond = angleChangePerSecond;//how fast it rotates
}
void Enemy::update(double tDelta) 
{
	float maxSpeed = 3.0f;//max speed for enemy
	//---------------------update position and orientation---------------------
	// 1. Physics bit for movement
	float accel = (5.0f / mass);//how fast it speeds up
	// 1.3. Update velocity
	velocity = velocity + accel * (float)tDelta;


	if(glm::length(velocity) > maxSpeed)
	{
		velocity = glm::normalize(velocity) * maxSpeed;
	}//velocity clamp to max speed

	// 1.4. Update position
	position = position + velocity * (float)tDelta;
	// 2. Non-physics bit for rotation
	orientation += velocity.x * (float)tDelta;//rotate based on x velocity

	


	//---------------------make the enemy wrap around the screen---------------------
	if (position.x > getViewplaneHeight() / 2.0f)
	{
		position.x = (-getViewplaneHeight() / 2.0f);//add a little offset so it doesnt immediately wrap back
	}
	else if (position.x < - getViewplaneHeight() / 2.0f)
	{
		position.x = (getViewplaneHeight() / 2.0f);
	}
	else if (position.y < - getViewplaneHeight() / 2.0f)
	{
		position.y = (getViewplaneHeight() / 2.0f);
	}
	else if (position.y > getViewplaneHeight() / 2.0f)
	{
		position.y = (- getViewplaneHeight() / 2.0f);
	}
}
