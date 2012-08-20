

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
