#ifndef RABBIT_H
#define RABBIT_H

#include "Variables.h"
#include <sstream>

class Rabbit
{
private:
	SDL_Rect box;
	int score;
	SDL_Surface* image, *image_r, *image_l;
	SDL_Surface* score_image;
	std::stringstream display_score;
	int xVel, yVel;
public:
	Rabbit();
	~Rabbit();

	//Get Methods
	int get_score() { return score; }
	SDL_Rect get_cbox() { return box; }
	
	//Input Methods
	void handle_input(SDL_Event r_event);

	//Update Methods
	void move();
	void add_point();
	void reset();

	//Draw Methods
	void draw();
	void draw_score();
};

#endif