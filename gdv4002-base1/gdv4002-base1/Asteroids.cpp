#include "Asteroids.h"

Enemy::Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize,GLuint initTextureID,float initialPhase,float initialPhaseVelocity): GameObject2D(initPosition, initOrientation, initSize, initTextureID) 
{
	phaseAngle = initialPhase;
	phaseVelocity = initialPhaseVelocity;
}
void Enemy::update(double tDelta) 
{
	//need to get the acceleration of each enemy because theyre all different (last thing in brackets when adding them in)
	//phaseVelocity = phaseVelocity + phaseAngle.y * (float)tDelta; // integrate to get new velocity (use y component)
	//position = position + (phaseAngle * (float)tDelta); // integrate to get new position
	// Set position based on phaseAngle
	position.y = tanf(phaseAngle);

	// Update phaseAngle based on velocity * time elapsed
	phaseAngle += phaseVelocity * tDelta;
}
//orientation += glm::radians(145.0f) * (float)tDelta;