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
