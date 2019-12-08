#include <SDL.h>
#include <SDL_image.h>

class menu
{
private:
    SDL_Surface *menu_screen;
    SDL_Surface *start_game;
    SDL_Surface *difficulty_level;
    SDL_Surface *quit;
    SDL_Surface *level;
    SDL_Surface *novice;
    SDL_Surface *genius;
    SDL_Surface *master;

public:
    int difficulty;
    SDL_Surface *gScreenSurface;
    SDL_Window *gWindow;
    int screen;
    menu(SDL_Window *);
    ~menu();
    void move(int, int);
    int click(int, int);
};