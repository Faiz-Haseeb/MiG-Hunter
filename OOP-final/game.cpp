#include "game.hpp"
#include "air.hpp"
#include<vector>
bool Game::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		
    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
    {
        printf( "Unable to open audio: %s\n", Mix_GetError());
		success=false;
    }
	
		//Create window
		gWindow = SDL_CreateWindow( "HU Mania", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Mix_Load_MUS is used to play the music , other all are used to load the sprite sheets 
	bool success = true;
	gMusic=Mix_LoadMUS("mouse_click_1.wav");
	assets = loadTexture("assets.png");
	assets_1=loadTexture("planes.png");
	assets_2=loadTexture("bullets.png");
	assets_3=loadTexture("explosion.png");
	giMusic=Mix_LoadMUS("battle_music.wav");
    gTexture = loadTexture("hu.png");
	giTexture=loadTexture("start_triggered.png");
	gikTexture=loadTexture("training_triggered.png");
	gikiTexture=loadTexture("inst.png") ;
	background = loadTexture("bg.png");
	gikikTexture=loadTexture("gameover.png");
	assets_4=loadTexture("scoreee.png");
	pause_asset=loadTexture("button.png");
	renewed=loadTexture("night sky.png");
	healt_asset=loadTexture("health (1).png");
	if(assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }

	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(assets);
	assets=NULL;
	SDL_DestroyTexture(gTexture);
	SDL_DestroyTexture(pause_asset);
	pause_asset=NULL;
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}


void Game::run( )
{
	bool quit = false;
	SDL_Event e;
	//plane add
	air air(gRenderer, assets,assets_1,assets_2,assets_3,healt_asset);
	int x = 0;
	while( !quit )
	{
		//Handle events on queue
		
		while( SDL_PollEvent( &e ) != 0 )
		{

			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}


			if(e.type == SDL_MOUSEBUTTONDOWN){
			//this is a good location to add pigeon in linked list.
				int xMouse, yMouse;
				
				SDL_GetMouseState(&xMouse,&yMouse);
				if (xMouse>870 & xMouse<957 & yMouse>555 & yMouse<575 & state==1)
				{	//this condition check whether the backk button has been pressed from instruions screen
					// and then returns it back to main screen 
					// 	For refrence state=0 means main screen state=1 means instructions page and stetae=2 means main game and state=3 means game over screen
                    cout<<"done";
					state=0;
					}
				
				else if (xMouse<253 && yMouse>270 && state==0){
					//this takes it to the main screen and creates all main creen object through air.create objects 
					SDL_RenderCopy(gRenderer, background, NULL, NULL);
					Mix_PlayMusic(giMusic,-1);
					state = 2;
					air.createObject();
				}
				else if (xMouse>350 && yMouse>350 && state==0)

					{ 	// this is to heck whethger training button is pressed from main screen
					//it takes it to the instructions page and plays the click sound loaded in mix 
						
						state=1;
						cout<<"clicked"<<endl;
						Mix_PlayMusic(gMusic,-1);
						SDL_RenderClear(gRenderer);
						
					}
				
		}
		if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
			{
				paused = !paused; //toggle whether pause is true or false
			}
		if (paused==false)
		{	
			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LEFT && state==2)
						{	//decides on signal for player plane to be moved through arrow keys 
							signal=1;
						}
			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RIGHT && state==2)
						{	
							signal=2;
						}

			if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_f && state==2)
						{	//creates bullet on said location if F is pressed 
							air.fire();
						}					
		}
		}
		if (paused==false)
		{
		if (counter%180==0 && state==2){
			// this cretaes obkjects after 180 iterations of the game loop so more enemies can be made timely
			air.createObject();
			
		}
		counter=counter+1;
		if (state==2 && air.game_end()==0){
			//This loop takes the game to the final screen if game_end conditipons are met
			state=3;
			//stops playing game music if game has ended
			if (Mix_PlayingMusic()){
				Mix_HaltMusic();
			}
			store_var=0;
			//the down block gets each digit of the score after game end by making use of modulus and floor division
			digit_1=air.get_score() / 100;
			store_var=air.get_score() % 100;
			digit_2=store_var/10;
			store_var=store_var%10;
			digit_3=store_var;
			cout<<digit_2;
			//This creates the three digits of the score with their location on the screen , the digit is passed to decide whic of the sprite needs to be used 

			s1=new Score(440,330,digit_1);
			s2=new Score(490,330,digit_2);
			s3=new Score(540,330, digit_3);
			

		}
		
		SDL_RenderClear(gRenderer);
		if (state==3){
			
			//this draws the background and score for th final screen
			SDL_RenderCopy(gRenderer, gikikTexture, NULL, NULL);
			s1->draw(gRenderer,assets_4);
			s2->draw(gRenderer,assets_4);
			s3->draw(gRenderer,assets_4);
		if(Mix_PlayingMusic()){
			Mix_HaltMusic();

		}
		}
		if (state==2 && paused==false ){
					Mix_ResumeMusic();
					//resumes music when game is continued from the pause condition
				}
		if (state==2){ 
			camera_rect.y=camera_rect.y+6;
			//this block is used for creaton of a moving background
			if (camera_rect.y>666){
					final_sig=1;
					camera_rect.y=0;
					//resets the background if it reaches the bottom of the screen
					}
			if (final_sig==1){
				//final_sig is used for knowing when to start the night background
				//ca,era rect dcides the position where to start drawing the background and tghe heoght and width of the drawing 
				SDL_RenderCopy(gRenderer, renewed, &camera_rect, NULL);
				
				
		}
		else{SDL_RenderCopy(gRenderer, background, &camera_rect, NULL);}
		}
		//if (state==3){
			//SDL_RenderCopy(gRenderer, gikikTexture, NULL, NULL);

		//}
		if (state==1)
		{SDL_RenderCopy(gRenderer, gikiTexture, NULL, NULL);}
		if (state==2){
			//draws all objects if screen in main screen
			air.drawObjects(signal);}
		signal=0;
		 //removes everything from renderer
		int z,r;
		SDL_GetMouseState(&z,&r);
		//This block createsthe red animation when the mouse hovers ont he buttons ontthe main screen 
		//rthis is done through toggling the background pictures which have are the same but have the red outline on one off the two buttons
		if (state==0){
			SDL_RenderClear(gRenderer);
		if (r>345 and z<300)
			{SDL_RenderCopy(gRenderer, giTexture, NULL, NULL);}//Draws background to renderer
		//***********************draw the objects here********************
		else if (r>345 && z>480){SDL_RenderCopy(gRenderer, gikTexture, NULL, NULL);}
		else{SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);}
		}
		//****************************************************************
    	SDL_RenderPresent(gRenderer); //displays the updated renderer
		
	    if(Mix_PlayingMusic() && state==1){
	    SDL_Delay(100);
		Mix_HaltMusic();}
		else {

			SDL_Delay(200);
		}	//causes sdl engine to delay for specified miliseconds
		}
		if (paused == true)

			{	//used to halt ,music and render paused screen if game is in the paused condition
				if (Mix_PlayingMusic())
				{Mix_PauseMusic();}
				SDL_RenderClear(gRenderer);
				SDL_RenderCopy(gRenderer, background, NULL, NULL);
				SDL_RenderCopy(gRenderer, pause_asset, NULL, &pause_moverRect);
				SDL_RenderPresent(gRenderer);
				SDL_Delay(3);
			}
	}
			
}

