#ifndef TRIANGLE_INCLUDE_WINDOW_HPP_
#define TRIANGLE_INCLUDE_WINDOW_HPP_

#include <cstddef>
#include <functional>
#include <span>
#include <string_view>
#include <unordered_map>

#include <api.hpp>

namespace simple_graphic {

class Window;

using Handler = std::function<void(Window& window, const XEvent&)>;
using EventMask = long;
using EventType = int;

class Window {
 public:
  explicit Window(std::size_t width = 800, std::size_t height = 600);
  ~Window();

  Window& operator=(const Window& other) = delete;

  // Replace current event mask with a new one
  void SetEventsHandlers(std::initializer_list<std::tuple<EventMask,
                                                          EventType,
                                                          Handler>> handlers = {});
  void SetName(std::string_view name);
  void SetBackgroundColor(float red, float green, float blue, float alpha);

  int GetWidth() const;
  int GetHeight() const;

  void Show();
  void RunEventLoop(const std::function<void()>& init_func = []() {});
 private:
  XSetWindowAttributes* InitWindowAttributes();

 private:
  std::size_t width_;
  std::size_t height_;

  int root_;

  Colormap colormap_;
  XSetWindowAttributes window_attributes_;

  std::unordered_map<long, Handler> handler_;

  ::Window window_;
};

}  // namespace simple_graphic

#endif  //TRIANGLE_INCLUDE_WINDOW_HPP_
