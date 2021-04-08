#ifndef TRIANGLE_INCLUDE_API_HPP_
#define TRIANGLE_INCLUDE_API_HPP_

extern "C" {
#include <GL/glx.h>
#include <unistd.h>
#include <X11/Xlib.h>
}

namespace simple_graphic {

inline Display* current_display = XOpenDisplay(nullptr);

void CheckCompatibility();
void CheckGLXSupport();
void CheckGLXVersion();

void RunXLoop();

}  // namespace simple_graphic

#endif //TRIANGLE_INCLUDE_API_HPP_
