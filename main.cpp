/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
  and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#endif
#include <iostream>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include "face.hpp"
#include "menu_mode.hpp"
//Screen dimension constants
const int SCREEN_WIDTH = 544;
const int SCREEN_HEIGHT = 421;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture *loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The window renderer
SDL_Renderer *gRenderer = NULL;

bool init()
{
    //Initialization mouseClicked
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success mouseClicked
    bool success = true;

    //Nothing to load
    return success;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

SDL_Texture *loadTexture(std::string path)
{
    //The final texture
    SDL_Texture *newTexture = NULL;

    //Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}

int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!loadMedia()) //Load media
        {
            printf("Failed to load media!\n");
        }
        else
        {
            bool quit = false; //Main loop controller

            SDL_Event e; //Event handler that takes care of all events

            bool mouseClicked = false;
            int oldx = 0;
            int oldy = 0;

            int mouse_pre_x = 0;
            int mouse_pre_y = 0;

            float x_rotate = 0;
            float y_rotate = 0;

            int game_mode = 0;

            face r_cube(gRenderer);
            r_cube.render(x_rotate, y_rotate);
            //While application is running
            menu my_menu(gWindow);
            while (!quit)
            {
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //Clear screen
                    //SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
                    //SDL_RenderClear(gRenderer);
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }

                    switch (e.type)
                    {

                    case SDL_KEYDOWN:
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_f:
                            r_cube.rotate_front();
                            break;
                        case SDLK_t:
                            r_cube.rotate_top();
                            break;
                        case SDLK_b:
                            r_cube.rotate_bottom();
                            break;
                        case SDLK_y:
                            r_cube.rotate_middle_y();
                            break;
                        case SDLK_r:
                            r_cube.rotate_right();
                            break;
                        case SDLK_l:
                            r_cube.rotate_left();
                            break;
                        case SDLK_x:
                            r_cube.rotate_middle_x();
                            break;
                        case SDLK_s:
                            r_cube.shuffle(10);
                            break;
                        case SDLK_c:
                            std::cout << r_cube.is_solved() << std::endl;
                            break;
                        }
                    case SDL_KEYUP:
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_a:
                            break;
                        case SDLK_d:
                            break;
                        }

                    default:
                        break;
                    }
                    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
                    {
                        //Get mouse position
                        int x, y;
                        SDL_GetMouseState(&x, &y);

                        if (e.type == SDL_MOUSEMOTION)
                        {
                            if (game_mode == 0)
                            {
                                my_menu.move(x, y);
                            }
                            if (mouseClicked == true)
                            {
                                if (game_mode == 1)
                                {
                                    x_rotate = (float)(mouse_pre_x - x) / (float)150.0;
                                    y_rotate = (float)(mouse_pre_y - y) / (float)150.0;
                                }
                            }
                        }
                        if (e.type == SDL_MOUSEBUTTONDOWN)
                        {
                            mouseClicked = true;
                            mouse_pre_x = x;
                            mouse_pre_y = y;
                        }
                        if (e.type == SDL_MOUSEBUTTONUP)
                        {
                            mouseClicked = false;
                            if (game_mode == 1)
                            {
                                r_cube.x_rotation+=x_rotate;
                                r_cube.y_rotation+=y_rotate;
                                x_rotate = 0;
                                y_rotate = 0;
                            }
                            if (mouse_pre_x == x && mouse_pre_y == y)
                            {
                                if (game_mode == 0)
                                {
                                    int res = my_menu.click(x, y);
                                    if (res == 1)
                                    {
                                        game_mode = 1;
                                        r_cube.render(x_rotate, y_rotate);
                                    }
                                    else if (res == 2)
                                    {
                                        quit = true;
                                    }
                                }
                            }
                        }
                    }
                }
                if (game_mode == 1)
                {
                    r_cube.render(x_rotate, y_rotate);
                }
            }
        }
    }
    //Free resources and close SDL
    close();
    return 0;
}
