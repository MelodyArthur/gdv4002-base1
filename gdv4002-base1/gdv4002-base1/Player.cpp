#include "Player.h"
#include "Keys.h"
#include "Engine.h"
#include <bitset>

extern std::bitset<5> keys;//very neccessary

Player::Player(glm::vec2 initPosition, float initOrientation, glm::vec2 initSize, GLuint initTextureID, float mass) : GameObject2D(initPosition, initOrientation, initSize, initTextureID) 
{
	this->mass = mass;
	velocity = glm::vec2(0.0f, 0.0f); // default to 0 velocity
}

void Player::update(double tDelta) 
{
	glm::vec2 F = glm::vec2(0.0f, 0.0f);//initialize force vector
	const float thrust = 2.0f;//thrust force applied when key is pressed

	//-------------------------------Make the ship move-----------------------------
	if (keys.test(Key::W) == true) {

		F += glm::vec2(0.0f, thrust);
	}
	if (keys.test(Key::S) == true) {

		F += glm::vec2(0.0f, -thrust);
	}
	if (keys.test(Key::A) == true) {

		F += glm::vec2(-thrust, 0.0f);
		orientation += glm::radians(145.0f) * (float)tDelta;
	}
	if (keys.test(Key::D) == true) {

		F += glm::vec2(thrust, 0.0f);
		orientation -= glm::radians(145.0f) * (float)tDelta;
	}
	//----------------position, velocity and acceleration update----------------
	glm::vec2 a = F * (1.0f / mass);//calculate acceleration.If f = ma, a = f / m
	velocity = velocity + (a * (float)tDelta);//integate to get new velocity
	position = position + (velocity * (float)tDelta);//integate to get new position


	//----------------make the player wrap around the screen----------------
	if (position.x > getViewplaneHeight() / 2.0f)
	{
		position.x = -getViewplaneHeight() / 2.0f;
	}
	else if (position.x < -getViewplaneHeight() / 2.0f)
	{
		position.x = getViewplaneHeight() / 2.0f;
	}
	else if (position.y < -getViewplaneHeight() / 2.0f)
	{
		position.y = getViewplaneHeight() / 2.0f;
	}
	else if (position.y > getViewplaneHeight() / 2.0f)
	{
		position.y = -getViewplaneHeight() / 2.0f;
	}
}
