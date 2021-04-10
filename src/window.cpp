#include <config.hpp>
#include <window.hpp>

namespace simple_graphic {

Window::Window(std::size_t width, std::size_t height) :
    width_(width),
    height_(height),
    root_(DefaultRootWindow(display)),
    colormap_(XCreateColormap(display, root_, visual->visual, AllocNone)),
    window_(XCreateWindow(display,  /* display */
                          root_,  /* parent */
                          0,  /* x */
                          0,  /* y */
                          width_,  /* width */
                          height_,  /* height */
                          0,  /* border_width */
                          visual->depth, /* depth */
                          InputOutput, /* class */
                          visual->visual, /* visual */
                          CWColormap, /* value_mask */
                          InitWindowAttributes() /* attributes */)) {
  XSetWMProtocols(display, window_, &atom_wm_delete_window, 1);
  // Set Exposure event
  SetEventsHandlers();
}

Window::~Window() {
  XFreeColormap(display, colormap_);
  XDestroyWindow(display, window_);
}

void Window::SetEventsHandlers(
    std::initializer_list<std::tuple<EventMask, EventType, Handler>> handlers) {
  long event_mask = 0;
  for (const auto& handler : handlers) {
    event_mask |= std::get<0>(handler);
    handler_[std::get<1>(handler)] = std::get<2>(handler);
  }
  XSelectInput(display, window_, event_mask);
}

void Window::SetName(std::string_view name) {
  XStoreName(display, window_, name.data());
}

void Window::SetBackgroundColor(float red,
                                float green,
                                float blue,
                                float alpha) {
  glClearColor(red, green, blue, alpha);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void Window::Show() {
  XMapWindow(display, window_);
  XFlush(display);
  glXMakeCurrent(display, window_, glx_context);

  glOrtho(0.f, GetWidth(), GetHeight(), 0.f, 0.f, 1.f);
}

XSetWindowAttributes* Window::InitWindowAttributes() {
  window_attributes_.colormap = colormap_;
  return &window_attributes_;
}

void Window::RunEventLoop(const std::function<void()>& init_func) {
  init_func();
  glXSwapBuffers(display, window_);

  XEvent event;
  while (true) {
    XNextEvent(display, &event);
    if (event.type == ClientMessage) {
      if (event.xclient.data.l[0] == static_cast<long>(atom_wm_delete_window)) {
        break;
      }
    }
    if (handler_.contains(event.type)) {
      handler_[event.type](*this, event);
    }
    glXSwapBuffers(display, window_);
  }
}

int Window::GetWidth() const {
  XWindowAttributes window_attributes;
  XGetWindowAttributes(display, window_, &window_attributes);
  return window_attributes.width;
}

int Window::GetHeight() const {
  XWindowAttributes window_attributes;
  XGetWindowAttributes(display, window_, &window_attributes);
  return window_attributes.height;
}

}  // namespace simple_graphic