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
	addObject("player",//defines the player object
		glm::vec2(1.0f, 1.0f),//initial position
		45.0f * pi / 180.0f,//initial rotation in radians
		glm::vec2(0.5f, 1.0f),//changes the size of the object
		"Resources\\Textures\\mcblock01.png",//adds a texture to the object
		TextureProperties::NearestFilterTexture());//changes the texture properties
	
		

	

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


