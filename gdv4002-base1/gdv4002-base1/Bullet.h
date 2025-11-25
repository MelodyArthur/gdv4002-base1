#pragma once
#include "GameObject2D.h"
#include <glm/glm.hpp>

class Bullet : public GameObject2D 
{
private:

public:
	Bullet(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID);

	void update(double tDelta) override;
};


