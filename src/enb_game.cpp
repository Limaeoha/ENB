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


// example_main.cpp
// compile and running with shell
//      g++ enb_game.cpp -L/usr/lib -lSDL -lGL && ./a.out

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cctype>
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>

using namespace std;

// enumerate all state of mouse button
enum mouse_button
{
    mb_left,
    mb_middle,
    mb_right,

    mb_count
};

struct mouse_state
{
    bool mouse_left;
    bool mouse_middle;
    bool mouse_right;
};

enum window_style
{
	ws_fullscreen,
	ws_fixed,
	ws_resizable
};

class enb_engine;

class enb_window
{
private:
    enb_engine* ge;

private:
    unsigned int last_mouse_down[mb_count];
    int last_mouse_xpos[mb_count];
    int last_mouse_ypos[mb_count];

    mouse_button get_mouse_button (int sdl_btn);
    void handle_event_mouse_down (SDL_Event event);
    mouse_state get_mouse_state (SDL_Event event);

    char get_virtual_key (SDL_keysym keysym);

protected:
    void handle_event_mouse_click (int x, int y, mouse_button mb);
    void handle_event_mouse_double_click (int x, int y, mouse_button mb);
    void handle_event_mouse_up (int x, int y, mouse_button mb);
    void handle_event_mouse_move (int x, int y, const mouse_state& ms);

    void handle_event_key_down (char key);
    void handle_event_key_up (char key);
    void handle_event_key_press (char key);

public:
    enb_window (enb_engine* ge);
    ~enb_window ();
    bool handle_event ();

    void set_text (string text);
    void set_style (window_style ws);
    void set_size (int w, int h);
    void set_pos (int x, int y);
    void set_enabled (bool enabled);
    void set_visible (bool visible);

    void init_context (int cbs, int dbs, int sbs);
    void make_current ();
    void swap_buffer ();
};

class enb_engine
{
private:
    enb_window* window;
public:
    void handle_event_mouse_click (int x, int y, mouse_button mb);
    void handle_event_mouse_double_click (int x, int y, mouse_button mb);
    void handle_event_mouse_up (int x, int y, mouse_button mb);
    void handle_event_mouse_move (int x, int y, const mouse_state& ms);

    void handle_event_key_down (char key);
    void handle_event_key_up (char key);
    void handle_event_key_press (char key);
public:
    enb_engine ();
    ~enb_engine ();
    void init (enb_window* window);
    void loop ();
};

void enb_window :: init_context (int cbs, int dbs, int sbs)
{
    SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute (SDL_GL_RED_SIZE, 1);
    SDL_GL_SetAttribute (SDL_GL_GREEN_SIZE, 1);
    SDL_GL_SetAttribute (SDL_GL_BLUE_SIZE, 1);
    SDL_GL_SetAttribute (SDL_GL_STENCIL_SIZE, sbs);
    SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, dbs);

    int flags = SDL_OPENGL;

    SDL_Surface* screen = SDL_SetVideoMode (640, 480, cbs, flags);

    if (screen == 0)
    {
        throw std :: runtime_error ("error: SDL_SetVideoMode\n");
    }
}

void enb_window :: make_current ()
{
}

void enb_window :: swap_buffer ()
{
    SDL_GL_SwapBuffers ();
}

void enb_window :: set_text (string text)
{
    SDL_WM_SetCaption (text.c_str (), 0);
}

void enb_window :: set_style (window_style ws)
{
    // TODO
}

void enb_window :: set_size (int w, int h)
{
    // TODO
}

void enb_window :: set_pos (int x, int y)
{
    // TODO
}

void enb_window :: set_enabled (bool enabled)
{
    // TODO
}

void enb_window :: set_visible (bool visible)
{
    // TODO
}

void enb_engine :: init (enb_window* window)
{
    this->window = window;
    window->set_text ("ENB-GAME");
    window->init_context (32, 16, 0);
    window->make_current ();
}

enb_engine :: enb_engine ()
{
    cout << "enb_engine construct function" << endl;
}

enb_engine :: ~enb_engine ()
{
    cout << "enb_engine destruct function" << endl;
}

void enb_engine :: loop ()
{
    // set rendering scene
    glColor4f (1.f, 1.f, 1.f, 1.f);
        // projection
        glViewport (0, 0, 640, 480);
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity ();
        glOrtho (-320, 320, -240, 240, 0, 1);
        // modelview
        glMatrixMode (GL_MODELVIEW);
        glLoadIdentity ();

    // render a frame
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel (GL_SMOOTH);
    glBegin (GL_TRIANGLES);
        glColor3ub ((GLubyte) 255, (GLubyte) 0, (GLubyte) 0);
        glVertex3f (0.0f, 100.0f, 0.0f);

        glColor3ub ((GLubyte) 0, (GLubyte) 255, (GLubyte) 0);
        glVertex3f (-100.0f, 0.0f, 0.0f);

        glColor3ub ((GLubyte) 0, (GLubyte) 0, (GLubyte) 255);
        glVertex3f (100.0f, 0.0f, 0.0f);
    glEnd ();

    window->swap_buffer ();
    cout << "render a triangle (swap buffer)\n";
}

enb_window :: enb_window (enb_engine* ge)
{
    this->ge = ge;
    cout << "enb_window construct function" << endl;
}

