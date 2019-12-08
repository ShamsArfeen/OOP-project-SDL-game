#include "menu_mode.hpp"

menu::menu(SDL_Window *iWindow)
{
    gWindow = iWindow;
    menu_screen = SDL_LoadBMP("menu2.bmp");
    level = SDL_LoadBMP("levelselection2.bmp");
    difficulty_level = SDL_LoadBMP("level2.bmp");
    start_game = SDL_LoadBMP("start2.bmp");
    quit = SDL_LoadBMP("quit2.bmp");
    novice = SDL_LoadBMP("levelnovice2.bmp");
    genius = SDL_LoadBMP("levelgenius2.bmp");
    master = SDL_LoadBMP("levelmaster2.bmp");
    gScreenSurface = NULL;
    gScreenSurface = SDL_GetWindowSurface(gWindow);
    SDL_BlitSurface(menu_screen, NULL, gScreenSurface, NULL);
    SDL_UpdateWindowSurface(gWindow);
    screen = 0;
    difficulty = 0;
}

menu::~menu()
{
}

void menu::move(int x, int y)
{
    if (111 < x && y > 50 && x < 400 && y < 98 && screen == 0)
    {
        SDL_BlitSurface(start_game, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
    else if (74 < x && y > 138 && x < 435 && y < 188 && screen == 0)
    {
        SDL_BlitSurface(difficulty_level, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
    else if (197 < x && y > 229 && x < 319 && y < 275 && screen == 0)
    {
        SDL_BlitSurface(quit, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
    else if (195 < x && y > 47 && x < 372 && y < 94 && screen == 1)
    {
        SDL_BlitSurface(novice, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
    else if (199 < x && y > 138 && x < 374 && y < 185 && screen == 1)
    {
        SDL_BlitSurface(genius, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
    else if (195 < x && y > 225 && x < 378 && y < 277 && screen == 1)
    {
        SDL_BlitSurface(master, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
    else if (screen == 1)
    {
        SDL_BlitSurface(level, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
    else if (screen == 0)
    {
        SDL_BlitSurface(menu_screen, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
}

int menu::click(int x, int y)
{
    if (111 < x && y > 50 && x < 400 && y < 98 && screen == 0)
    {
        return 1;
    }
    else if (74 < x && y > 138 && x < 435 && y < 188 && screen == 0)
    {
        screen = 1;
        SDL_BlitSurface(level, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
        return 0;
    }
    else if (197 < x && y > 229 && x < 319 && y < 275 && screen == 0)
    {
        return 2;
    }
    else if (195 < x && y > 47 && x < 372 && y < 94 && screen == 1)
    {
        screen = 0;
        difficulty = 0;
        SDL_BlitSurface(menu_screen, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
        return 0;
    }
    else if (199 < x && y > 138 && x < 374 && y < 185 && screen == 1)
    {
        screen = 0;
        difficulty = 1;
        SDL_BlitSurface(menu_screen, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
        return 0;
    }
    else if (195 < x && y > 225 && x < 378 && y < 277 && screen == 1)
    {
        screen = 0;
        difficulty = 2;
        SDL_BlitSurface(menu_screen, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
        return 0;
    }
    else if (screen == 0)
    {
        SDL_BlitSurface(menu_screen, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
}