#include "Player.h"
#include "Bullet.h"
#include "Engine.h"



Bullet::Bullet(glm::vec2 initPosition,float initOrientation,glm::vec2 initSize,GLuint initTextureID) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) 
{
	
}


void Bullet::update(double tDelta)
{
	// Move the bullet forward in the direction it is facing
	float speed = 5.0f; // Set a constant speed for the bullet
	position.x += cos(orientation) * speed * (float)tDelta;
	position.y += sin(orientation) * speed * (float)tDelta;
	


}