#include "Rabbit.h"

Rabbit::Rabbit(void) : score(0), xVel(0), yVel(0)
{
	display_score << "Score: " << score;
	image_l = load_image("rabbit-l.bmp");
	image_r = load_image("rabbit-r.bmp");
	image = image_l;
	box.x = SCREEN_WIDTH / 2;
	box.y = SCREEN_HEIGHT / 2;
	box.h = image->h;
	box.w = image->w;
}

Rabbit::~Rabbit(void)
{
	SDL_FreeSurface(image);
	SDL_FreeSurface(score_image);
}

//Input Methods
void Rabbit::handle_input(SDL_Event r_event)
{
	//adjust the velocity and change the image direction based on the keypress
	if (r_event.type == SDL_KEYDOWN)
	{
		switch (r_event.key.keysym.sym)
		{
			case SDLK_UP: yVel -= 2; break;
            case SDLK_DOWN: yVel += 2; break;
            case SDLK_LEFT: 
				xVel -= 2; 
				if (image != image_l) 
					image = image_l; 
				break;
            case SDLK_RIGHT: 
				xVel += 2; 
				if (image != image_r)
					image = image_r; 
				break;    
        }
    }
	else if(r_event.type == SDL_KEYUP)
    {
        //Adjust the velocity
        switch(r_event.key.keysym.sym)
        {
            case SDLK_UP: yVel += 2; break;
            case SDLK_DOWN: yVel -= 2; break;
            case SDLK_LEFT: xVel +=  2; break;
            case SDLK_RIGHT: xVel -= 2; break;   
        }        
    }
}

//Update Methods
void Rabbit::move()
{
    box.x += xVel;
    
    if( ( box.x < 0 ) || ( box.x > 600 ) )
    {
        box.x -= xVel;    
    }
    
    box.y += yVel;
    
    if( ( box.y < 0 ) || ( box.y + 2 > 440 ) )
    {
        box.y -= yVel;    
    }
}

void Rabbit::add_point()
{ 
	score++; 
	display_score.str(""); 
	display_score << "Score: " << score;
}

void Rabbit::reset()
{
	score = 0;
	display_score.str("");
	display_score << "Score: " << score;
	xVel = 0;
	yVel = 0;
}

//Draw Methods
void Rabbit::draw()
{
	blit(image, screen, box.x, box.y);
}

void Rabbit::draw_score()
{
	score_image = TTF_RenderText_Solid(textFont, display_score.str().c_str(), textColor);
	blit(score_image, screen);
}