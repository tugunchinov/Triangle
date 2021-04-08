#include <window.hpp>
#include <iostream>
namespace simple_graphic {

// TODO: for?
void RunXLoop() {
  while (true) {
    while (XPending(simple_graphic::Window::current_display) > 0) {
      XEvent x_event;
      XNextEvent(simple_graphic::Window::current_display, &x_event);
      std::cout << "in loop\n";
      std::cout.flush();
      XNextEvent(simple_graphic::Window::current_display, &x_event);
      switch (x_event.type) {
        case DestroyNotify:return;
      }
    }
  }
}

}  // namespace simple_graphic
