#include "Emitter.h"
#include "Engine.h"
#include "Asteroids.h"

using namespace std;

Emitter::Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval) : GameObject2D(initPosition, 0.0f, initSize, 0) 
{
	// Initialize emitter properties
	this->emitTimeInterval = emitTimeInterval;
	emitCounter = emitTimeInterval;
	particleNumber = 0;

	
	// Obtain a seed for the random number engine
	random_device rd;

	// Standard mersenne_twister_engine seeded with rd() - mt19937 is a high-quality pseudo-random number generator
	gen = mt19937(rd());

	// Setup distributions
	normDist = uniform_real_distribution<float>(-1.0f, 1.0f);
	massDist = uniform_real_distribution<float>(0.005f, 0.08f);
	scaleDist = uniform_real_distribution<float>(0.1f, 0.5f);


}
// override render but do nothing - we'll not render anything for the emitter 
void Emitter::render() {}

void Emitter::update(double tDelta) {

	emitCounter += (float)tDelta;
	float maxAsteroids = getObjectCounts("Enemy");
	if (maxAsteroids >= 5)
	{
		return; // do not emit more if we have reached max
	}

	// Check if it's time to emit a new particle
	if (emitCounter >= emitTimeInterval) 
	{
		// decrease emitCounter by emitTimeInterval - don't set to 0 as this would ignore the case where multiple particles are needed.
		emitCounter -= emitTimeInterval;

		// spawn in the enemies
		GLuint enemyTexture = loadTexture("Resources\\Textures\\Asteroid.jpg");
		float x = position.x + normDist(gen) * size.x;// random x position within emitter width
		float y = position.y + normDist(gen) * size.y;// random y position within emitter height
		float scale = scaleDist(gen);// random size for enemy
		float mass = massDist(gen);//random mass for enemy
		Enemy* s1 = new Enemy(glm::vec2(x, y), 0.0f, glm::vec2(scale, scale), enemyTexture, mass, orientation);
		string key = string("Enemy");

		if (particleNumber > 0) { // first name in collection must not be numbered if using this approach

			// add value so unique anyway - not using engine mechanism
			key += to_string(particleNumber);
		}

		particleNumber++;
		addObject(key.c_str(), s1);
	}
}




