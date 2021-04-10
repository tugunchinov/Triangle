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

void Configure() {
  simple_graphic::CheckCompatibility();
  simple_graphic::SetErrorHandler();
}

int ErrorHandler(Display* /* current_display */, XErrorEvent* error_event) {
  std::cerr << "Program crashed with error code " << error_event->error_code
            << std::endl;
  Clear();
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
