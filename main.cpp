#include <iostream>

#include <window.hpp>

namespace simple_graphic {

// TODO: well-implemented
int XErrorHandler(Display* /* display */, XErrorEvent* error_event) {
  std::cerr << "X server failed with error code " << error_event->error_code
            << std::endl;
  // TODO: exit().
  return 0;
}

}  // namespace simple_graphic

int main() {
  XSetErrorHandler(simple_graphic::XErrorHandler);

  simple_graphic::Window window;

  window.SetName("Hello, X server!");
  window.Show();

  simple_graphic::RunXLoop();

  return 0;
}
