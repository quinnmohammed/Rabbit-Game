#include "Variables.h"

//screen-related consts
const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 640;
const int SCREEN_BPP = 32;

const int TILE_SIZE = 32;
const int NUM_OF_TILES_Y = 15;
const int NUM_OF_TILES_X = 20;

const int GAME_TIME = 60;

//screen-related
SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
SDL_Surface* background = SDL_LoadBMP("background.bmp");

//text-related
const SDL_Color textColor = {255, 255, 255};
TTF_Font* textFont = NULL; //is opened in the init() function

//sound-related
Mix_Music* backgroundSong = NULL;
Mix_Chunk* flowerSound = NULL;

void Initialize()
{
	SDL_Init( SDL_INIT_EVERYTHING );
	SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Rabbit Faggit 1.0 - Quinn Mohammed", NULL);
	TTF_Init();
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	
	textFont = TTF_OpenFont("Zapf.ttf", 16);
	backgroundSong = Mix_LoadMUS("Asteroids and Clouds.wav");
	flowerSound = Mix_LoadWAV("Catch Flower.wav");
}

void CleanUp()
{
	TTF_CloseFont(textFont);
	Mix_FreeMusic(backgroundSong);
	Mix_FreeChunk(flowerSound);
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
}

SDL_Surface* load_image(const char* filename)
{
	SDL_Surface* tempImage = SDL_LoadBMP(filename);
	SDL_Surface* optimizedImage = SDL_DisplayFormat(tempImage);
	SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 255, 0, 255));
	return optimizedImage;
}

void blit(SDL_Surface* image, SDL_Surface* dest, int x, int y)
{
	SDL_Rect area;
	area.x = x; area.y = y;
	SDL_BlitSurface(image, NULL, dest, &area);
}

void draw_background(SDL_Surface* bg_image)
{
	for (int i = 0, n = 0; i < NUM_OF_TILES_X; i++, n += TILE_SIZE)
	{
		for (int j = 0, m = 0; j < NUM_OF_TILES_Y; j++, m += TILE_SIZE)
		{
			blit(background, screen, n, m);
		}
	}
}

void draw_text(SDL_Surface* text)
{
	SDL_BlitSurface(text, NULL, screen, NULL);
}

bool check_collision(SDL_Rect A, SDL_Rect B)
{
	int leftA = A.x, leftB = B.x;
	int topA = A.y, topB = B.y;
	int rightA = A.x + A.w, rightB = B.x + B.w;
	int bottomA = A.y + A.h, bottomB = B.y + B.h;

	if( bottomA <= topB )
        return false;
    
    if( topA >= bottomB )
        return false;
   
    if( rightA <= leftB )
        return false;
    
    
    if( leftA >= rightB )
        return false;
    
    return true;
}
