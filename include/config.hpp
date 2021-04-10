#ifndef TRIANGLE_INCLUDE_CONFIG_HPP_
#define TRIANGLE_INCLUDE_CONFIG_HPP_

extern "C" {
#include <GL/glx.h>
#include <X11/Xlib.h>
}

namespace simple_graphic {

inline Display* display = XOpenDisplay(nullptr);
inline int screen_id = DefaultScreen(display);

inline GLint glx_attribs[] = {
    GLX_RGBA,
    GLX_DOUBLEBUFFER,
    GLX_DEPTH_SIZE, 24,
    None
};
inline XVisualInfo* visual = glXChooseVisual(display, screen_id, glx_attribs);
inline GLXContext
    glx_context = glXCreateContext(display, visual, nullptr, GL_TRUE);

// Handle a window closing
inline Atom
    atom_wm_delete_window = XInternAtom(display, "WM_DELETE_WINDOW", False);
}  // namespace simple_graphic

#endif //TRIANGLE_INCLUDE_CONFIG_HPP_
