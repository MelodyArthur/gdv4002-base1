#include "Engine.h"
#include "Keys.h" // setup in chapter 6
#include "Player.h"
#include "Enemy.h"

// Function prototypes
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods); // setup in chapter 6


// Globals
glm::vec2 gravity = glm::vec2(0.0f, -1.0f);

// Bit flags to track which keys are currently pressed - setup in chapter 6
std::bitset<5> keys{ 0x0 };


int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 512, 512, 10.0f);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	// Setup game objects
	//Player Object using name and pointer to an existing object
	GLuint playerTexture = loadTexture("Resources\\Textures\\player1_ship.png");
	Player* mainPlayer = new Player(glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), playerTexture, 2.5f);
	addObject("player", mainPlayer);

	//Enemy Objects using name and pointer to an existing object
	// 1. Load enemy texture 
	GLuint enemyTexture = loadTexture("Resources\\Textures\\alien01.png");
	// 2. Create enemy objects
	Enemy* enemy1 = new Enemy(glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(45.0f));
	Enemy* enemy2 = new Enemy(glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(90.0f));
	Enemy* enemy3 = new Enemy(glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), enemyTexture, 0.0f, glm::radians(60.0f));
	// Add enemy objects to the engine
	addObject("enemy1", enemy1);
	addObject("enemy2", enemy2);
	addObject("enemy3", enemy3);



	// Setup event handlers
	setKeyboardHandler(myKeyboardHandler);


	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//Check if the key was just pressed
	if (action == GLFW_PRESS) 
	{
		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window(and quit)
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_W:
			//printf("w pressed\n");//notifies that the function is working
			keys[Key::W] = true;//moves player when key is pressed
			break;
		case GLFW_KEY_S:
			keys[Key::S] = true;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = true;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = true;
			break;
		}
	}
	//Check if the key was just released
	if (action == GLFW_RELEASE)
	{
		switch (key)
		{
		case GLFW_KEY_W:
			keys[Key::W] = false;//stops movement when key is released
			break;
		case GLFW_KEY_S:
			keys[Key::S] = false;
			break;
		case GLFW_KEY_A:
			keys[Key::A] = false;
			break;
		case GLFW_KEY_D:
			keys[Key::D] = false;
			break;

		}
	}
}




