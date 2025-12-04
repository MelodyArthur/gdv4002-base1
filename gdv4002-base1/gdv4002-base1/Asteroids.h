#pragma once
#include "GameObject2D.h"
#include <glm/glm.hpp>

extern glm::vec2 gravity;

class Enemy : public GameObject2D {

private:
	float mass;
	glm::vec2 velocity;
	float angleChangePerSecond;

public:
	Enemy(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass, float angleChangePerSecond);

	void update(double tDelta) override;

};
