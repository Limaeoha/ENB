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


// game main window
class enb_main_window : public enb_window_opengl
{
private:
    // private game data
    enb_game * game;
public:
    enb_main_window (enb_game * g);
    ~enb_main_window ();

    void handle_event_create ()
    void handle_event_mouse_down (int x, int y, /* TODO */)
    void handle_event_mouse_up (int x, int y, /* TODO */)
    void handle_event_mouse_move (/* TODO */)
    void handle_event_mouse_double_click (/* TODO */)

    void handle_event_key_down (/* TODO */)
    void handle_event_key_up (/* TODO */)
    void handle_event_key_press (/* TODO */)

    void handle_event_resize (/* TODO */)
    void handle_event_paint (/* TODO */)

    void handle_event_close (/* TODO */)
    void handle_event_destroy (/* TODO */)
};
