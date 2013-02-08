#include "Game.h"

Game::Game(void) : startTicks(0), high_score(0), final_score(0), timer(NULL), highScore(NULL), finalScore(NULL), newHighScore(NULL)
{
}

Game::~Game(void)
{
	if (timer != NULL)
		SDL_FreeSurface(timer);
	if (highScore != NULL)
		SDL_FreeSurface(highScore);
	if (finalScore != NULL)
		SDL_FreeSurface(finalScore);
	if (newHighScore != NULL)
		SDL_FreeSurface(newHighScore);
}

//Update Methods
void Game::reset()
{
	startTicks = 0;
	activate_timer();
}

void Game::set_highscore()
{
	if (final_score > high_score)
		high_score = final_score;
}

//Draw Methods
void Game::show_time()
{
	time_display.str("");
	time_display << "Time: " << get_time(); 
	timer = TTF_RenderText_Solid(textFont, time_display.str().c_str(), textColor);
	blit(timer, screen, 0, 20);
}

void Game::show_highScore(int score)
{
	final_score = score;
	
	//if high score was never defined, make this new score the high sore
	if (high_score == 0 || final_score > high_score)
	{
		SDL_Surface* extra = TTF_RenderText_Solid(textFont, "New High Score!", textColor);
		blit(extra, screen, SCREEN_WIDTH/2 - extra->w/2, 50);
	}

	newHighScore = TTF_RenderText_Solid(textFont, "Press Spacebar to try and beat your high score!", textColor);
	blit(newHighScore, screen, SCREEN_WIDTH/2 - newHighScore->w/2, 100);

	finalScore_display.str("");
	finalScore_display << "Final Score: " << final_score;
	finalScore = TTF_RenderText_Solid(textFont, finalScore_display.str().c_str(), textColor);
	blit(finalScore, screen, SCREEN_WIDTH/2 - finalScore->w/ 2, 220);

	highScore_display.str("");

	if (final_score > high_score)
		highScore_display << "Previous High Sore: " << high_score;
	else
		highScore_display << "High Score: " << high_score;

	highScore = TTF_RenderText_Solid(textFont, highScore_display.str().c_str(), textColor);
	blit(highScore, screen, SCREEN_WIDTH/2 - highScore->w/2, 260);
}