#include "Player.h"
#include "Asteroids.h"
#include "Bullet.h"
#include "Engine.h"
#include "Keys.h" 
#include <bitset>

// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods); 

// Globals
std::bitset<5> keys{ 0x0 };
Player* mainPlayer = nullptr;



void spawnBullet()
{
	static int bulletCounter = 0;
	GLuint bulletTexture = loadTexture("Resources\\Textures\\bullet.png");
	glm::vec2 spawnPos = glm::vec2(0.0f, 0.3f);//need to somehow get player position and orientation
	float forward = 0.0f;
	if (mainPlayer) 
	{
		spawnPos = mainPlayer->position;
		forward = mainPlayer ->orientation;

	}
	Bullet* bullet = new Bullet(spawnPos, forward, glm::vec2(0.1f, 0.1f), bulletTexture);
	std::string name = "bullet" + std::to_string(++bulletCounter);
	addObject(name.c_str(), bullet);
}

int main(void) 
{
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 512, 512, 10.0f);//create the window
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
	

	// Create an enemy object and add it to the engine
	GLuint enemyTexture = loadTexture("Resources\\Textures\\Asteroid.jpg");//texture
	Enemy* enemy1 = new Enemy(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(25.0f));
	Enemy* enemy2 = new Enemy(glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(30.0f));
	Enemy* enemy3 = new Enemy(glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(60.0f));//enemy objects
	addObject("enemy1", enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);//add enemy objects to engine

	// Setup event handlers
	setKeyboardHandler(myKeyboardHandler);
	engineMainLoop();// Enter main loop - this handles update and render calls
	engineShutdown();// When we quit (close window for example), clean up engine resources

	listGameObjectKeys();//list all object keys in engine
	return 0;
}

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




