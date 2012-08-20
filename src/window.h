

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
