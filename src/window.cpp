

// window.cpp

#include "window.h"

// ==========================
// enb_window :: handle_event
// process window event
// ==========================
enb_window :: handle_event ()
{
    SDL_Event event;

    while (SDL_PollEvent (&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                // TODO
            case SDL_MOUSEBUTTONDOWN:
                game_window->handle_event_mouse_down (event);
                // TODO
            case SDL_MOUSEBUTTONUP:
                game_window->handle_event_mouse_up (event.button.x, \
                    event.button.y, get_which_button (event.button.button));
                // TODO
            case SDL_KEYDOWN:
                // TODO
            case SDL_KEYUP:
                // TODO
        }
    }
};
