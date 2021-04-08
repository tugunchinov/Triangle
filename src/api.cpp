#include <iostream>

#include <window.hpp>

namespace simple_graphic {

void CheckCompatibility() {
  CheckGLXSupport();
  CheckGLXVersion();
}

void CheckGLXSupport() {
  if (!glXQueryExtension(current_display, nullptr, nullptr)) {
    std::cerr << "GLX is not supported" << std::endl;
    std::exit(1);
  }
}

void CheckGLXVersion() {
  int major = 0;
  int minor = 0;
  glXQueryVersion(current_display, &major, &minor);
  if (major < 1 || (major == 1 && minor < 3)) {
    std::cerr << "GLX 1.3 and higher required" << std::endl;
  }
}

void RunXLoop() {
  while (true) {
    XEvent x_event;
    XNextEvent(current_display, &x_event);
    if (x_event.type == MapNotify) {
      break;
    }
  }
}

}  // namespace simple_graphic
