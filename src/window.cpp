#include <window.hpp>

namespace simple_graphic {

void Window::SetName(std::string_view name) {
  XStoreName(current_display, window_, name.data());
}

void Window::Show() {
  XMapWindow(current_display, window_);
  XFlush(current_display);
}

}  // namespace simple_graphic