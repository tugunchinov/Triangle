#include <iostream>

#include <config.hpp>
#include <window.hpp>

namespace simple_graphic {

void CheckCompatibility() {
  CheckGLXSupport();
  CheckGLXVersion();
}

void CheckGLXSupport() {
  if (!glXQueryExtension(display, nullptr, nullptr)) {
    std::cerr << "GLX is not supported" << std::endl;
    std::exit(1);
  }
}

void CheckGLXVersion() {
  int major = 0;
  int minor = 0;
  glXQueryVersion(display, &major, &minor);
  if (major < 1 || (major == 1 && minor < 2)) {
    std::cerr << "GLX 1.2 and greater is required" << std::endl;
    std::exit(1);
  }
}

int ErrorHandler(Display* /*display*/, XErrorEvent* /*error_event*/) {
  // TODO
  std::cerr << "Some error occurred" << std::endl;
  std::exit(1);
}

void SetErrorHandler() {
  XSetErrorHandler(ErrorHandler);
}

void Clear() {
  glXDestroyContext(display, glx_context);
  XCloseDisplay(display);
}

}  // namespace simple_graphic
