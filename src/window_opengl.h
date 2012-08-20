

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
