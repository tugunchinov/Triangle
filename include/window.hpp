#ifndef TRIANGLE_WINDOW_HPP
#define TRIANGLE_WINDOW_HPP

#include <cstddef>
#include <string_view>

#include <api.hpp>

namespace simple_graphic {

class Window {
 public:
  explicit Window(std::size_t width = 800, std::size_t height = 600) :
      width_(width),
      height_(height),
      root_(DefaultRootWindow(current_display)),
      screen_(DefaultScreen(current_display)),
      window_(XCreateSimpleWindow(current_display,  /* display */
                                  root_,  /* parent */
                                  0,  /* x */
                                  0,  /* y */
                                  width_,  /* width */
                                  height_,  /* height */
                                  0,  /* border_width */
                                  BlackPixel(current_display,
                                             screen_) /* border */,
                                  BlackPixel(current_display,
                                             screen_) /* background */)) {

  }

  void SetName(std::string_view name);

  void Show();

  friend void RunXLoop();

 private:
  std::size_t width_;
  std::size_t height_;

  int root_;
  int screen_;

  ::Window window_;
};

}  // namespace simple_graphic

#endif
