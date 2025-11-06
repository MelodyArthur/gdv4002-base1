#include "Engine.h"

// Function prototypes


int main(void) {
	const float pi = 3.14159265359f;

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//
	GameObject2D* player1Object = getObject("player1");//retrieves the player object
	if (player1Object != nullptr) 
	{
		printf("Player1 position: x=%f, y=%f\n", player1Object->position.x, player1Object->position.y);
	}
	addObject("player1",//defines the player object
		glm::vec2(1.0f, 1.0f),//initial position
		45.0f * pi / 180.0f,//initial rotation in radians
		glm::vec2(0.5f, 1.0f),//changes the size of the object
		"Resources\\Textures\\mcblock01.png",//adds a texture to the object
		TextureProperties::NearestFilterTexture());//changes the texture properties


	addObject("player2");
	GameObject2D* player2Object = getObject("player2");//retrieves the player2 object
	if (player2Object != nullptr) {
		printf("Player2 position: x=%f, y=%f\n", player2Object->position.x, player2Object->position.y);
		player2Object->textureID = loadTexture("Resources\\Textures\\bumblebee.png");//adds a texture to player2
	}
	player2Object->position = glm::vec2(-1.0f, 1.0f);//changes the position of player2
	player2Object->orientation = -45.0f * pi / 180.0f;//changes the rotation of player2
	player2Object->size = glm::vec2(0.5f, 1.0f);//changes the size of player2

		

	

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


