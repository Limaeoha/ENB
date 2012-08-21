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


// window_opengl.h

#ifndef _ENB_WINDOW_OPENGL
#define _ENB_WINDOW_OPENGL

#include "window.h"

// definite window class inherit form enb_window
class enb_window_opengl : public enb_window
{
    // this's a render window for openGL
private:
    // private member
protected:
    // protected member
public:
    void init_context_gl (int color_bits, int depth_bits, int stencil_bits);
    void make_context_gl ();
    void swap_buffer ();
};

#endif  //_ENB_WINDOW_OPENGL