enb_window :: ~enb_window ()
{
    cout << "enb_window destruct function" << endl;
}

bool enb_window :: handle_event ()
{
    SDL_Event event;
    while (SDL_PollEvent (&event))
    {
        try {
            switch (event.type)
            {
                case SDL_QUIT:
                {
                    return (false);
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                    handle_event_mouse_down (event);
                    break;
                }
                case SDL_MOUSEBUTTONUP:
                {
                    handle_event_mouse_up (event.button.x, \
                        event.button.y, get_mouse_button (event.button.button));
                    break;
                }
                case SDL_MOUSEMOTION:
                {
                    mouse_state state = get_mouse_state (event);
                    handle_event_mouse_move (event.motion.x, \
                        event.motion.y, state);
                    break;
                }
                case SDL_KEYDOWN:
                {
                    handle_event_key_down (get_virtual_key (event.key.keysym));
                    handle_event_key_press (static_cast<char> \
                        (event.key.keysym.unicode));
                    break;
                }
                case SDL_KEYUP:
                {
                    handle_event_key_up (get_virtual_key (event.key.keysym));
                    break;
                }
            }
        }
        catch (std::exception& e)
        {
            std::cerr << "can't process event: " << e.what () << endl;
        }
    }
    return (true);
}

char enb_window :: get_virtual_key (SDL_keysym keysym)
{
    return (0);
}

mouse_state enb_window :: get_mouse_state (SDL_Event event)
{
    mouse_state state;
    state.mouse_left = (event.motion.state & SDL_BUTTON_LMASK) != 0;
    state.mouse_middle = (event.motion.state & SDL_BUTTON_MMASK) != 0;
    state.mouse_right = (event.motion.state & SDL_BUTTON_RMASK) != 0;

    return (state);
}

// ==================
// enb_window :: get_mouse_button
// ==================
mouse_button enb_window :: get_mouse_button (int sdl_btn)
{
    switch (sdl_btn)
    {
        case SDL_BUTTON_LEFT: return (mb_left);
        case SDL_BUTTON_RIGHT: return (mb_right);
        case SDL_BUTTON_MIDDLE: return (mb_middle);
        default:
            throw std::runtime_error ("error: mouse button greater than number 3");
    }
}

// ==================
// enb_window :: handle_mouse_down
// which is click event or double click event
// ==================
void enb_window :: handle_event_mouse_down (SDL_Event event)
{
    unsigned int ticks = SDL_GetTicks ();
    mouse_button mb = get_mouse_button (event.button.button);
    
    if (ticks - last_mouse_down[mb] < 400 && \
        abs (last_mouse_xpos[mb] - event.button.x) < 2 && \
        abs (last_mouse_ypos[mb] - event.button.y) < 2)
    {   // double click
        handle_event_mouse_double_click (event.button.x, \
            event.button.y, mb);
    }
    else
    {   // click
        handle_event_mouse_click (event.button.x, \
            event.button.y, mb);
    }
}

void enb_engine :: handle_event_key_down (char key)
{
    cout << "key down\n";
}

void enb_engine :: handle_event_key_up (char key)
{
    cout << "key up\n";
}

void enb_engine :: handle_event_key_press (char key)
{
    cout << "key press\n";
}

void enb_engine :: handle_event_mouse_move (int x, int y, const mouse_state& ms)
{
    cout << "mouse move\n";
}

void enb_engine :: handle_event_mouse_up (int x, int y, mouse_button mb)
{
    cout << "mouse up\n";
}

void enb_engine :: handle_event_mouse_click (int x, int y, mouse_button mb)
{
    cout << "click\n";
}

void enb_engine :: handle_event_mouse_double_click (int x, int y, mouse_button mb)
{
    cout << "double click\n";
}

void enb_window :: handle_event_key_down (char key)
{
    ge->handle_event_key_down (key);
}

void enb_window :: handle_event_key_up (char key)
{
    ge->handle_event_key_up (key);
}

void enb_window :: handle_event_key_press (char key)
{
    ge->handle_event_key_press (key);
}

void enb_window :: handle_event_mouse_move (int x, int y, const mouse_state& ms)
{
    ge->handle_event_mouse_move (x, y, ms);
}

void enb_window :: handle_event_mouse_up (int x, int y, mouse_button mb)
{
    ge->handle_event_mouse_up (x, y, mb);
}

void enb_window :: handle_event_mouse_click (int x, int y, mouse_button mb)
{
    ge->handle_event_mouse_click (x, y, mb);
}

void enb_window :: handle_event_mouse_double_click (int x, int y, mouse_button mb)
{
    ge->handle_event_mouse_double_click (x, y, mb);
}

int engine_main (int argc, char** argv)
{
    enb_engine* engine = new enb_engine ();
    enb_window* window = new enb_window (engine);

    engine->init (window);
    while (window->handle_event ())
    {
        sleep (1);
        //std::cout << "TODO: game looooop" << endl;
        engine->loop ();
    }

    delete window;
    delete engine;

    return (0);
}

int main (int argc, char** argv)
{
    if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Can't initialize SDL Library: " \
                  << SDL_GetError () << std::endl;
        return (1);
    }

    SDL_EnableUNICODE (1);
    //SDL_SetVideoMode (640, 480, 32, SDL_SWSURFACE);
    int rlt = engine_main (argc, argv);
    SDL_Quit ();

    return (rlt);
}
