


void enb_main_window :: handle_event_create ()
{
    // TODO
    game->handle_event_create ();
}

void handle_event_mouse_down (int x, int y, /* TODO */)
{
    // TODO
    game->handle_event_mouse_down (...);
}

void handle_event_mouse_up (int x, int y, /* TODO */)
{
    game->handle_event_mouse_up (...);
}

void handle_event_mouse_move (/* TODO */)
{
    game->handle_event_mouse_move (...);
}

void handle_event_mouse_double_click (/* TODO */)
{
    game->handle_event_double_click (...);
}

void handle_event_key_down (/* TODO */)
{
    game->handle_event_key_down (...);
}

void handle_event_key_up (/* TODO */)
{
    game->handle_event_key_up (...);
}

void handle_event_key_press (/* TODO */)
{
    game->handle_event_key_press (...);
}

void handle_event_resize (/* TODO */)
{
    game->handle_event_resize (...);
}

void handle_event_paint (/* TODO */)
{
    game->handle_event_paint (...);
}

void handle_event_close (/* TODO */)
{
    game->handle_event_close (...);
}

void handle_event_destroy (/* TODO */)
{
    game->handle_event_destroy (...);
}


// running from here
int game_main (int argc, char ** argv)
{
    enb_main_window * main_window = NULL;
    enb_game * game = NULL;

    game = new enb_game ();
    main_window = new enb_main_window (game);

    // initialize all resource data for a game
    game->init ();

    // main loooooooooooooop (handle event)
    while (main_window :: handleEvent ())
    {
        game->process ();
    }
}

int main (int argc, char **argv)
{
    if (SDL_Init (...) < 0)
    {
        std::cerr << "can't initialize SDL library";
        return (1);
    }

    int result = game_main (argc, char ** argv);

    SDL_Quit ();

    return (result);
}
