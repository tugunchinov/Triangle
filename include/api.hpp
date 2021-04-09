#ifndef TRIANGLE_INCLUDE_API_HPP_
#define TRIANGLE_INCLUDE_API_HPP_

extern "C" {
#include <GL/glx.h>
#include <unistd.h>
#include <X11/Xlib.h>
}

namespace simple_graphic {

void CheckCompatibility();
void CheckGLXSupport();
void CheckGLXVersion();

int ErrorHandler(Display* display, XErrorEvent* error_event);
void SetErrorHandler();

void Clear();

}  // namespace simple_graphic

#endif //TRIANGLE_INCLUDE_API_HPP_
