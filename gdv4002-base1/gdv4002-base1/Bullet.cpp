#include "Player.h"
#include "Bullet.h"
#include "Engine.h"



Bullet::Bullet(glm::vec2 initPosition,float initOrientation,glm::vec2 initSize,GLuint initTextureID) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) 
{
	velocity = glm::vec2(0.0f, 0.0f); // default to 0 velocity
	mass = 0.5f; // set a default mass for the bullet
}


void Bullet::update(double tDelta)
{
	//---------------------update position and orientation---------------------
	// 1. Physics bit for movement
	float accel = (2.5f / mass);//how fast it speeds up
	// 1.3. Update velocity
	velocity = velocity + accel * (float)tDelta;

	// Move the bullet forward in the direction it is facing
	position.x += cos(orientation) * velocity.x * (float)tDelta;//update x position using velocity
	position.y += sin(orientation) * velocity.y * (float)tDelta;//update y position using velocity
	
	float maxSpeed = 10.0f;//max speed for bullet (changeable)

	if (glm::length(velocity) > maxSpeed)
	{
		velocity = glm::normalize(velocity) * maxSpeed;
	}//velocity clamp to max speed

	
	


}