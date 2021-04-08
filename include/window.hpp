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
 //     default_screen_(DefaultScreen(current_display)),
      window_(XCreateWindow(current_display,  /* display */
                            root_,  /* parent */
                            0,  /* x */
                            0,  /* y */
                            width_,  /* width */
                            height_,  /* height */
                            0,  /* border_width */
                            CopyFromParent,  /* depth */
                            CopyFromParent,  /* class */
                            CopyFromParent,  /* visual */
                            0,  /* valuemask */
                            nullptr  /* attributes */)) {

  }

  void SetName(std::string_view name);

  void Show();

  friend void RunXLoop();

 private:
  static Display* current_display;

  std::size_t width_;
  std::size_t height_;

  int root_;
//  int default_screen_;

  ::Window window_;
};

}  // namespace simple_graphic

#endif
