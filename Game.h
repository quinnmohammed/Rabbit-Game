#ifndef GAME_H
#define GAME_H

#include "Variables.h"
#include "Rabbit.h"
#include "Flower.h"

class Game
{
private:
	int startTicks;
	std::stringstream time_display, highScore_display, finalScore_display;
	SDL_Surface* timer;
	int high_score, final_score;
	SDL_Surface* highScore, *finalScore, *newHighScore;

public:
	Game(void);
	~Game(void);
	
	//Get Methods
	int get_time() { return ((SDL_GetTicks() - startTicks) / 1000); }
 
	//Update Methods
	void activate_timer() { startTicks = SDL_GetTicks(); }
	void reset();
	void set_highscore();

	//Draw Methods
	void show_time();
	void show_highScore(int score);
	
	
};

#endif