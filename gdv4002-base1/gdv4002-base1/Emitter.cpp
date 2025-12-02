#include "Emitter.h"
#include "Engine.h"
#include "Bullet.h"


using namespace std;


Emitter::Emitter(glm::vec2 initPosition, glm::vec2 initSize, float emitTimeInterval) : GameObject2D(initPosition, 0.0f, initSize, 0) 
{
	this->emitTimeInterval = emitTimeInterval;
	emitCounter = emitTimeInterval;

}
void Emitter::render() {}// Do nothing - emitter is invisible

void Emitter::update(double tDelta) 
{

	emitCounter += (float)tDelta;

	while (emitCounter >= emitTimeInterval) {

		// decrease emitCounter by emitTimeInterval - don't set to 0 as this would ignore the case where multiple particles are needed.
		emitCounter -= emitTimeInterval;

		// Create new particle

	}
}


