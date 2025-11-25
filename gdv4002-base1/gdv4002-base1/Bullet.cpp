#include "Player.h"
#include "Bullet.h"
#include "Engine.h"

Bullet::Bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float initialPhase, float initialPhaseVelocity) : GameObject2D(initPosition, initOrientation, initSize, initTextureID)
{
	phaseAngle = initialPhase;
	phaseVelocity = initialPhaseVelocity;
}