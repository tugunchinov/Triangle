#ifndef TRIANGLE_INCLUDE_API_HPP_
#define TRIANGLE_INCLUDE_API_HPP_

extern "C" {
#include <unistd.h>
#include <X11/Xlib.h>
}

namespace simple_graphic {

void RunXLoop();

}  // namespace simple_graphic

#endif //TRIANGLE_INCLUDE_API_HPP_
