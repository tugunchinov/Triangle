#include <config.hpp>
#include <window.hpp>

namespace simple_graphic {

Window::Window(std::size_t width, std::size_t height) :
    width_(width),
    height_(height),
    root_(DefaultRootWindow(display)) {

  window_ = XCreateWindow(display,  /* display */
                          root_,  /* parent */
                          0,  /* x */
                          0,  /* y */
                          width_,  /* width */
                          height_,  /* height */
                          0,  /* border_width */
                          visual->depth, /* depth */
                          InputOutput, /* class */
                          visual->visual, /* visual */
                          0, /* value_mask */
                          nullptr /* attributes */);
}

void Window::SetEventMask(long event_mask) {
  XSelectInput(display, window_, event_mask);
}

void Window::SetName(std::string_view name) {
  XStoreName(display, window_, name.data());
}

void Window::Show() {
  glXMakeCurrent(display, window_, glx_context);
  XMapWindow(display, window_);
  XFlush(display);
}

}  // namespace simple_graphic