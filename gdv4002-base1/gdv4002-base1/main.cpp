#include "Player.h"
#include "Asteroids.h"
#include "Bullet.h"
#include "Engine.h"
#include "Keys.h" 
#include "Emitter.h"
#include <bitset>

//---------------------------Function prototypes---------------------------
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods); 
void deleteBullets(GLFWwindow* window, double tDelta);
//void deleteEnemies(GLFWwindow* window, double tDelta);

//---------------------------Global Variables-----------------------------
std::bitset<5> keys{ 0x0 };
Player* mainPlayer = nullptr;
float g1 = (getViewplaneHeight() / 2.0f);
float g2 = (getViewplaneWidth() / 2.0f);
glm::vec2 gravity = glm::vec2(g1, g2);
static const double bulletCooldown = 0.2;//time between bullets(adjustable)
static double lastBulletSpawnTime = -100000.0;//last time a bullet was spawned but allows first bullet to spawn


void spawnBullet()
{
	//set the cooldown timer
	double now = glfwGetTime();//get current time
	if (now - lastBulletSpawnTime < bulletCooldown)
	{
		return; //cooldown not finished
	}

	//spawn the bullet
	static int bulletCounter = 0;
	GLuint bulletTexture = loadTexture("Resources\\Textures\\bullet.png");//load bullet texture
	glm::vec2 spawnPos = glm::vec2(0.0f, 0.3f);//sets default spawn position
	float forward = 0.0f;//sets default forward direction
	if (mainPlayer) 
	{
		spawnPos = mainPlayer->position;
		forward = mainPlayer ->orientation;
	}//get player position and orientation

	Bullet* bullet = new Bullet(spawnPos, forward, glm::vec2(0.1f, 0.1f), bulletTexture);//create new bullet object
	
	std::string key = std::string("bullet");// base key name
	if (bulletCounter > 0) // first name in collection must not be numbered if using this approach
	{ 
		key += std::to_string(bulletCounter); // add value so unique anyway - not using engine mechanism
	}
	addObject(key.c_str(), bullet);
	bulletCounter++;//increment bullet counter for unique naming
	lastBulletSpawnTime = now;//update last bullet spawn time

}

int main(void) 
{
	//create the window
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 512, 512, 10.0f);
	hideAxisLines();//hide axis lines for cleaner look
	if (initResult != 0) 
	{
		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//------------------------------Game Objects--------------------------------
	// Create a player object and add it to the engine
	GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png");
	mainPlayer = new Player(glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), playerTexture, 1.0f);
	addObject("player", mainPlayer);

	Emitter* emitter = new Emitter(glm::vec2(0.0f, getViewplaneHeight() / 2.0f * 1.2f), glm::vec2(getViewplaneWidth() / 2.0f, 0.0f), 1.5f);
	addObject("emitter", emitter);

	//------------------------------Event Handlers-------------------------------
	setKeyboardHandler(myKeyboardHandler);
	setUpdateFunction(deleteBullets, false);
	//setUpdateFunction(deleteEnemies, false);

	engineMainLoop();// Enter main loop - this handles update and render calls
	engineShutdown();// When we quit (close window for example), clean up engine resources

	listGameObjectKeys();//list all object keys in engine
	return 0;
}
//----------------------------delete off-screen bullets-------------------------
void deleteBullets(GLFWwindow* window, double tDelta)
{
	GameObjectCollection bullet = getObjectCollection("bullet");

	for (int i = 0; i < bullet.objectCount; i++) {

		if (bullet.objectArray[i]->position.y < - (getViewplaneHeight() / 2.0f))
		{
      		deleteObject(bullet.objectArray[i]);
		}
		else if(bullet.objectArray[i]->position.x > (getViewplaneWidth() / 2.0f))
		{
   			deleteObject(bullet.objectArray[i]);
		}
		else if (bullet.objectArray[i]->position.y > (getViewplaneHeight() / 2.0f))
		{
			deleteObject(bullet.objectArray[i]);
		}
		else if (bullet.objectArray[i]->position.x <  - (getViewplaneWidth() / 2.0f))
		{
			deleteObject(bullet.objectArray[i]);
		}
	}//note: only listens to one if statement per run
}
//----------------------------delete off-screen enemies-------------------------
//void deleteEnemies(GLFWwindow* window, double tDelta)
//{
//	GameObjectCollection enemy = getObjectCollection("Enemy");
//	for (int i = 0; i < enemy.objectCount; i++) {
//		if (enemy.objectArray[i]->position.y < -(getViewplaneHeight() / 2.0f))
//		{
//			deleteObject(enemy.objectArray[i]);
//		}
//	}
//}

//----------------------------boring keyboard stuff-------------------------
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	
	if (action == GLFW_PRESS) 
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window(and quit)
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_W:
			keys[Key::W] = true;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = true;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = true;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = true;
			break;
		case GLFW_KEY_SPACE:
			spawnBullet();
			break;
		}
	}
	// If not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) 
	{
		switch (key)
		{
		case GLFW_KEY_W:
			keys[Key::W] = false;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = false;
			break;
		case GLFW_KEY_S:
			keys[Key::S] = false;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = false;
			break;
		}
	}
}




