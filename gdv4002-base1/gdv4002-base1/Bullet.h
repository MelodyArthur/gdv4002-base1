#pragma once
#include "GameObject2D.h"
#include <glm/glm.hpp>

class Bullet : public GameObject2D 
{
private:
	unsigned long long particleNumber; // monotonically increasing particle index / number - used to set key
	glm::vec2	velocity;
	float		mass;
public:
	Bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID);
	~Bullet();

	void update(double tDelta) override;
};


