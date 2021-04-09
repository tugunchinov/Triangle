#ifndef TRIANGLE_INCLUDE_WINDOW_HPP_
#define TRIANGLE_INCLUDE_WINDOW_HPP_

#include <cstddef>
#include <string_view>

#include <api.hpp>

namespace simple_graphic {

class Window {
 public:
  explicit Window(std::size_t width = 800, std::size_t height = 600);

  // Replace current event mask with @event_mask
  void SetEventMask(long event_mask);

  void SetName(std::string_view name);

  void Show();

 private:
  std::size_t width_;
  std::size_t height_;

  int root_;
 public:
  ::Window window_;
};

}  // namespace simple_graphic

#endif  //TRIANGLE_INCLUDE_WINDOW_HPP_
