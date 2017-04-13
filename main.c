#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Failure during init(%s)\n",SDL_GetError());
        return -1;
    }

    SDL_Window* pWindow = NULL;
    pWindow = 
        SDL_CreateWindow
        (
            "SDL2 app",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN
        );

    int should_quit = 0;

    if( pWindow )
    {
        SDL_Event event;
        while (should_quit == 0)
        {
            int has_event = SDL_PollEvent(&event);
            if (has_event)
            {
                switch (event.type)
                {
                    case SDL_QUIT:
                        should_quit = 1;
                        break;
                    case SDL_KEYDOWN:
                        printf("keydown event\n");
                        break;
                    case SDL_KEYUP:
                        printf("keyup event\n");
                        printf
                        (
                            "key scancode is %d, key virtual key code is %d \n", 
                            event.key.keysym.scancode,
                            event.key.keysym.sym
                        );
                        break;
                    case SDL_TEXTINPUT:
                        printf("text input event\n");
                        printf("character is %s\n", event.text.text);
                        break;
                }
            }
        }
    }
    else
    {
        fprintf(stderr,"Failure while creating the window: %s\n",SDL_GetError());
    }
    SDL_Quit();
    return 0;
}
