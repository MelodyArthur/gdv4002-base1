#pragma once
#include "GameObject2D.h"
#include <glm/glm.hpp>

class Enemy : public GameObject2D {

private:
	float		mass; // in radians
	glm::vec2		velocity; // angle change per second
	glm::vec2	accel; // acceleration vector for enemy

public:
	Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass);

	void update(double tDelta) override;

};
