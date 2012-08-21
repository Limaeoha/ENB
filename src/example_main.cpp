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
// complie:
//      g++ example_main.cpp -L/usr/lib -lSDL

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cctype>
#include <string>
#include <SDL/SDL.h>

using namespace std;

class enb_main_window
{
private:
protected:
public:
    enb_main_window ();
    ~enb_main_window ();
    bool handle_event ();
};

class enb_game_engine
{
private:
protected:
public:
    enb_game_engine ();
    ~enb_game_engine ();
    void loop ();
};

enb_game_engine :: enb_game_engine ()
{
    cout << "enb_game_engine construct function" << endl;
}

enb_game_engine :: ~enb_game_engine ()
{
    cout << "enb_game_engine destruct function" << endl;
}

void enb_game_engine :: loop ()
{
    // render a frame
    cout << "render a frame (swap buffer)\n";
}

enb_main_window :: enb_main_window ()
{
    cout << "enb_main_window construct function" << endl;
}

enb_main_window :: ~enb_main_window ()
{
    cout << "enb_main_window destruct function" << endl;
}

bool enb_main_window :: handle_event ()
{
    SDL_Event event;
    while (SDL_PollEvent (&event))
    {
        try {
            switch (event.type)
            {
                case SDL_QUIT:
                    return (false);
                case SDL_MOUSEBUTTONDOWN:
                    std::cout << "event is SDL_MOUSEBUTTONDOWN" << endl;
                    break;
                case SDL_MOUSEBUTTONUP:
                    std::cout << "event is SDL_MOUSEBUTTONUP" << endl;
                    break;
                case SDL_MOUSEMOTION:
                    std::cout << "event is SDL_MOUSEMOTION" << endl;
                     break;
                case SDL_KEYDOWN:
                    std::cout << "event is SDL_KEYDOWN" << endl;
                    break;
                case SDL_KEYUP:
                    std::cout << "event is SDL_KEYUP" << endl;
                    break;
            }
        }
        catch (std::exception& e)
        {
            std::cerr << "can't process event: " << e.what () << endl;
        }
    }
    return (true);
}

int game_main (int argc, char** argv)
{
    enb_main_window* main_window = new enb_main_window ();
    enb_game_engine* engine = new enb_game_engine ();

    while (main_window->handle_event ())
    {
        sleep (1);
        //std::cout << "TODO: game looooop" << endl;
        engine->loop ();
    }

    delete main_window;
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
    SDL_SetVideoMode (640, 480, 32, SDL_SWSURFACE);
    int rlt = game_main (argc, argv);
    SDL_Quit ();

    return (rlt);
}
