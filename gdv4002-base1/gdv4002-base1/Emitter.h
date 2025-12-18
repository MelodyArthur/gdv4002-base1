#pragma once

#include "GameObject2D.h"
#include <random>

class Emitter : public GameObject2D
{
private:

	float	emitTimeInterval;// time between particle emissions
	float	emitCounter;

	unsigned long long particleNumber; // monotonically increasing particle index / number - used to set key

	GLuint	enemyTexture;// texture for emitted particles
	// Random number generator
	std::mt19937 gen;

	// Random number distributions
	std::uniform_real_distribution<float> normDist; // -1 to 1
	std::uniform_real_distribution<float> massDist, scaleDist;

public:

	void setEmitInterval(float seconds);
	float getEmitInterval() const;

	Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval);

	void update(double tDelta) override;
	void render() override;

};

