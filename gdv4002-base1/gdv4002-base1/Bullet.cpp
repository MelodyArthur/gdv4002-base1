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
	// Move the bullet forward in the direction it is facing
	float speed = 1.0f; // Set a constant speed for the bullet
	position.x += cos(orientation) * speed * (float)tDelta;
	position.y += sin(orientation) * speed * (float)tDelta;
	
	//float maxSpeed = 1.0f;
	////---------------------update position and orientation---------------------
	//// 1. Physics bit for movement
	//float accel = (20.0f / mass);
	//// 1.3. Update velocity
	//velocity = velocity + accel * (float)tDelta;


	////if (glm::length(velocity) > maxSpeed)
	////{
	////	velocity = glm::normalize(velocity) * maxSpeed;
	////}//velocity clamp to max speed

	
	


}