#include "Asteroids.h"
#include "Engine.h"

Enemy::Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize,GLuint initTextureID,float mass, float angleChangePerSecond): GameObject2D(initPosition, initOrientation, initSize, initTextureID) 
{
	
	this->mass = mass;
	velocity = glm::vec2(15.0f, 15.0f); // default to 0 velocity
	this->angleChangePerSecond = angleChangePerSecond;
}
void Enemy::update(double tDelta) 
{
	float maxSpeed = 1.0f;
	//---------------------update position and orientation---------------------
	// 1. Physics bit for movement
	float accel = (20.0f / mass);
	// 1.3. Update velocity
	velocity = velocity + accel * (float)tDelta;

	/*if (velocity.x > maxSpeed)
	{
		velocity.x = maxSpeed;
	}
	if (velocity.y > maxSpeed)
	{
		velocity.y = maxSpeed;
	}*/

	if(glm::length(velocity) > maxSpeed)
	{
		velocity = glm::normalize(velocity) * maxSpeed;
	}//stops the disco lights

	// 1.4. Update position
	position = position + velocity * (float)tDelta;
	// 2. Non-physics bit for rotation
	orientation += angleChangePerSecond * (float)tDelta;

	


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



//orientation += glm::radians(145.0f) * (float)tDelta;

// set the initial velocity as a value and make it change depending on the mass of the asteroid