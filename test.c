#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>

int main() {
    Display *display;
    Window root, win;
    XEvent ev;

    display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Unable to open display\n");
        return 1;
    }

    root = DefaultRootWindow(display);

    // Create a window
    win = XCreateSimpleWindow(display, root, 0, 0, 200, 200, 1, 0, 0);

    // Select KeyPress events to capture key presses
    XSelectInput(display, win, KeyPressMask);

    // Map the window to the screen
    XMapWindow(display, win);
    XFlush(display);

    while (1) {
        XNextEvent(display, &ev);

        if (ev.type == KeyPress) {
            KeySym keysym = XLookupKeysym(&ev.xkey, 0);
            printf("Key pressed: %u, Keysym: %lu\n", ev.xkey.keycode, keysym);
        }
    }

    return 0;
}
