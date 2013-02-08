#ifndef FLOWER_H
#define FLOWER_H

#include "Variables.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class Flower
{
private:
	SDL_Rect box;
	SDL_Surface* image;
public:
	Flower(void);
	~Flower(void);

	//Get Methods
	SDL_Rect get_cbox() { return box; }

	//Update Methods
	void respawn();

	//Draw Methods
	void draw();
};

#endif