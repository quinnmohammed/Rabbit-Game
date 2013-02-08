#include "Flower.h"

Flower::Flower()
{
	image = load_image("flower.bmp");
	srand((unsigned)time(0));
	box.x = (rand()%600)+1;
	box.y = (rand()%440)+1;
	box.h = image->h;
	box.w = image->w;
}

Flower::~Flower()
{
	SDL_FreeSurface(image);
}

//Update Methods
void Flower::respawn()
{
	Mix_PlayChannel(-1, flowerSound, 0);
	box.x = (rand()%600)+1;
	box.y = (rand()%440)+1;
}

//Draw Methods
void Flower::draw()
{
	blit(image, screen, box.x, box.y);
}