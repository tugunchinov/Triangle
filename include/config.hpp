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
    GLX_STENCIL_SIZE, 8,
    //GLX_RED_SIZE, 8,
    //GLX_GREEN_SIZE, 8,
    //GLX_BLUE_SIZE, 8,
    //GLX_SAMPLE_BUFFERS, 0,
    //GLX_SAMPLES, 0,
    None
};
inline XVisualInfo* visual = glXChooseVisual(display, screen_id, glx_attribs);
inline GLXContext
    glx_context = glXCreateContext(display, visual, nullptr, GL_TRUE);

}

#endif //TRIANGLE_INCLUDE_CONFIG_HPP_
