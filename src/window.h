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


// window.h

#ifndef _ENB_WINDOW_H
#define _ENB_WINDOW_H

#include <SDL.h>

// declare a virtual/abstract window class
// base SDL library
class enb_window
{
private:
protected:
    int x_pos;
    int y_pos;
    int width;
    int height;
public:
    enb_window ();
    virtual ~enb_window ();

    // handle event (loop)
    void handle_event ();

    // window state
    void set_title (string text);
    void set_style (/* TODO */);
    void set_size (int w, int h);
    void set_position (int x, int y);
    void set_enabled (bool enabled);
    void set_visible (bool visible);

protected:
    // events
    virtual void handle_event_create () {}
    virtual void handle_event_mouse_down (int x, int y, /* TODO */) {}
    virtual void handle_event_mouse_up (int x, int y, /* TODO */) {}
    virtual void handle_event_mouse_move (/* TODO */) {}
    virtual void handle_event_mouse_double_click (/* TODO */) {}

    virtual void handle_event_key_down (/* TODO */) {}
    virtual void handle_event_key_up (/* TODO */) {}
    virtual void handle_event_key_press (/* TODO */) {}

    virtual void handle_event_resize (/* TODO */) {}
    virtual void handle_event_paint (/* TODO */) {}

    virtual void handle_event_close (/* TODO */) {}
    virtual void handle_event_destroy (/* TODO */) {}
};

#endif  // _ENB_WINDOW_H
