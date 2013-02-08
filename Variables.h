#ifndef VARIABLES_H
#define VARIABLES_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

//variables
extern SDL_Surface* screen;
extern SDL_Surface* background;

extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
extern const int SCREEN_BPP;

extern const int TILE_SIZE;
extern const int NUM_OF_TILES_Y;
extern const int NUM_OF_TILES_X;

extern const int GAME_TIME;

extern const SDL_Color textColor; 
extern TTF_Font* textFont;

extern Mix_Music* backgroundSong;
extern Mix_Chunk* flowerSound;

//functions
void Initialize();
void CleanUp();

SDL_Surface* load_image(const char* filename);

void blit(SDL_Surface* image, SDL_Surface* dest, int x = 0, int y = 0);

void draw_background(SDL_Surface* bg_image);
void draw_text(SDL_Surface* text);

bool check_collision(SDL_Rect A, SDL_Rect B);


#endif