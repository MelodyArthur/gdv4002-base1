#include "Engine.h"
#include "Keys.h"
#include <bitset>

// Function prototypes
float enemyPhase[3] = { 3.0f, 1.0f, 5.0f };//if you change these they'll change the starting position of the enemies
float enemyPhaseVelocity[3] = { glm::radians(90.0f),
	glm::radians(180.0f),
	glm::radians(240.0f)};//if you change these it'll change the speed of the enemies
void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);


int main(void) {
	const float pi = 3.14159265359f;

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}
	
	//game objects for pre excersize 5
	// Setup game scene objects here
	//
	//GameObject2D* player1Object = getObject("player1");//retrieves the player object
	//if (player1Object != nullptr) 
	//{
	//	printf("Player1 position: x=%f, y=%f\n", player1Object->position.x, player1Object->position.y);
	//}
	//addObject("player1",//defines the player object
	//	glm::vec2(1.0f, 1.0f),//initial position
	//	45.0f * pi / 180.0f,//initial rotation in radians
	//	glm::vec2(0.5f, 1.0f),//changes the size of the object
	//	"Resources\\Textures\\mcblock01.png",//adds a texture to the object
	//	TextureProperties::NearestFilterTexture());//changes the texture properties


	//addObject("player2");
	//GameObject2D* player2Object = getObject("player2");//retrieves the player2 object
	//if (player2Object != nullptr) {
	//	printf("Player2 position: x=%f, y=%f\n", player2Object->position.x, player2Object->position.y);
	//	player2Object->textureID = loadTexture("Resources\\Textures\\bumblebee.png");//adds a texture to player2
	//}
	//player2Object->position = glm::vec2(-1.0f, 1.0f);//changes the position of player2
	//player2Object->orientation = -45.0f * pi / 180.0f;//changes the rotation of player2
	//player2Object->size = glm::vec2(0.5f, 1.0f);//changes the size of player2

	//game objects from 5 forwards
	addObject("player", glm::vec2(-1.5f, 0.0f), 0.0f, glm::vec2(0.5f, 0.5f), "Resources\\Textures\\player1_ship.png");
	addObject("enemy", glm::vec2(0.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");
	addObject("enemy", glm::vec2(1.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");
	addObject("enemy", glm::vec2(2.0f, 0.0f), 0.0f, glm::vec2(0.75f, 0.75f), "Resources\\Textures\\alien01.png");

	
	setUpdateFunction(myUpdate);
	setKeyboardHandler(myKeyboardHandler);
	
	listGameObjectKeys();//lists all game objects in the scene
	listObjectCounts();//lists the number of game objects in the scene
	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}
void myUpdate(GLFWwindow* window, double tDelta) {

	GameObjectCollection enemies = getObjectCollection("enemy");
	for (int i = 0; i < enemies.objectCount; i++) {

		enemies.objectArray[i]->position.y = sinf(enemyPhase[i]); // assume phase stored in radians so no conversion needed

		enemyPhase[i] += enemyPhaseVelocity[i] * tDelta;
	}
}
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Check if the key was just pressed
	if (action == GLFW_PRESS) {

		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window(and quit)
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_W:
			printf("w pressed\n");
			break;
		}


	}
}



//update function for pre excercise 5
//void myUpdate(GLFWwindow* window, double tDelta)
//{
//	float player1RotationSpeed = glm::radians(90.0f);
//	GameObject2D* player1 = getObject("player1");
//	player1->orientation += player1RotationSpeed * tDelta;//tdelta ensures it runs at the same speed no matter what the frame rate is
//}



