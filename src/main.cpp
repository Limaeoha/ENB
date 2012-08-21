/*	
 *  Copyright (C) 2012
 *	"Mu Lei" known as "NalaGinrut" <NalaGinrut@gmail.com>
 *       fU9ANg <bb.newlife@gmail.com>
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */




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
int game_main (int argc, char** argv)
{
    enb_main_window* main_window = NULL;
    enb_game* game = NULL;

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

int main (int argc, char** argv)
{
    if (SDL_Init (...) < 0)
	{
	    std::cerr << "can't initialize SDL library";
	    return (1);
	}

    int result = game_main (argc, argv);

    SDL_Quit ();

    return (result);
}
