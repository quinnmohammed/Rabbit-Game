#include "Variables.h"
#include "Game.h"
#include "SDL_mixer.h"

int main(int argc, char* args[])
{
	Initialize(); 

	Game rabbit_faggit;
	Rabbit player;
	Flower flower;

	SDL_Event event;
	bool quit = false;
	
	rabbit_faggit.activate_timer();

	while(!quit)
	{
		bool time_up = rabbit_faggit.get_time() > GAME_TIME;
		if(time_up)
		{			
			while (SDL_PollEvent(&event))
			{
				switch(event.type)
				{
				case SDL_KEYDOWN:
					{
						switch(event.key.keysym.sym)
						{
							case SDLK_SPACE:
							rabbit_faggit.set_highscore();
							rabbit_faggit.reset();
							player.reset();
							player.draw_score();
							flower.respawn();
						}					
					}
					break;
				case SDL_QUIT:
					{
					quit = true;
					break;		
					}
				}
			}
		}
		
		if (!time_up)
		{
			while( SDL_PollEvent( &event ) )
			{
				player.handle_input(event);

				if( event.type == SDL_QUIT )
					quit = true;
			}

			//if there's a collision between the player and the flower - add a point, and respawn the flower
			if (check_collision(flower.get_cbox(), player.get_cbox()))
			{
				flower.respawn();
				player.add_point();
			}

			player.move();
		}


		//play fcken music
		
		if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                        Mix_PlayMusic( backgroundSong, 1 );
                        {
                       //     return 1;
                        }    
                    }

		//DRAWING SECTION - EVERYTHING MUST BE DRAWN HERE
		draw_background(background);
			
		//if game is still going draw player, flower, time and score -- otherwise just show the final score, high score, etc
		if (!time_up)
		{
			player.draw();
			flower.draw();
			rabbit_faggit.show_time();
			player.draw_score();
		}
		else
			rabbit_faggit.show_highScore(player.get_score());

		SDL_Flip(screen);
	}

	CleanUp();
	return 0;
}